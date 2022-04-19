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
#include <stdio.h>

void parameter_print(t_parameter p)
{
	printf("minus = %d\n", p.minus);
	printf("plus = %d\n", p.plus);
	printf("width = %d\n", p.width);
	printf("precision = %d\n", p.precision);
	printf("specifier = %c\n", p.specifier);
	printf("zero = %d\n", p.zero);
	printf("dot = %d\n", p.dot);
	printf("space = %d\n", p.space);
	printf("sharp = %d\n", p.sharp);
	printf("neg_prec = %d\n", p.neg_prec);
}

t_parameter	ft_all_to_0(void)
{
	t_parameter	newparameter;

	newparameter.minus = 0;
	newparameter.plus = 0;
	newparameter.width = 0;
	newparameter.precision = 0;
	newparameter.specifier = 0;
	newparameter.zero = 0;
	newparameter.dot = 0;
	newparameter.space = 0;
	newparameter.sharp = 0;
	newparameter.neg_prec = 0;
	return (newparameter);
}