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
	p->highest_value = who_is_biggest_of_3(p->precision, p->width, len);
	// printf("len : %d\n", len);
	// parameter_print(p);
	if (n == 0 && p->dot)
		len = 0;
	if ((n < 0 || p->plus) && (p->specifier == 'd' || p->specifier == 'i') \
	&& p->width && p->dot && (p->width > p->precision || p->width > len))
		p->highest_value--;
	if (p->plus && n >= 0 && (p->specifier == 'd' || p->specifier == 'i'))
	{
		p->return_value += ft_print_char('+');
		p->highest_value--;
	}
	else if (n < 0 && p->zero && (p->specifier == 'd' || p->specifier == 'i'))
	{
		p->return_value += ft_print_char('-');
		p->highest_value--;
		len--;
	}
	else if (p->space && !p->plus && n > 0 && p->specifier != 'u' && p->precision < len)
		p->return_value += ft_print_char(' ');
	if (p->width > p->precision && !p->minus)
	{
		while (p->highest_value-- > who_is_biggest_of_2(p->precision, len))
		{
			if (!p->zero)
				p->return_value += ft_print_char(' ');
			else
				p->return_value += ft_print_char('0');
		}
	}
	if (n < 0 && !p->zero && (p->specifier == 'd' || p->specifier == 'i'))
	{
		p->return_value += ft_print_char('-');
		p->highest_value--;
		len--;
	}
	if (p->precision > len)
		while (p->precision > len++)
			p->return_value += ft_print_char('0');
}

void	is_it_double_specifier(char *str, char *tmp, int i)
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

int	who_is_biggest_of_2(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	who_is_biggest_of_3(int a, int b, int c)
{
	if (a >= b && a >= c)
		return (a);
	else if (b >= a && b >= c)
		return (b);
	else
		return (c);
}

void	minus_flag(t_parameter *p, long long n, int len)
{
	if (n == 0 && p->dot)
		len = 0;
	if (p->plus || n < 0)
		len--;
	if (p->width > p->precision && p->width > len)
		while (p->highest_value-- > who_is_biggest_of_2(p->precision, len))
			p->return_value += ft_print_char(' ');
}
