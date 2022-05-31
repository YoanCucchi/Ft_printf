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

static unsigned long long	set_amount(t_parameter *p, t_float *f)
{
	int					temp;

	temp = p->precision;
	f->amount = 10;
	while (--temp > 0)
		f->amount *= 10;
	return (f->amount);
}

char	*f_join(t_parameter *p, t_float *f, char *nbr)
{
	char	*s1;
	char	*s2;

	s1 = ft_unsigned_long_itoa(f->trunc);
	s2 = ft_unsigned_long_itoa(f->decimal);
	if (p->precision == 0 && p->dot && !p->sharp)
		return (s1);
	s1[ft_strlen(s1)] = '.';
	nbr = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (nbr);
}

void	split_float(t_parameter *p, t_float *f, long double n)
{
	unsigned long long	test;
	long double			one_point;
	char				*reverse;
	int					last_digit;

	if (f->sign)
		n *= -1;
	f->amount = set_amount(p, f);
	printf("f->amount = %llu\n", f->amount);
	f->trunc = (unsigned long long)n;
	printf("f->trunc = %llu\n", f->trunc);
	one_point = n - (f->trunc - 1);
	printf("one point = %LF\n", one_point);
	f->decimal = one_point * f->amount;
	printf("f->decimal = %llu\n", f->decimal);
	test = one_point * (f->amount * 10);
	reverse = ft_strduprev(ft_itoa(test));
	last_digit = ft_atoi(reverse) / f->amount;
	if (last_digit >= 5)
		f->decimal++;
	free(reverse);
	if (!p->precision && p->dot)
	{
		if (f->decimal >= 5 && (f->trunc == 1 || f->trunc == 3 || f->trunc == 5 \
	|| f->trunc == 7 || f->trunc == 9))
			f->trunc++;
	}
}
