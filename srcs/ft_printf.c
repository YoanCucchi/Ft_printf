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

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		return_value;
	char	*first;

	va_start(args, format);
	return_value = 0;
	while (*format)
	{
		if (*format == '%')
		{
			first = (char *)format;
			if (*(++format))
				return_value += ft_parse((char *)format, args);
			while (*format && !ft_strchr(SPECIFIERS, *format))
				format++;
			if (!(*format))
				format = first;
		}
		else
			return_value += ft_print_char(*format);
		if (*format)
			format++;
	}
	va_end(args);
	return (return_value);
}

int	conversion_type(t_parameter p, va_list args)
{
	int	return_value;

	return_value = 0;
	if (p.specifier == 'c')
		return_value += ft_print_c(args);
	else if (p.specifier == 's')
		return_value += ft_print_str(p, args);
	else if (p.specifier == 'x' || p.specifier == 'X')
		if (!ft_strcmp(p.length, "hh"))
			return_value += ft_print_hex_hh(p, args);
		else
			return_value += ft_print_hex(p, args);
	else if (p.specifier == 'p')
		return_value += ft_print_p(p, args);
	else if (p.specifier == 'd' || p.specifier == 'i' || p.specifier == 'u')
		return_value += ft_print_nbr(p, args);
	else if (p.specifier == '%')
		return_value += ft_print_percent();
	free(p.length);
	return (return_value);
}
