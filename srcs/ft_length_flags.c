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

int	ft_length_flags (t_parameter p, va_list *ap)
{
	int	return_value;

	return_value = 0;
	if (!ft_strcmp("l", p.length))
		return_value += ft_print_nbr(p, ap);
	if (!ft_strcmp("ll", p.length))
		return_value += ft_print_nbr(p, ap);
	if (!ft_strcmp("h", p.length))
		return_value += ft_print_short_nbr(p, ap);
	if (!ft_strcmp("hh", p.length))
		return_value += ft_print_nbr(p, ap);
	return (return_value);
}
