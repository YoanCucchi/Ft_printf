/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:00:48 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/12 11:35:25 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		return_value;
	char	*first;

	va_start(ap, str);
	return_value = 0;
	first = NULL;
	while (*str)
	{
		if (*str == '%')
		{
			first = (char *)str;
			if (*(++str))
				return_value += ft_parse((char *)str, &ap);
			while (*str && !ft_strchr(SPECIFIERS, *str))
				str++;
			if (!(*str))
				str = first;
		}
		else
			return_value += ft_print_char(*str);
		if (*str)
			str++;
	}
	va_end(ap);
	return (return_value);
}

int	conversion_type(t_parameter p, va_list *ap)
{
	int	return_value;

	return_value = 0;
	if (p.specifier == 'c')
		return_value += ft_print_c(ap);
	else if (p.specifier == 's')
		return_value += ft_print_str(p, ap);
	else if (p.specifier == 'x' || p.specifier == 'X')
	{
		if (!ft_strcmp(p.length, "hh"))
			return_value += ft_print_hex_hh(p, ap);
		else
			return_value += ft_print_hex(p, ap);
	}
	else if (p.specifier == 'p')
		return_value += ft_print_p(p, ap);
	else if (p.specifier == 'd' || p.specifier == 'i')
		return_value += ft_print_nbr(p, ap);
	else if (p.specifier == 'u')
		return_value += ft_print_unsigned_nbr(p, ap);
	else if (p.specifier == '%')
		return_value += ft_print_percent(p);
	free(p.length);
	return (return_value);
}
