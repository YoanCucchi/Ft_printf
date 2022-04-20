/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:38:10 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/15 15:38:11 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_str(t_parameter p, va_list args)
{
	char	*string;
	int		i;

	i = 0;
	string = va_arg(args, char *);
	if (!string)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (string[i])
		ft_print_char(string[i++]);
	return (i);
}
