/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:35:54 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/12 16:36:36 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;

	str = NULL;
	if (!str)
	{
		write(1, "(null)", 6);
		return(6);
	}
	i = 0;
	while(str[i])
		write(1, &str[i++], 1);
	return(i);
}

int	ft_print_ptr(unsigned long long ptr)
{
	return(1);
}