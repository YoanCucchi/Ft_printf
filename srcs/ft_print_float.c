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

static int	is_negative(long double nbr)
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

static int	ft_minus_flag(t_parameter *p, t_float *f)
{
	while ((p->width-- - ft_nbrlen(f->trunc, 10) - 1 - p->precision) > 0)
	{
		if (!p->zero)
			p->return_value += ft_print_char(' ');
		else
			p->return_value += ft_print_char('0');
	}
	return (0);
}

static int	ft_len_zero_handling_float(t_parameter *p, t_float *f)
{
	int	total;

	total = 0;
	// parameter_print(p);
	// printf("is negative, %d\n", is_negative(n));
	// printf("nbrlen = %d\n", ft_nbrlen(f->trunc, 10));
	if (f->is_negative)
		total = p->precision + ft_nbrlen(f->trunc, 10) + 1;
	else
		total = p->precision + p->plus + p->space + ft_nbrlen(f->trunc, 10) + 1;
	while (p->width-- > total)
	{
		if (!p->zero)
			p->return_value += ft_print_char(' ');
		else
			p->return_value += ft_print_char('0');
	}
	if (!p->minus)
	{
		while ((p->width-- - ft_nbrlen(f->trunc, 10) - 1 - p->precision) > 0)
		{
			if (!p->zero)
				p->return_value += ft_print_char(' ');
			else
				p->return_value += ft_print_char('0');
		}
		return (0);
	}
	return (0);
}

static int	handling_sign(t_parameter *p, t_float *f)
{
	if (p->space && (!f->is_negative))
		p->return_value += ft_print_char(' ');
	if (f->is_negative && p->zero)
		p->return_value += ft_print_char('-');
	else if (p->plus && p->zero)
		p->return_value += ft_print_char('+');
	return (0);
}

static void	setting_float(t_parameter *p, t_float *f, long double n)
{
	f->is_negative = is_negative(n); // if 1 = -
	if (f->is_negative && (p->precision < 6 || !p->precision))
		p->width--;
	if (!p->precision && !p->dot)
		p->precision = 6;
	if (!p->precision && p->dot)
		p->width++;
}

int	ft_print_float(t_parameter *p, va_list ap)
{
	double	n;
	char	*nbr;
	t_float	*f;

	f = NULL;
	nbr = NULL;
	f = memalloc_float(f);
	n = va_arg(ap, double);
	setting_float(p, f, n);
	split_float(p, f, n);
	nbr = float_maker(p, f, nbr);
	handling_sign(p, f);
	if (!p->minus)
		ft_len_zero_handling_float(p, f);
	if (f->is_negative && !p->zero)
		p->return_value += ft_print_char('-');
	else if (p->plus && !p->zero)
		p->return_value += ft_print_char('+');
	p->return_value += ft_putnstr(nbr, (p->precision + \
	ft_nbrlen(f->trunc, 10) + 1));
	if (!f->decimal)
		while (p->precision-- > 1)
			p->return_value += ft_print_char('0');
	if (p->minus)
		ft_minus_flag(p, f);
	free(nbr);
	free(f);
	return (0);
}

int	ft_print_l_float(t_parameter *p, va_list ap)
{
	long double	n;
	char		*nbr;
	t_float		*f;

	f = NULL;
	nbr = NULL;
	f = memalloc_float(f);
	n = va_arg(ap, long double);
	setting_float(p, f, n);
	split_float(p, f, n);
	nbr = float_maker(p, f, nbr);
	handling_sign(p, f);
	if (!p->minus)
		ft_len_zero_handling_float(p, f);
	if (f->is_negative && !p->zero)
		p->return_value += ft_print_char('-');
	else if (p->plus && !p->zero)
		p->return_value += ft_print_char('+');
	p->return_value += ft_putnstr(nbr, (p->precision + \
	ft_nbrlen(f->trunc, 10) + 1));
	if (!f->decimal)
		while (p->precision-- > 1)
			p->return_value += ft_print_char('0');
	if (p->minus)
		ft_minus_flag(p, f);
	free(nbr);
	free(f);
	return (0);
}	
