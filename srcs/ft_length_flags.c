/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:00:45 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/03 12:00:46 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_parse_l(t_parameter *p, va_list *ap)
{
	if (p->specifier == 'd' || p->specifier == 'i')
		p->return_value += ft_print_long_nbr(p, ap);
	if (p->specifier == 'u')
		p->return_value += ft_print_long_unsigned_nbr(p, ap);
	// if (p->specifier == 'x' || p->specifier == 'X')
		// return(p->return_value += ft_print_long_hex(p, ap));
	return (0);
}

static int	ft_parse_ll(t_parameter *p, va_list *ap)
{
	if (p->specifier == 'd' || p->specifier == 'i')
		p->return_value += ft_print_long_nbr(p, ap);
	if (p->specifier == 'u')
		p->return_value += ft_print_long_unsigned_nbr(p, ap);
	return (0);
}

static int	ft_parse_h(t_parameter *p, va_list *ap)
{
	p->return_value += ft_print_short_nbr(p, ap);
	return (0);
}

static int	ft_parse_hh(t_parameter *p, va_list *ap)
{
	p->return_value += ft_print_nbr(p, ap);
	return (0);
}

int	ft_length_flags (t_parameter *p, va_list *ap)
{
	if (!ft_strcmp("l", p->length))
		p->return_value += ft_parse_l(p, ap);
	if (!ft_strcmp("ll", p->length))
		p->return_value += ft_parse_ll(p, ap);
	if (!ft_strcmp("h", p->length))
		p->return_value += ft_parse_h(p, ap);
	if (!ft_strcmp("hh", p->length))
		p->return_value += ft_parse_hh(p, ap);
	return (0);
}
