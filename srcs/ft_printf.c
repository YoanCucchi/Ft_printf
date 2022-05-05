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
	va_list		ap;
	t_parameter	*p;
	char		*first;

	va_start(ap, str);
	p = (t_parameter *)malloc(sizeof(t_parameter));
	if (!p)
		return(-1);
	first = NULL;
	while (*str)
	{
		if (*str == '%')
		{
			ft_all_to_0(p);
			first = (char *)str;
			if (*(++str))
				p->return_value += ft_parse((char *)str, &ap, p);
			while (*str && !ft_strchr(SPECIFIERS, *str))
				str++;
			if (!(*str))
				str = first;
		}
		else
			p->return_value += ft_print_char(*str);
		if (*str)
			str++;
	}
	va_end(ap);
	param_free(p);
	free(p);
	return (p->return_value);
}

int	conversion_type(t_parameter *p, va_list *ap)
{
	if (p->length && (ft_strchr(LENGTH_DISPATCH, *p->format)))
		p->return_value += ft_length_flags(p, ap);
	else if (p->length && (ft_strchr("f", *p->format)))
		p->return_value += ft_length_flags(p, ap);
	else if (p->specifier == 'c')
		p->return_value += ft_print_c(p, ap);
	else if (p->specifier == 's')
		p->return_value += ft_print_str(p, ap);
	else if (p->specifier == 'x' || p->specifier == 'X')
			p->return_value += ft_print_hex(p, ap);
	else if (p->specifier == 'p')
		p->return_value += ft_print_p(p, ap);
	else if (p->specifier == 'd' || p->specifier == 'i')
		p->return_value += ft_print_nbr(p, ap);
	else if (p->specifier == 'u')
		p->return_value += ft_print_unsigned_nbr(p, ap);
	else if (p->specifier == '%')
		p->return_value += ft_print_percent(p);
	return (p->return_value);
}
