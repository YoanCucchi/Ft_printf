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
	char			*nbr;

	n = va_arg(*ap, int);
	nbr = ft_octal_itoa(n);
	len = ft_strlen(nbr);
	ft_len_zero_handling_octal(p, n, len);
	if (!p->precision && !p->width && n == 0 && !p->sharp)
		return (0);
	else if (n != 0)
		p->return_value += ft_recursive_octal(p, n, n);
	len = ft_strlen(nbr);
	if (p->minus)
		minus_flag(p, n, len);
	return (0);
}

int	ft_print_long_o(t_parameter *p, va_list *ap)
{
	int				len;
	unsigned long	n;
	char			*nbr;

	n = va_arg(*ap, long);
	nbr = ft_octal_itoa(n);
	len = ft_strlen(nbr);
	ft_len_zero_handling_octal(p, n, len);
	if (!p->precision && !p->width && n == 0 && !p->sharp)
		return (0);
	else
		p->return_value += ft_recursive_octal(p, n, n);
	return (0);
}

int	ft_print_llong_o(t_parameter *p, va_list *ap)
{
	int					len;
	unsigned long long	n;
	char				*nbr;

	n = va_arg(*ap, long long);
	nbr = ft_octal_itoa(n);
	len = ft_strlen(nbr);
	ft_len_zero_handling_octal(p, n, len);
	if (!p->precision && !p->width && n == 0 && !p->sharp)
		return (0);
	else
		p->return_value += ft_recursive_octal(p, n, n);
	return (0);
}

int	ft_print_short_o(t_parameter *p, va_list *ap)
{
	int				len;
	unsigned short	n;
	char			*nbr;

	n = va_arg(*ap, int);
	nbr = ft_octal_itoa(n);
	len = ft_strlen(nbr);
	ft_len_zero_handling_octal(p, n, len);
	if (!p->precision && !p->width && n == 0 && !p->sharp)
		return (0);
	else
		p->return_value += ft_recursive_octal(p, n, n);
	return (0);
}

int	ft_print_char_octal(t_parameter *p, va_list *ap)
{
	int				len;
	unsigned char	n;
	char			*nbr;

	n = va_arg(*ap, int);
	nbr = ft_octal_itoa(n);
	len = ft_strlen(nbr);
	ft_len_zero_handling_octal(p, n, len);
	if (!p->precision && !p->width && n == 0 && !p->sharp)
		return (0);
	else
		p->return_value += ft_recursive_octal(p, n, n);
	return (0);
}
