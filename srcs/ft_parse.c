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

static void	ft_parse_flags(char *str, t_parameter *p)
{
	while (ft_strchr(FLAGS, *str) && *str != '.')
	{
		if (*str == '#')
			p->sharp = 1;
		if (*str == '0')
			p->zero = 1;
		if (*str == '-')
			p->minus = 1;
		if (*str == '+')
			p->plus = 1;
		if (*str == ' ')
			p->space = 1;
		str++;
		p->format++;
	}
}

static void	ft_parse_width(char *str, va_list *ap, t_parameter *p)
{
	int	checked;

	checked = 0;
	while (!ft_strchr(SPECIFIERS, *str) && !ft_strchr(LENGTH, *str))
	{
		if (*str == '.')
			return ;
		if ((ft_strchr(WIDTH, *str) || *str == '*') && !checked)
		{
			if (*str == '*')
				p->width = va_arg(*ap, int);
			else
				p->width = ft_atoi(str);
			checked = 1;
		}
		str++;
		p->format++;
	}
}

static void	ft_parse_precision(char *str, va_list *ap, t_parameter *p)
{
	int	checked;

	checked = 0;
	if (*str != '.')
		return ;
	p->dot = 1;
	str++;
	p->format++;
	while (!ft_strchr(SPECIFIERS, *str) && !ft_strchr(LENGTH, *str))
	{
		if ((ft_isdigit(*str) || *str == '*') && !checked)
		{
			if (*str == '*')
				p->precision = va_arg(*ap, int);
			else
				p->precision = ft_atoi(str);
			checked = 1;
		}
		str++;
		p->format++;
	}
}

static void	ft_parse_length(char *str, t_parameter *p)
{
	int		i;
	char	*tmp;

	tmp = malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	while (!ft_strchr(SPECIFIERS, str[i]))
	{
		if (ft_strchr(LENGTH, str[i]))
		{
			tmp[i] = str[i];
			is_it_double_specifier(str, p, tmp, i);
		}
		i++;
		p->format++;
	}
	p->length = ft_strdup(tmp);
	if (ft_strcmp("ll", p->length) && ft_strcmp("l", p->length) && \
	ft_strcmp("h", p->length) && ft_strcmp("hh", p->length) && \
	ft_strcmp("L", p->length))
	{
		free(p->length);
		p->length = NULL;
	}
	free(tmp);
}

/*
** Here we are parsing flags, width, precision and length to set up
** all our parameters and return the proper conversion type and format
** %[Flags][Width].[Precision][Length]
*/
int	ft_parse(char *str, va_list *ap, t_parameter *p)
{
	p->format = str;
	ft_parse_flags(p->format, p);
	ft_parse_width(p->format, ap, p);
	ft_parse_precision(p->format, ap, p);
	ft_parse_length(p->format, p);
	p->specifier = *p->format;
	conversion_type(p, ap);
	return (0);
}
