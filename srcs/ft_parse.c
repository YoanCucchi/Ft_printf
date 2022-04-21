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

static t_parameter	ft_parse_flags(char *str, t_parameter p)
{
	while (ft_strchr(FLAGS, *str) && *str != '.')
	{
		if (*str == '#')
			p.sharp = 1;
		if (*str == '0')
			p.zero = 1;
		if (*str == '-')
			p.minus = 1;
		if (*str == '+')
			p.plus = 1;
		if (*str == ' ')
			p.space = 1;
		str++;
	}
	return (p);
}

static t_parameter	ft_parse_width(char *str, va_list args, t_parameter p)
{
	int	checked;

	checked = 0;
	while (!ft_strchr(SPECIFIERS, *str) && *str != '.')
	{
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			p.zero = 1;
		else if ((ft_strchr(WIDTH, *str) || *str == '*') && !checked)
		{
			if (*str == '*')
				p.width = va_arg(args, int);
			else
				p.width = ft_atoi(str);
			checked = 1;
		}
		str++;
	}	
	return (p);
}

static t_parameter	ft_parse_precision(char *str, va_list args, t_parameter p)
{
	int	checked;

	checked = 0;
	while (!ft_strchr(SPECIFIERS, *str))
	{
		if ((ft_isdigit(*str) || *str == '*') && !checked)
		{
			if (*str == '*')
				p.precision = va_arg(args, int);
			else
				p.precision = ft_atoi(str);
			checked = 1;
		}
		str++;
	}
	return (p);
}

// p.test = str a fixer
static t_parameter	ft_parse_length(char *str, t_parameter p)
{
	while (!ft_strchr(SPECIFIERS, *str))
	{
		if (ft_strchr(LENGTH, *str))
			p.test = str;
	}
	return (p);
}

/*
** Here we are parsing flags, width, precision and lenght to set up
** all our parameters and return the proper conversion type
** %[Flags][Width].[Precision][Length]
*/
int	ft_parse(char *str, va_list args)
{
	t_parameter	p;

	p = ft_all_to_0();
	p = ft_parse_flags(str, p);
	p = ft_parse_width(str, args, p);
	while (!ft_strchr(SPECIFIERS, *str) && *str != '.')
		str++;
	/*
	** DEALING WITH PRECISION
	*/
	if (*str == '.' && !p.specifier)
	{
		p.dot = 1;
		p = ft_parse_precision(str++, args, p);
		while (!ft_strchr(SPECIFIERS, *str))
			str++;
	}
	if (p.width < 0)
	{
		p.minus = 1;
		p.width *= -1;
	}
//	p = ft_parse_length(str, p);
	p.specifier = *str;
	return (conversion_type(p, args));
}
