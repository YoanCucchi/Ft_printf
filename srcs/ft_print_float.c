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
	// parameter_print(p);
	// printf("nbrlen = %d\n", ft_nbrlen(f->trunc, 10));
	while (p->width-- > p->precision + p->space + p->plus + ft_nbrlen(f->trunc, 10) + 1)
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

int	ft_print_float(t_parameter *p, va_list *ap)
{
	double	n;
	char	*nbr;
	t_float	*f;
	int		tmp;

// need to fix + with - number
// need to impletet space flag
// need to create length flag floats
// need to handle 0 flag
// protect malloc
// need to fix when width > precision
	tmp = 0;
	f = NULL;
	f = memalloc_float(f);
	nbr = NULL;
	n = va_arg(*ap, double);
	// printf("n = %f\n", n);
	if (is_negative(n) && !p->precision) // pas bon
		p->width--;
	if (!p->precision && !p->dot)
		p->precision = 6;
	split_float(p, f, n);
	// printf("f->trunc = %llu\n", f->trunc);
	// printf("f->decimal = %llu\n", f->decimal);
	nbr = f_join(p, f, nbr);
	// printf("nbr = %s\n", nbr);
	if (p->space && !is_negative(n) && !p->plus) // pas bon non plus
	{
		p->return_value += ft_print_char(' ');
		p->width--;
	}
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
	tmp = p->precision;
	if (f->trunc == 0 && f->decimal == 0)
	{
		while (tmp-- > 1)
			p->return_value += ft_print_char('0');
	}
	ft_len_zero_handling_float(p, f, n);
	while (p->precision-- > 1 && f->decimal == '0' && f->trunc)
		p->return_value += ft_print_char('0');
	free(nbr);
	free(f);
	return (0);
}

int	ft_print_l_float(t_parameter *p, va_list *ap)
{
	double	n;
	char	*nbr;
	t_float	*f;
	int		tmp;

// need to fix + with - number
// need to impletet space flag
// need to create length flag floats
// need to handle 0 flag
// protect malloc
// need to fix when width > precision
	tmp = 0;
	f = NULL;
	f = memalloc_float(f);
	nbr = NULL;
	n = va_arg(*ap, long double);
	// printf("n = %f\n", n);
	if (!p->precision && !p->dot)
		p->precision = 6;
	if (is_negative(n))
		p->width--;
	split_float(p, f, n);
	// printf("f->trunc = %llu\n", f->trunc);
	// printf("f->decimal = %llu\n", f->decimal);
	nbr = f_join(p, f, nbr);
	// printf("nbr = %s\n", nbr);
	ft_len_zero_handling_float(p, f, n);
	if (is_negative(n))
		p->return_value += ft_print_char('-');
	else if (p->plus)
		p->return_value += ft_print_char('+');
	p->return_value += ft_putnstr(nbr, (p->precision + \
	ft_nbrlen(f->trunc, 10) + 1));
	tmp = p->precision;
	if (f->trunc == 0 && f->decimal == 0)
	{
		while (tmp-- > 1)
			p->return_value += ft_print_char('0');
	}
	ft_len_zero_handling_float(p, f, n);
	free(nbr);
	free(f);
	return (0);
}

