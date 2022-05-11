/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:13:14 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/09 10:13:16 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_octal(t_parameter *p, va_list *ap)
{
	unsigned int	n;
	int				len;

	n = va_arg(*ap, int);
	len = ft_nbrlen(n, 8);
	ft_len_zero_handling_octal(p, n, len);
	if (n != 0 && p->precision <= 0 && !p->sharp)
		p->return_value += ft_recursive_octal(p, n, n);
	else if (n != 0 && p->precision < 0 && p->sharp)
		p->return_value += ft_print_char(' ');
	else if (p->dot && !p->precision && n == 0 && !p->sharp)
		p->return_value += ft_print_char(' ');
	else
		p->return_value += ft_recursive_octal(p, n, n);
	return (0);
}

int	ft_print_long_o(t_parameter *p, va_list *ap)
{
	int	len;
	unsigned long	n;

	n = va_arg(*ap, long);
	len = ft_nbrlen(n, 8);
	ft_len_zero_handling_octal(p, n, len);
	if (n != 0 && p->precision <= 0 && !p->sharp)
		p->return_value += ft_recursive_octal(p, n, n);
	else if (n != 0 && p->precision < 0 && p->sharp)
		p->return_value += ft_print_char(' ');
	else if (p->dot && !p->precision && n == 0 && !p->sharp)
		p->return_value += ft_print_char(' ');
	else
		p->return_value += ft_recursive_octal(p, n, n);
	return (0);
}

int	ft_print_llong_o(t_parameter *p, va_list *ap)
{
	int	len;
	unsigned long long	n;


	n = va_arg(*ap, long long);
	len = ft_nbrlen(n, 8);
	ft_len_zero_handling_octal(p, n, len);
	if (n != 0 && p->precision <= 0 && !p->sharp)
		p->return_value += ft_recursive_octal(p, n, n);
	else if (n != 0 && p->precision < 0 && p->sharp)
		p->return_value += ft_print_char(' ');
	else if (p->dot && !p->precision && n == 0 && !p->sharp)
		p->return_value += ft_print_char(' ');
	else
		p->return_value += ft_recursive_octal(p, n, n);
	return (0);
}

int	ft_print_short_o(t_parameter *p, va_list *ap)
{
	int	len;
	unsigned short	n;

	n = va_arg(*ap, int);
	len = ft_nbrlen(n, 8);
	ft_len_zero_handling_octal(p, n, len);
	if (n != 0 && p->precision <= 0 && !p->sharp)
		p->return_value += ft_recursive_octal(p, n, n);
	else if (n != 0 && p->precision < 0 && p->sharp)
		p->return_value += ft_print_char(' ');
	else if (p->dot && !p->precision && n == 0 && !p->sharp)
		p->return_value += ft_print_char(' ');
	else
		p->return_value += ft_recursive_octal(p, n, n);
	return (0);
}

int	ft_print_char_octal(t_parameter *p, va_list *ap)
{
	int	len;
	unsigned char	n;

	n = va_arg(*ap, int);
	len = ft_nbrlen(n, 8);
	ft_len_zero_handling_octal(p, n, len);
	if (n != 0 && p->precision <= 0 && !p->sharp)
		p->return_value += ft_recursive_octal(p, n, n);
	else if (n != 0 && p->precision < 0 && p->sharp)
		p->return_value += ft_print_char(' ');
	else if (p->dot && !p->precision && n == 0 && !p->sharp)
		p->return_value += ft_print_char(' ');
	else
		p->return_value += ft_recursive_octal(p, n, n);
	return (0);
}
