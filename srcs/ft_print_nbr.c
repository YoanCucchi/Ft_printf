/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:38:06 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/15 15:38:06 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_nbr(t_parameter *p, va_list *ap)
{
	int		n;
	int		len;
	char	*nbr;

	n = va_arg(*ap, int);
	nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	if (!p->precision)
		p->precision = p->width;
	if (p->plus && nbr[0] != '-' && p->specifier != 'u')
		p->return_value += ft_print_char('+');
	if (nbr[0] == '-' && p->zero && p->specifier != 'u')
		p->return_value += ft_print_char('-');
	while (p->width-- - len > 0)
	{
		if (!p->zero || p->precision <= len)
			p->return_value += ft_print_char(' ');
		else
			p->return_value += ft_print_char('0');
	}
	if (nbr[0] == '-' && p->zero)
		p->return_value += write(1, ++nbr, --len);
	else
		p->return_value += write(1, nbr, len);
	free(nbr);
	return (0);
}

int	ft_print_unsigned_nbr(t_parameter *p, va_list *ap)
{
	unsigned int	n;
	int				len;
	char			*nbr;

	printf("test");
	n = va_arg(*ap, unsigned int);
	nbr = ft_itoa_unsigned(n);
	len = ft_strlen(nbr);
	if (!p->precision)
		p->precision = p->width;
	while (p->width-- - len > 0)
	{
		if (!p->zero || p->precision <= len)
			p->return_value += ft_print_char(' ');
		else
			p->return_value += ft_print_char('0');
	}
	p->return_value += write(1, nbr, len);
	free(nbr);
	return (0);
}

int	ft_print_short_nbr(t_parameter *p, va_list *ap)
{
	short int	n;
	int			len;
	char		*nbr;

	n = (short int)va_arg(*ap, int);
	nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	if (!p->precision)
		p->precision = p->width;
	if (p->plus && nbr[0] != '-' && p->specifier != 'u')
		p->return_value += ft_print_char('+');
	if (nbr[0] == '-' && p->zero && p->specifier != 'u')
		p->return_value += ft_print_char('-');
	while (p->width-- - len > 0)
	{
		if (!p->zero || p->precision <= len)
			p->return_value += ft_print_char(' ');
		else
			p->return_value += ft_print_char('0');
	}
	if (nbr[0] == '-' && p->zero)
		p->return_value += write(1, ++nbr, --len);
	else
		p->return_value += write(1, nbr, len);
	return (0);
}

int	ft_print_long_nbr(t_parameter *p, va_list *ap)
{
	long long	n;
	int			len;
	char		*nbr;

	n = va_arg(*ap, long long);
	nbr = ft_long_itoa(n);
	len = ft_strlen(nbr);
	if (!p->precision)
		p->precision = p->width;
	if (p->plus && nbr[0] != '-' && p->specifier != 'u')
		p->return_value += ft_print_char('+');
	if (nbr[0] == '-' && p->zero && p->specifier != 'u')
		p->return_value += ft_print_char('-');
	while (p->width-- - len > 0)
	{
		if (!p->zero || p->precision <= len)
			p->return_value += ft_print_char(' ');
		else
			p->return_value += ft_print_char('0');
	}
	if (nbr[0] == '-' && p->zero)
		p->return_value += write(1, ++nbr, --len);
	else
		p->return_value += write(1, nbr, len);
	free(nbr);
	return (0);
}

int	ft_print_long_unsigned_nbr(t_parameter *p, va_list *ap)
{
	unsigned long long	n;
	int					len;
	char				*nbr;

	n = va_arg(*ap, unsigned long long);
	nbr = ft_unsigned_long_itoa(n);
	len = ft_strlen(nbr);
	if (!p->precision)
		p->precision = p->width;
	if (p->plus && nbr[0] != '-' && p->specifier != 'u')
		p->return_value += ft_print_char('+');
	if (nbr[0] == '-' && p->zero && p->specifier != 'u')
		p->return_value += ft_print_char('-');
	while (p->width-- - len > 0)
	{
		if (!p->zero || p->precision <= len)
			p->return_value += ft_print_char(' ');
		else
			p->return_value += ft_print_char('0');
	}
	if (nbr[0] == '-' && p->zero)
		p->return_value += write(1, ++nbr, --len);
	else
		p->return_value += write(1, nbr, len);
	free(nbr);
	return (0);
}