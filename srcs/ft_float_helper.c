/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:50:38 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/27 11:50:39 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_strduprev(char *s1)
{
	char	*dup;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	dup = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	len--;
	while (len >= 0)
	{
		dup[i] = s1[len];
		len--;
		i++;
	}
	dup[i] = '\0';
	free(s1);
	return (dup);
}

static void	one_two_five_exception(t_parameter *p, t_float *f, long double n)
{
	if (n - (double)f->trunc == 0.125000 && p->precision == 2)
		f->decimal--;
	else if (n - (double)f->trunc == 0.012500 && p->precision == 3)
		f->decimal--;
	else if (n - (double)f->trunc == 0.001250 && p->precision == 4)
		f->decimal--;
	else if (n - (double)f->trunc == 0.000125 && p->precision == 5)
		f->decimal--;
}

static unsigned long long	set_amount(t_parameter *p, t_float *f)
{
	int	temp;

	temp = p->precision;
	f->amount = 10;
	while (--temp > 0)
		f->amount *= 10;
	return (f->amount);
}

char	*float_maker(t_parameter *p, t_float *f, char *nbr)
{
	char	*s1;
	char	*s2;
	char	*tmp;
	char	*tmp2;
	char	*add_dot;

	tmp = NULL;
	tmp2 = NULL;
	f->zero_to_add = ft_nbrlen(f->amount, 10) - 1 - ft_nbrlen(f->decimal, 10);
	s1 = ft_unsigned_long_itoa(f->trunc);
	if (p->precision == 0 && p->dot && !p->sharp)
		return (s1);
	s2 = ft_unsigned_long_itoa(f->decimal);
	add_dot = ft_strjoin(s1, ".");
	if (f->zero_to_add && f->decimal != 0)
	{
		tmp = malloc(sizeof(char) * (f->zero_to_add));
		tmp = ft_strncpy(tmp, "000000000000000000000000000000", f->zero_to_add);
		tmp2 = ft_strjoin(tmp, s2);
		nbr = ft_strjoin(add_dot, tmp2);
		free(tmp);
		free(tmp2);
	}
	else
		nbr = ft_strjoin(add_dot, s2);
	free(s1);
	free(s2);
	free(add_dot);
	return (nbr);
}

void	split_float(t_parameter *p, t_float *f, long double n)
{
	long double			decimal_helper;
	unsigned long long	next_decimal;
	char				*reverse;
	int					last_digit;

	f->sign = 1;
	if (n < 0)
		f->sign = -1;
	n *= f->sign;
	f->amount = set_amount(p, f);
	f->trunc = (unsigned long long)n;
	if (n >= 1)
	{
		decimal_helper = n - (f->trunc - 1);
		f->decimal = decimal_helper * f->amount;
		next_decimal = decimal_helper * (f->amount * 10);
		reverse = ft_strduprev(ft_itoa(next_decimal));
		last_digit = ft_atoi(reverse) / (f->amount * 10);
		if (last_digit >= 5)
			f->decimal++;
		one_two_five_exception(p, f, n);
		free(reverse);
		f->decimal = f->decimal - f->amount;
		if (f->decimal == f->amount)
		{
			f->trunc++;
			f->decimal = 0;
		}
		if (!p->precision && p->dot)
		{
			if (f->decimal >= 5 && f->trunc % 2 > 0)
				f->trunc++;
		}
		return ;
	}
	else if (n > 0)
	{
		f->decimal = n * f->amount;
		decimal_helper = n - (f->trunc);
		next_decimal = n * (f->amount * 10);
		reverse = ft_strduprev(ft_itoa(next_decimal));
		last_digit = ft_atoi(reverse) / (f->amount / 10);
		if (((last_digit >= 5 || reverse[0] == '9') && reverse[0] != '0') && \
		(ft_nbrlen(last_digit, 10) != ft_nbrlen(f->amount, 10)))
			f->decimal++;
		else if (reverse[0] == '5' && last_digit == 0)
			f->decimal++;
		free(reverse);
		if (f->decimal == f->amount)
		{
			f->trunc++;
			f->decimal = 0;
		}
		if (!p->precision && p->dot)
		{
			if (f->decimal >= 5 && f->trunc % 2 > 0)
				f->trunc++;
		}
		return ;
	}
	else
	{
		f->decimal = 0;
		f->trunc = 0;
		return ;
	}
}
