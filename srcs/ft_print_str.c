/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:38:10 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/15 15:38:11 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_str(t_parameter *p, va_list *ap)
{
	char	*string;

	string = va_arg(*ap, char *);
	if (!string)
		string = "(null)";
	if (p->precision > (int)ft_strlen(string) || !p->precision)
		p->precision = ft_strlen(string);
	if (p->width - p->precision > 0)
		while (p->width-- - p->precision > 0)
			p->return_value += ft_print_char(' ');
	p->return_value += ft_putnstr(string, p->precision);
	return (0);
}

int	ft_print_c(t_parameter *p, va_list *ap)
{
	char	c;

	c = va_arg(*ap, int);
	p->return_value += ft_print_char(c);
	return (0);
}

int	ft_print_percent(t_parameter *p)
{
	if (!p->precision)
		p->precision = 1;
	if (p->width - p->precision > 0)
		while (p->width-- - p->precision > 0)
			p->return_value += ft_print_char(' ');
	p->return_value += ft_print_char('%');
	return (0);
}
