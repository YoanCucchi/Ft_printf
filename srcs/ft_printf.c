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
	char	*first;
	
	va_start(args, str);
	return_value = 0;
	while (*str)
	{
		if (*str == '%')
		{
			first = (char *)str;
			if (*(++str))
				return_value += ft_parse((char *)str, args);
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
	va_end(args);
	return (return_value);
}

int	conversion_type(t_parameter p, va_list args)
{
	int	return_value;

	return_value = 0;
	if (p.specifier == 'c')
		return_value += ft_print_char(p.specifier);
	if (p.specifier == 'd')
		return_value += ft_print_nbr(p, args);∑
	if (p.specifier == 's')
		return_value += ft_print_str(p, args);
	if (p.specifier == '%')
		return_value += ft_print_percent();
	return(return_value);
}
