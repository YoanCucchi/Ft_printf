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

static int	ft_len_zero_handling_float(t_parameter *p, t_float *f, double n)
{
	int total;

	total = 0;
	if (p->minus && !p->minus_check)
	{
		p->minus_check = 1;
		return (0);
	}
	// parameter_print(p);
	// printf("is negative, %d\n", is_negative(n));
	// printf("nbrlen = %d\n", ft_nbrlen(f->trunc, 10));
	if (is_negative(n))
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

int	ft_print_float(t_parameter *p, va_list *ap)
{
	double	n;
	char	*nbr;
	t_float	*f;

	f = NULL;
	f = memalloc_float(f);
	nbr = NULL;
	n = va_arg(*ap, double);
	if (is_negative(n) && (p->precision < 6 || !p->precision))
		p->width--;
	if (!p->precision && !p->dot)
		p->precision = 6;
	if (!p->precision && p->dot)
		p->width++;
	split_float(p, f, n);
	nbr = f_join(p, f, nbr);
	if (p->space && (!is_negative(n)))
		p->return_value += ft_print_char(' ');
	if (is_negative(n) && p->zero)
		p->return_value += ft_print_char('-');
	else if (p->plus && p->zero)
		p->return_value += ft_print_char('+');
	ft_len_zero_handling_float(p, f, n);
	if (is_negative(n) && !p->zero)
		p->return_value += ft_print_char('-');
	else if (p->plus && !p->zero)
		p->return_value += ft_print_char('+');
	p->return_value += ft_putnstr(nbr, (p->precision + \
	ft_nbrlen(f->trunc, 10) + 1));
	if (!f->decimal)
	{
		while (p->precision-- > 1)
			p->return_value += ft_print_char('0');
	}
	free(nbr);
	free(f);
	return (0);
}

int	ft_print_l_float(t_parameter *p, va_list *ap)
{
	double	n;
	char	*nbr;
	t_float	*f;

	f = NULL;
	f = memalloc_float(f);
	nbr = NULL;
	n = va_arg(*ap, double);
	if (is_negative(n) && (p->precision < 6 || !p->precision))
		p->width--;
	if (!p->precision && !p->dot)
		p->precision = 6;
	if (!p->precision && p->dot)
		p->width++;
	split_float(p, f, n);
	nbr = f_join(p, f, nbr);
	if (p->space && (!is_negative(n)))
		p->return_value += ft_print_char(' ');
	if (is_negative(n) && p->zero)
		p->return_value += ft_print_char('-');
	else if (p->plus && p->zero)
		p->return_value += ft_print_char('+');
	ft_len_zero_handling_float(p, f, n);
	if (is_negative(n) && !p->zero)
		p->return_value += ft_print_char('-');
	else if (p->plus && !p->zero)
		p->return_value += ft_print_char('+');
	p->return_value += ft_putnstr(nbr, (p->precision + \
	ft_nbrlen(f->trunc, 10) + 1));
	if (!f->decimal)
	{
		while (p->precision-- > 1)
			p->return_value += ft_print_char('0');
	}
	free(nbr);
	free(f);
	return (0);
}	
