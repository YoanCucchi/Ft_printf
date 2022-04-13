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
			return_value += conversion_type(args, str[i + 1]);
			i++;
		}
		else
			return_value += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (return_value);
}

int	conversion_type(va_list args, const char type)
{
	int	return_value;

	return_value = 0;
	if (type == 'c')
		return_value += ft_print_char(va_arg(args, int));
	else if (type == 's')
		return_value += ft_print_str(va_arg(args, char *));
//	else if (type == 'p')
//		return_value += ft_print_ptr(va_arg(args, void *));
//	else if (type == 'd' || type == 'i')
//		return_value += ft_print_nbr(va_arg(args, int));
//	else if (type == 'u')
//		return_value += ft_print_unsigned(va_arg(args, unsigned int));
//	else if (type == 'x' || type == 'X')
//		return_value += ft_print_hex(va_arg(args, unsigned int));
	else if (type == '%')
		return_value += ft_print_percent();
	return(return_value);
}
