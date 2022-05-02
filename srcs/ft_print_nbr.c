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

int	ft_print_nbr(t_parameter p, va_list *ap)
{
	int		n;
	int		len;
	char	*nbr;
	int		return_value;

	return_value = 0;
	n = va_arg(*ap, int);
	nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	if (!p.precision)
		p.precision = p.width;
	if (p.plus && nbr[0] != '-' && p.specifier != 'u')
		return_value += ft_print_char('+');
	if (nbr[0] == '-' && p.zero && p.specifier != 'u')
		return_value += ft_print_char('-');
	while (p.width-- - len > 0)
	{
		if (!p.zero || p.precision <= len)
			return_value += ft_print_char(' ');
		else
			return_value += ft_print_char('0');
	}
	if (nbr[0] == '-' && p.zero)
		return_value += write(1, ++nbr, --len);
	else
		return_value += write(1, nbr, len);
	return (return_value);
}
