/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:33:48 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/25 13:33:49 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_len_zero_handling_float(t_parameter *p, t_float *f, double n)
{
	if (p->minus && !p->minus_check)
	{
		p->minus_check = 1;
		return (0);
	}
	while (p->width-- > p->plus + p->precision + ft_nbrlen(f->trunc, 10) + 1)
	{
		if (!p->zero)
			p->return_value += ft_print_char(' ');
		else
			p->return_value += ft_print_char('0');
	}
	if (!p->minus && !p->minus_check)
	{
		while ((p->width-- - ft_nbrlen(f->trunc, 10) - 1 - p->precision) > 0 && n)
		{
			if (!p->zero)
				p->return_value += ft_print_char(' ');
			else
				p->return_value += ft_print_char('0');
		}
		return (0);
	}
	if (p->minus && p->minus_check)
	{
		while ((p->width-- - ft_nbrlen(f->trunc, 10) - 1 - p->precision) > 0 && n)
		{
			if (!p->zero)
				p->return_value += ft_print_char(' ');
			else
				p->return_value += ft_print_char('0');
		}
	}
	return (0);
}

static int	is_negative(double nbr)
{
	unsigned long long	*ull;
	int					sign;

	if (nbr > 0)
		return (0);
	if (nbr < 0)
		return (1);
	ull = (unsigned long long *)&nbr;
	sign = (int)(*ull >> 63);
	if (sign == 0)
		return (0);
	return (1);
}

int	ft_print_float(t_parameter *p, va_list *ap)
{
	double	n;
	char	*nbr;
	t_float	*f;
	int		test;

// need to fix + with - number
// need to impletet space flag
// need to create length flag floats
// need to handle 0 flag
// protect malloc
// need to fix when width > precision
	f = NULL;
	f = memalloc_float(f);
	test = 0;
	nbr = NULL;
	n = va_arg(*ap, double);
	if (n <= 0 && is_negative(n))
		f->sign = 1;
	if (!p->precision && !p->dot)
		p->precision = 6;
	split_float(p, f, n);
	nbr = f_join(p, f, nbr);
	ft_len_zero_handling_float(p, f, n);
	if (f->sign)
		p->return_value += ft_print_char('-');
	else if (p->plus)
		p->return_value += ft_print_char('+');
	p->return_value += ft_putnstr(nbr, (p->precision + \
	ft_nbrlen(f->trunc, 10) + 1));
	if (f->trunc == 0 && f->decimal == 0)
	{
		test = ft_nbrlen(f->amount, 10) - 2;
		while (test--)
			p->return_value += ft_print_char('0');
	}
	ft_len_zero_handling_float(p, f, n);
	free(nbr);
	free(f);
	return (0);
}
