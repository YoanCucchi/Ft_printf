/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:35:58 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/15 15:36:06 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_len_zero_handling(t_parameter *p, long long n, int len)
{
	int	highest_value;

	highest_value = 0;
	highest_value = who_is_biggest_of_3(p->precision, p->width, len);
	if (p->sharp && p->specifier == 'o' && n!= 0 && \
	(p->width >= p->precision || !p->precision))
		highest_value--;
	if (p->width - p->precision > 0)
	{
		while (highest_value-- > who_is_biggest_of_2(p->precision, len))
		{
			if (p->zero && (p->precision > len || !p->precision))
				p->return_value += ft_print_char('0');
			else
				p->return_value += ft_print_char(' ');
		}
	}
	if (p->specifier == 'o' && p->sharp && n != 0 && highest_value < len)
		p->return_value += ft_print_char('0');
	else if (p->specifier == 'o' && p->sharp && n != 0 && highest_value - len >= 0)
		p->return_value += ft_print_char(' ');
	if (p->precision > len)
		while (p->precision-- > len)
			p->return_value += ft_print_char('0');
}

void	is_it_double_specifier(char *str, t_parameter *p, char *tmp, int i)
{
	if (str[i] == 'l' && str[i + 1] == 'l')
	{
		i++;
		tmp[i] = str[i];
	}
	if (str[i] == 'h' && str[i + 1] == 'h')
	{
		i++;
		tmp[i] = str[i];
	}
}

void	param_free(t_parameter *p)
{
	p->sharp = 0;
	p->zero = 0;
	p->minus = 0;
	p->plus = 0;
	p->space = 0;
	p->width = 0;
	p->dot = 0;
	p->precision = 0;
	p->specifier = 0;
	free(p->length);
}

int	who_is_biggest_of_2(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	who_is_biggest_of_3(int a, int b, int c)
{
	if (a > b && a > c)
		return (a);
	else if (b > a && b > c)
		return (b);
	else
		return (c);
}
