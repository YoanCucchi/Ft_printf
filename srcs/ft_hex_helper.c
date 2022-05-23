/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:44:08 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/12 15:44:09 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	zerox_print(t_parameter *p)
{
	if (p->specifier == 'X')
		p->return_value += ft_putnstr("0X", 2);
	else
		p->return_value += ft_putnstr("0x", 2);
	p->checked = 1;
}

int	ft_recursive_hex(t_parameter *p, size_t n, size_t iteration)
{
	int		remainder;
	char	character;

	if (n > 0 || !iteration)
	{
		remainder = n % 16;
		if (p->specifier != 'X')
			character = HEXALOWCASE[remainder];
		else
			character = HEXAUPCASE[remainder];
		n /= 16;
		iteration = 1;
		p->return_value += ft_recursive_hex(p, n, iteration);
		p->return_value += ft_print_char(character);
	}
	return (0);
}

void	ft_len_zero_handling_hex(t_parameter *p, long long n, int len)
{
	p->highest_value = who_is_biggest_of_3(p->precision, p->width, len);
	if (n == 0 && p->dot)
		len = 0;
	if (p->sharp && n != 0)
		p->highest_value -= 2;
	if (p->width > p->precision && !p->minus)
	{
		if (p->sharp && (p->dot || p->zero) && n != 0 &&\
		(p->precision < len || !p->precision))
			zerox_print(p);
		while (p->highest_value-- > who_is_biggest_of_2(p->precision, len))
		{
			if (p->zero && !p->dot && (p->precision < len || !p->precision))
				p->return_value += ft_print_char('0');
			else
				p->return_value += ft_print_char(' ');
		}
	}
	if (p->sharp && n != 0 && !p->checked && ((!p->precision && !p->dot) || \
	p->precision >= len || (!p->precision && p->dot)))
		zerox_print(p);
	while (p->precision > len++)
		p->return_value += ft_print_char('0');
}

void	ft_len_zero_handling_p(t_parameter *p, long long n, int len)
{
	p->highest_value = who_is_biggest_of_3(p->precision, p->width, len);
	if (n == 0 && p->dot)
		len = 0;
	p->highest_value -= 2;
	if (n != 0 && p->precision > len)
		p->return_value += ft_putnstr("0x", 2);
	if (p->width > p->precision && !p->minus)
	{
		if (p->highest_value + 3 > len && n != 0 && !p->precision)
			p->highest_value--;
		while (p->highest_value-- > who_is_biggest_of_2(p->precision, len))
		{
			if ((p->zero) && (p->precision > len || !p->precision))
				p->return_value += ft_print_char('0');
			else
				p->return_value += ft_print_char(' ');
		}
	}
	if (n == 0 || p->precision < len)
		p->return_value += ft_putnstr("0x", 2);
	while (p->precision > len++)
		p->return_value += ft_print_char('0');
}
