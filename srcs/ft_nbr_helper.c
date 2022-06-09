/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:08:23 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/23 19:08:25 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	minus_plus_handling_before_zeros(t_parameter *p, long long n)
{
	if (n < 0 && !p->minus_check && (!p->zero || !p->precision || p->precision < p->len) && \
	((p->width < p->precision || p->width < p->len) || p->zero) && \
	p->specifier != 'u')
	{
		p->return_value += ft_print_char('-');
		p->highest_value--;
		p->len--;
		p->minus_check = 1;
	}
	else if (p->plus && p->zero && n >= 0 && p->specifier != 'u')
	{
		p->return_value += ft_print_char('+');
		p->highest_value--;
	}
	else if (p->space && !p->plus && n >= 0 && p->specifier != 'u' && \
	p->precision < p->len)
	{
		p->return_value += ft_print_char(' ');
		p->highest_value--;
	}
}

static void	minus_plus_handling_after_zeros(t_parameter *p, long long n)
{
	if (p->plus && !p->zero && n >= 0 && p->specifier != 'u')
	{
		p->return_value += ft_print_char('+');
		p->highest_value--;
	}
	if (n < 0 && !p->minus_check && p->specifier != 'u' && \
	(p->width > p->precision || p->width > p->len))
	{
		p->return_value += ft_print_char('-');
		p->highest_value--;
		p->len--;
	}
}

void	ft_len_zero_handling_nbr(t_parameter *p, long long n)
{
	p->highest_value = who_is_biggest_of_3(p->precision, p->width, p->len);
	if (n == 0 && p->dot)
		p->len = 0;
	if (((n < 0 && p->precision >= p->len) || p->plus) && p->specifier != 'u' \
	&& p->width && p->dot && \
	(p->width > p->precision && (p->precision > p->len || p->width > p->len)))
		p->highest_value--;
	minus_plus_handling_before_zeros(p, n);
	if (p->width > p->precision && !p->minus)
	{
		while (p->highest_value-- > who_is_biggest_of_2(p->precision, p->len))
		{
			if (!p->zero || p->precision > p->len)
				p->return_value += ft_print_char(' ');
			else
				p->return_value += ft_print_char('0');
		}
	}
	minus_plus_handling_after_zeros(p, n);
	p->zeros_print = p->precision - p->len;
	if (p->zeros_print > 0)
		while (p->zeros_print-- > 0)
			p->return_value += ft_print_char('0');
}
