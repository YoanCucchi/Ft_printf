/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:50:52 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/12 15:50:53 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_char_hex(t_parameter *p, va_list *ap)
{
	unsigned char	n;
	int				len;

	n = va_arg(*ap, int);
	len = ft_nbrlen(n, 16);
	ft_len_zero_handling_hex(p, n, len);
	if (n == 0 && !p->dot)
		p->return_value += ft_print_char('0');
	else if (n != 0)
		p->return_value += ft_recursive_hex(p, n, n);
	len = ft_nbrlen(n, 16);
	if (p->minus)
		minus_flag(p, n, len);
	if (p->width > p->precision && p->zero)
		while (p->highest_value-- > who_is_biggest_of_2(p->precision, len))
			p->return_value += ft_print_char('0');
	return (0);
}

int	ft_print_short_hex(t_parameter *p, va_list *ap)
{
	int				len;
	unsigned short	n;

	n = va_arg(*ap, int);
	len = ft_nbrlen(n, 16);
	ft_len_zero_handling_hex(p, n, len);
	if (n == 0 && !p->dot)
		p->return_value += ft_print_char('0');
	else if (n != 0)
		p->return_value += ft_recursive_hex(p, n, n);
	len = ft_nbrlen(n, 16);
	if (p->minus)
		minus_flag(p, n, len);
	if (p->width > p->precision && p->zero)
		while (p->highest_value-- > who_is_biggest_of_2(p->precision, len))
			p->return_value += ft_print_char('0');
	return (0);
}

int	ft_print_long_hex(t_parameter *p, va_list *ap)
{
	int				len;
	unsigned long	n;

	n = va_arg(*ap, long);
	len = ft_nbrlen(n, 16);
	ft_len_zero_handling_hex(p, n, len);
	if (n == 0 && !p->dot)
		p->return_value += ft_print_char('0');
	else if (n != 0)
		p->return_value += ft_recursive_hex(p, n, n);
	len = ft_nbrlen(n, 16);
	if (p->minus)
		minus_flag(p, n, len);
	if (p->width > p->precision && p->zero)
		while (p->highest_value-- > who_is_biggest_of_2(p->precision, len))
			p->return_value += ft_print_char('0');
	return (0);
}

int	ft_print_long_long_hex(t_parameter *p, va_list *ap)
{
	int					len;
	unsigned long long	n;

	n = va_arg(*ap, long long);
	len = ft_nbrlen(n, 16);
	ft_len_zero_handling_hex(p, n, len);
	if (n == 0 && !p->dot)
		p->return_value += ft_print_char('0');
	else if (n != 0)
		p->return_value += ft_recursive_hex(p, n, n);
	len = ft_nbrlen(n, 16);
	if (p->minus)
		minus_flag(p, n, len);
	if (p->width > p->precision && p->zero)
		while (p->highest_value-- > who_is_biggest_of_2(p->precision, len))
			p->return_value += ft_print_char('0');
	return (0);
}
