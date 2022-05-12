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
	parameter_print(p);
	if (p->plus && nbr[0] != '-')
		p->return_value += ft_print_char('+');
	if (nbr[0] == '-' && p->zero)
		p->return_value += ft_print_char('-');
	ft_len_zero_handling(p, len);
	if (nbr[0] == '-' && p->zero)
		p->return_value += write(1, nbr + 1, --len);
	else if (p->dot && !p->precision && n == 0)
		return (0);
	else if (n == 0 && p->precision <= 0)
		p->return_value += ft_print_char('0');
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

	n = va_arg(*ap, int);
	nbr = ft_itoa_unsigned(n);
	len = ft_strlen(nbr);
	ft_len_zero_handling(p, len);
	if (p->dot && !p->precision && n == 0)
		return (0);
	else if (n == 0 && p->precision <= 0)
		p->return_value += ft_print_char('0');
	else
		p->return_value += write(1, nbr, len);
	free(nbr);
	return (0);
}

int	ft_print_short_nbr(t_parameter *p, va_list *ap)
{
	int		len;
	char	*nbr;
	short	n;

	n = va_arg(*ap, int);
	nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	if (p->plus && nbr[0] != '-')
		p->return_value += ft_print_char('+');
	if (nbr[0] == '-' && p->zero)
		p->return_value += ft_print_char('-');
	ft_len_zero_handling(p, len);
	if (nbr[0] == '-' && p->zero)
		p->return_value += write(1, nbr + 1, --len);
	else if (p->dot && !p->precision && n == 0)
		return (0);
	else if (n == 0 && p->precision <= 0)
		p->return_value += ft_print_char('0');
	else
		p->return_value += write(1, nbr, len);
	free(nbr);
	return (0);
}

int	ft_print_long_nbr(t_parameter *p, va_list *ap)
{
	int		len;
	char	*nbr;
	long	n;

	n = va_arg(*ap, long);
	nbr = ft_long_itoa(n);
	len = ft_strlen(nbr);
	if (p->plus && nbr[0] != '-')
		p->return_value += ft_print_char('+');
	if (nbr[0] == '-' && p->zero)
		p->return_value += ft_print_char('-');
	ft_len_zero_handling(p, len);
	if (nbr[0] == '-' && p->zero)
		p->return_value += write(1, nbr + 1, --len);
	else if (p->dot && !p->precision && n == 0)
		return (0);
	else if (n == 0 && p->precision <= 0)
		p->return_value += ft_print_char('0');
	else
		p->return_value += write(1, nbr, len);
	free(nbr);
	return (0);
}

int	ft_print_long_long_nbr(t_parameter *p, va_list *ap)
{
	int		len;
	char	*nbr;
	unsigned long long	n;

	n = va_arg(*ap, long long);
	nbr = ft_long_itoa(n);
	len = ft_strlen(nbr);
	if (p->plus && nbr[0] != '-')
		p->return_value += ft_print_char('+');
	if (nbr[0] == '-' && p->zero)
		p->return_value += ft_print_char('-');
	ft_len_zero_handling(p, len);
	if (nbr[0] == '-' && p->zero)
		p->return_value += write(1, nbr + 1, --len);
	else if (p->dot && !p->precision && n == 0)
		return (0);
	else if (n == 0 && p->precision <= 0)
		p->return_value += ft_print_char('0');
	else
		p->return_value += write(1, nbr, len);
	free(nbr);
	return (0);
}

int	ft_print_ulong_nbr(t_parameter *p, va_list *ap)
{
	int		len;
	char	*nbr;
	unsigned long	n;

	n = va_arg(*ap, long);
	nbr = ft_unsigned_long_itoa(n);
	len = ft_strlen(nbr);
	ft_len_zero_handling(p, len);
	if (p->dot && !p->precision && n == 0)
		return (0);
	else if (n == 0 && p->precision <= 0)
		p->return_value += ft_print_char('0');
	else
		p->return_value += write(1, nbr, len);
	free(nbr);
	return (0);
}

int	ft_print_ushort_nbr(t_parameter *p, va_list *ap)
{
	int		len;
	char	*nbr;
	unsigned short	n;

	n = va_arg(*ap, int);
	nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	ft_len_zero_handling(p, len);
	if (p->dot && !p->precision && n == 0)
		return (0);
	else if (n == 0 && p->precision <= 0)
		p->return_value += ft_print_char('0');
	else
		p->return_value += write(1, nbr, len);
	free(nbr);
	return (0);
}

int	ft_print_char_nbr(t_parameter *p, va_list *ap)
{
	int		len;
	char	*nbr;
	signed char	n;

	n = va_arg(*ap, int);
	nbr = ft_long_itoa(n);
	len = ft_strlen(nbr);
	if (p->dot && !p->precision && n == 0)
		return (0);
	if (p->plus && nbr[0] != '-')
		p->return_value += ft_print_char('+');
	ft_len_zero_handling(p, len);
	p->return_value += write(1, nbr, len);
	free(nbr);
	return (0);
}

int	ft_print_uchar_nbr(t_parameter *p, va_list *ap)
{
	int			len;
	char		*nbr;
	unsigned char	n;

	n = va_arg(*ap, int);
	nbr = ft_long_itoa(n);
	len = ft_strlen(nbr);
	if (p->dot && !p->precision && n == 0)
		return (0);
	ft_len_zero_handling(p, len);
	p->return_value += write(1, nbr, len);
	free(nbr);
	return (0);
}
