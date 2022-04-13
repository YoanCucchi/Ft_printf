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
#include <stdio.h>

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return(1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	return_value;
	int	i;

	va_start(args, str);
	return_value = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			return_value += find_format(args, str[i + 1]);
			i++;
		}
		else
			return_value += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (return_value);
}

int	find_format(va_list args, const char format)
{
	int	return_value;

	return_value = 0;
	if (format == 'c')
		return_value += ft_print_char(va_arg(args, int));
	else if (format == 's')
		return_value += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		return_value += ft_print_ptr((unsigned long long)va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		return_value += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		return_value += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		return_value += ft_print_hex(va_arg(args, unsigned int));
	else if (format == '%')
		return_value += ft_print_percent();
	return(return_value);
}
