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

static int	ft_parse_l(t_parameter *p, va_list *ap, int return_value)
{
	if (p->specifier == 'd' || p->specifier == 'i')
		return(return_value += ft_print_long_nbr(p, ap));
	if (p->specifier == 'u')
		return_value += ft_print_long_unsigned_nbr(p, ap);
	// if (p->specifier == 'x' || p->specifier == 'X')
		// return(return_value += ft_print_long_hex(p, ap));
	return (return_value);
}

static int	ft_parse_ll(t_parameter *p, va_list *ap, int return_value)
{
	if (p->specifier == 'd' || p->specifier == 'i')
		return(return_value += ft_print_long_nbr(p, ap));
	if (p->specifier == 'u')
		return_value += ft_print_long_unsigned_nbr(p, ap);
	return (return_value);
}

static int	ft_parse_h(t_parameter *p, va_list *ap, int return_value)
{
	return(return_value += ft_print_short_nbr(p, ap));
	return (return_value);
}

static int	ft_parse_hh(t_parameter *p, va_list *ap, int return_value)
{
	return(return_value += ft_print_nbr(p, ap));
}

int	ft_length_flags (t_parameter *p, va_list *ap)
{
	int	return_value;

	return_value = 0;
	if (!ft_strcmp("l", p->length))
		return_value += ft_parse_l(p, ap, return_value);
	if (!ft_strcmp("ll", p->length))
		return_value += ft_parse_ll(p, ap, return_value);
	if (!ft_strcmp("h", p->length))
		return_value += ft_parse_h(p, ap, return_value);
	if (!ft_strcmp("hh", p->length))
		return_value += ft_parse_hh(p, ap, return_value);
	return (return_value);
}
