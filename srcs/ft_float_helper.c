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
	if (dup == NULL)
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
	int					temp;

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
	char	*test;
	int		zero_to_add;

	tmp = NULL;
	tmp2 = NULL;
	zero_to_add = 0;
	// printf("f->decimal = %llu\n", f->decimal);
	// printf("f->trunc = %llu\n", f->trunc);
	// printf("f->amount = %llu\n", f->amount);
	zero_to_add = ft_nbrlen(f->amount, 10) - 1 - ft_nbrlen(f->decimal, 10);
	// printf("zero to add = %d\n", zero_to_add);
	// tmp = malloc(sizeof(char) * (zero_to_add));
	s1 = ft_unsigned_long_itoa(f->trunc);
	s2 = ft_unsigned_long_itoa(f->decimal);
	// printf("s1 = %s\n", s1);
	// printf("s2 = %s\n", s2);
	if (p->precision == 0 && p->dot && !p->sharp) // need to free stuff here
		return (s1);
	// test = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	test = ft_strjoin(s1, ".");
	// printf("test = %s\n", test);
	// s1[ft_strlen(s1)] = '.';
	// printf("s1 = %s\n", s1);
	// printf("n = %Lf", n);
	if (zero_to_add && f->decimal != 0)
	{
		tmp = malloc(sizeof(char) * (zero_to_add));
		tmp = ft_strncpy(tmp, "000000000000000000000000000000000", zero_to_add);
		// tmp[zero_to_add + 1] = '\0';
		// printf("tmp = %s\n", tmp);
		tmp2 = ft_strjoin(tmp, s2);
		// printf("tmp2 = %s\n", tmp2);
		nbr = ft_strjoin(test, tmp2);
		// printf("nbr = %s\n", nbr);
		free(tmp);
		free(tmp2);
	}
	else
		nbr = ft_strjoin(test, s2);
	// printf("nbr = %s/n", nbr);
	free(s1);
	free(s2);
	free(test);
	return (nbr);
}

void	split_float(t_parameter *p, t_float *f, long double n)
{
	long double			decimal_helper;
	unsigned long long	next_decimal;
	char				*reverse;
	int					last_digit;
	// long double			test;
	int	i;

	i = 0;
	f->sign = 1;
	if (n < 0)
		f->sign = -1;
	n *= f->sign;
	f->amount = set_amount(p, f);
	f->trunc = (unsigned long long)n;
	// printf("n = %.20Lf\n", n);
	// test = (long double)n - (unsigned long long)n;
	// while (i++ < p->precision)
	// 	test = test * 10;
	// printf("test = %Lf\n", test);
	if (n >= 1)
	{
		// printf("p->precision = %d\n", p->precision);
		// printf("f->amount = %llu\n", f->amount);
		decimal_helper = n - (f->trunc - 1);
		// printf("decimal helper = %Lf\n", decimal_helper);
		f->decimal = decimal_helper * f->amount;
		// printf("f->decimal = %llu\n", f->decimal);
		next_decimal = decimal_helper * (f->amount * 10);
		// printf("next decimal = %llu\n", next_decimal);
		reverse = ft_strduprev(ft_itoa(next_decimal));
		// printf("reverse = %s\n", reverse);
		last_digit = ft_atoi(reverse) / (f->amount * 10);
		// printf("last digit = %d\n", last_digit);
		if (last_digit >= 5)
			f->decimal++;
		one_two_five_exception(p, f, n);
		free(reverse);
		// printf("f->decimal after increase  = %llu\n", f->decimal);
		f->decimal = f->decimal - f->amount;
		// printf("f->decimal before if = amount  = %llu\n", f->decimal);
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
		// printf("f->decimal before return = %llu\n", f->decimal);
		// printf("f->trunc before return = %llu\n", f->trunc);
		return ;
	}
	else if (n > 0)
	{
		// printf("f->amount = %llu\n", f->amount);
		f->decimal = n * f->amount;
		// printf("f->decimal = %llu\n", f->decimal);
		decimal_helper = n - (f->trunc);
		// printf("decimal helper = %Lf\n", decimal_helper);
		next_decimal = n * (f->amount * 10);
		// printf("next decimal = %llu\n", next_decimal);
		reverse = ft_strduprev(ft_itoa(next_decimal));
		// printf("reverse = %s\n", reverse);
		last_digit = ft_atoi(reverse) / (f->amount / 10);
		// printf("last digit = %d\n", last_digit);
		// printf("rev 0 = %c\n", reverse[0]);
		// printf(" nbrlen last digit = %d\n", ft_nbrlen(next_decimal, 10));
		// printf(" nbrlen amount = %d\n", ft_nbrlen(f->amount, 10));
		if (((last_digit >= 5 || reverse[0] == '9') && reverse[0] != '0') && (ft_nbrlen(last_digit, 10) != ft_nbrlen(f->amount, 10)))
			f->decimal++;
		else if (reverse[0] == '5' && last_digit == 0)
			f->decimal++;
		free(reverse);
		// printf("f->decimal before if = amount  = %llu\n", f->decimal);
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
		// printf("f->decimal before return = %llu\n", f->decimal);
		// printf("f->trunc before return = %llu\n", f->trunc);
		return ;
	}
	else
	{
		f->decimal = 0;
		f->trunc = 0;
		return ;
	}
}
