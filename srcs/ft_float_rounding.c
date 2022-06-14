/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_rounding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:01:21 by ycucchi           #+#    #+#             */
/*   Updated: 2022/06/09 12:01:23 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strduprev(char *s1)
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

void	one_two_five_exception(t_parameter *p, t_float *f, long double n)
{
	if (n - (double)f->trunc == 0.250000 && p->precision == 1)
		f->decimal--;
	else if (p->precision == 2 && \
	(n - (double)f->trunc == 0.225000 || n - (double)f->trunc == 0.125000))
		f->decimal--;
	else if (n - (double)f->trunc == 0.225000 && p->precision == 3)
		f->decimal--;
	else if (n - (double)f->trunc == 0.225000 && p->precision == 4)
		f->decimal--;
	else if (n - (double)f->trunc == 0.225000 && p->precision == 5)
		f->decimal--;
}

void	rounding_big(long double n, t_parameter *p, t_float *f)
{
	long double			decimal_helper;
	unsigned long long	next_decimal;
	char				*reverse;

	reverse = NULL;
	decimal_helper = n - (f->trunc - 1);
	f->decimal = decimal_helper * f->amount;
	next_decimal = decimal_helper * (f->amount * 10);
	reverse = ft_strduprev(ft_itoa(next_decimal));
	if (reverse[0] >= '5')
		f->decimal++;
	one_two_five_exception(p, f, n);
	f->decimal = f->decimal - f->amount;
	if (f->decimal == f->amount)
	{
		f->trunc++;
		f->decimal = 0;
	}
	if (!p->precision && p->dot && f->decimal >= 5 && f->trunc % 2 > 0)
		f->trunc++;
	free(reverse);
}

void	rounding_small(long double n, t_parameter *p, t_float *f)
{
	unsigned long long	next_decimal;
	char				*reverse;

	f->decimal = n * f->amount;
	next_decimal = n * (f->amount * 10);
	reverse = ft_strduprev(ft_itoa(next_decimal));
	if (reverse[0] >= '5')
		f->decimal++;
	one_two_five_exception(p, f, n);
	if (f->decimal == f->amount)
	{
		f->trunc++;
		f->decimal = 0;
	}
	if (!p->precision && p->dot && f->decimal >= 5 && f->trunc % 2 > 0)
		f->trunc++;
	free(reverse);
}
