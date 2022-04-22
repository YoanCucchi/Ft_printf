/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_parameter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:13:48 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/15 15:13:52 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// A VIRER !!!
void	parameter_print(t_parameter p)
{
	printf("---------------------------------------------------------------\n");
	printf("sharp = %d\n", p.sharp);
	printf("zero = %d\n", p.zero);
	printf("minus = %d\n", p.minus);
	printf("plus = %d\n", p.plus);
	printf("space = %d\n", p.space);
	printf("width = %d\n", p.width);
	printf("dot = %d\n", p.dot);
	printf("precision = %d\n", p.precision);
	printf("format = %s\n", p.format);
	printf("length = %s\n", p.length);
	printf("specifier = %c\n", p.specifier);
	printf("---------------------------------------------------------------\n");
}

t_parameter	ft_all_to_0(void)
{
	t_parameter	newparameter;

	newparameter.sharp = 0;
	newparameter.zero = 0;
	newparameter.minus = 0;
	newparameter.plus = 0;
	newparameter.space = 0;
	newparameter.width = 0;
	newparameter.dot = 0;
	newparameter.precision = 0;
	newparameter.specifier = 0;
	newparameter.format = NULL;
	newparameter.length = malloc(sizeof(char) * 100);
	return (newparameter);
}
