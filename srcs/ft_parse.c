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
		p.format++;
	}
	return (p);
}

static t_parameter	ft_parse_width(char *str, t_parameter p)
{
	int	checked;

	checked = 0;
	while (!ft_strchr(SPECIFIERS, *str) && !ft_strchr(LENGTH, *str) && *str != '.')
	{
		if (*str == '0' && (ft_strchr(WIDTH, *(str - 1))))
			p.zero = 1;
//		else if ((ft_strchr(WIDTH, *str) || *str == '*') && !checked)
//		{
//			if (*str == '*')
//				p.width = va_arg(*args, int);
//			else
				p.width = ft_atoi(str);
			checked = 1;
//		}
		str++;
		p.format++;
	}	
	return (p);
}

static t_parameter	ft_parse_precision(char *str, t_parameter p)
{
	int	checked;

	checked = 0;
	if (*str != '.')
		return (p);
	p.dot = 1;
	str++;
	p.format++;
	while (!ft_strchr(SPECIFIERS, *str) && !ft_strchr(LENGTH, *str))
	{
		if ((ft_isdigit(*str) || *str == '*') && !checked)
		{
	//		if (*str == '*')
	//			p.precision = va_arg(*args, int);
	//		else
				p.precision = ft_atoi(str);
			checked = 1;
		}
		str++;
		p.format++;
	}
	return (p);
}

static t_parameter	ft_parse_length(char *str, t_parameter p)
{
	int		i;
	char	*tmp;

	tmp = malloc(sizeof(char) * ft_strlen(str));
	i = 0;
	while (!ft_strchr(SPECIFIERS, str[i]))
	{
		if (ft_strchr(LENGTH, str[i]))
		{
			tmp[i] = str[i];
			is_it_double_specifier(str, p, tmp, i);
		}
		i++;
		p.format++;
	}
	p.length = ft_strdup(tmp);
	free(tmp);
	return (p);
}

/*
** Here we are parsing flags, width, precision and length to set up
** all our parameters and return the proper conversion type and format
** %[Flags][Width].[Precision][Length]
*/
int	ft_parse(char *str, va_list *ap)
{
	t_parameter	p;

	p = ft_all_to_0();
	p.format = str;
	p = ft_parse_flags(p.format, p);
	p = ft_parse_width(p.format, p);
	p = ft_parse_precision(p.format, p);
	p = ft_parse_length(p.format, p);
	p.specifier = *p.format;
	return (conversion_type(p, ap));
}
