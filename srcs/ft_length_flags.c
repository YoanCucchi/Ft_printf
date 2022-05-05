/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:00:45 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/03 12:00:46 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_parse_l(t_parameter *p, va_list *ap)
{
	long n;

	n = 0;
	printf("inside parse_l\n");
	if (p->specifier == 'd' || p->specifier == 'i')
	{
		n = (long)va_arg(*ap, long);
		p->return_value += ft_print_long_nbr(p, ap, n);
	}
	// if (p->specifier == 'o')
	// 	p->return_value += ft_print_ulong_octal(p, ap);
	else if (p->specifier == 'u')
	{
		n = (unsigned long)va_arg(*ap, unsigned long);
		p->return_value += ft_print_ulong_nbr(p, ap, n);
	}
	//  if (p->specifier == 'x' || p->specifier == 'X')
	// 	p->return_value += ft_print_ulong_hex(p, ap);
	return (0);
}

static int	ft_parse_ll(t_parameter *p, va_list *ap)
{
	unsigned long long n;

	n = 0;
	printf("inside parse_ll\n");
	if (p->specifier == 'd' || p->specifier == 'i')
	{
		n = (long long)va_arg(*ap, long long);
		p->return_value += ft_print_long_nbr(p, ap, n);
	}
	// if (p->specifier == 'o')
	// 	p->return_value += ft_print_ulong_long_octal(p, ap);
	else if (p->specifier == 'u')
	{
		n = (unsigned long long)va_arg(*ap, unsigned long long);
		p->return_value += ft_print_ulong_nbr(p, ap, n);
	}
	//  if (p->specifier == 'x' || p->specifier == 'X')
	// 	p->return_value += ft_print_ulong_long_hex(p, ap);
	return (0);
}

static int	ft_parse_h(t_parameter *p, va_list *ap)
{
	short int	n;

	n = 0;
	// if (p->specifier == 'd' || p->specifier == 'i')
	// 	p->return_value += ft_print_short_nbr(p, ap);
	// if (p->specifier == 'o')
	// 	p->return_value += ft_print_ushort_octal(p, ap);
	// if (p->specifier == 'u')
	// 	p->return_value += ft_print_ushort_nbr(p, ap);
	//  if (p->specifier == 'x' || p->specifier == 'X')
	// 	p->return_value += ft_print_ushort_hex(p, ap);
	return (0);
}

static int	ft_parse_hh(t_parameter *p, va_list *ap)
{
	// if (p->specifier == 'd' || p->specifier == 'i')
	// 	p->return_value += ft_print_char_nbr(p, ap);
	// if (p->specifier == 'o')
	// 	p->return_value += ft_print_uchar_octal(p, ap);
	// if (p->specifier == 'u')
	// 	p->return_value += ft_print_uchar_nbr(p, ap);
	// if (p->specifier == 'x' || p->specifier == 'X')
	// 	p->return_value += ft_print_uchar_hex(p, ap);
	return (0);
}

int	ft_length_flags(t_parameter *p, va_list *ap)
{
	printf("inside length flags\n");
	if (!ft_strcmp("l", p->length))
		p->return_value += ft_parse_l(p, ap);
	if (!ft_strcmp("ll", p->length))
		p->return_value += ft_parse_ll(p, ap);
	if (!ft_strcmp("h", p->length))
		p->return_value += ft_parse_h(p, ap);
	if (!ft_strcmp("hh", p->length))
		p->return_value += ft_parse_hh(p, ap);
	return (0);
}
