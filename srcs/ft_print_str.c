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
	int		return_value;

//	printf("--------------------------------------------------------------\n");
//	parameter_print(p);
//	printf("--------------------------------------------------------------\n");
	string = va_arg(args, char *);
	if (!string)
		string = "(null)";
	return_value = 0;
	if (!p.dot || p.precision > (int)ft_strlen(string) || p.precision < 0)
		p.precision = ft_strlen(string);
	if (p.width - p.precision > 0)
		while (p.width-- - p.precision > 0)
				return_value += ft_print_char(' ');
	return_value += ft_putnstr(string, p.precision);
	return (return_value);
}
