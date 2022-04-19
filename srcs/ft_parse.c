/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:15:18 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/15 16:15:20 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static t_parameter	ft_parse_flags(char *str, t_parameter p)
{
	while (*str != '.' && !ft_strchr(SPECIFIERS, *str))
	{
		if (*str == '-')
			p.minus = 1;
		if (*str == '+')
			p.plus = 1;
		if (*str == ' ')
			p.space = 1;
		if (*str == '#')
			p.sharp = 1;
		str++;
	}
	return (p);
}

static t_parameter	ft_parse_width(char *str, va_list args, t_parameter p)
{
	int	specified;

	specified = 0;
	while (*str != '.' && !ft_strchr(SPECIFIERS, *str))
	{
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			p.zero = 1;
		else if (((*str > '0' && *str <= '9') || *str == '*') && !specified)
		{
			if (*str == '*')
				p.width = va_arg(args, int);
			else
				p.width = ft_atoi(str);
			specified = 1;
		}
		str++;
	}	
	return (p);
}

static t_parameter	ft_parse_precision(char *str, va_list args, t_parameter p)
{
	int	specified;

	specified = 0;
	while (!ft_strchr(SPECIFIERS, *str))
	{
		if ((ft_isdigit(*str) || *str == '*') && !specified)
		{
			if (*str == '*')
				p.precision = va_arg(args, int);
			else
				p.precision = ft_atoi(str);
			specified = 1;
		}
		str++;
	}
	return (p);
}

int	ft_parse(char *str, va_list args)
{
	//%[Flags][Width].[Precision][Specifier]

	t_parameter	newparameter;

	newparameter = ft_all_to_0();
	while (!ft_strchr(SPECIFIERS, *str) && *str != '.')
		str++;
	newparameter.specifier = *str;
	return (conversion_type(newparameter, args));
}