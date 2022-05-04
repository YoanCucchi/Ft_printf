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
void	parameter_print(t_parameter *p)
{
	printf("---------------------------------------------------------------\n");
	printf("sharp = %d\n", p->sharp);
	printf("zero = %d\n", p->zero);
	printf("minus = %d\n", p->minus);
	printf("plus = %d\n", p->plus);
	printf("space = %d\n", p->space);
	printf("width = %d\n", p->width);
	printf("dot = %d\n", p->dot);
	printf("precision = %d\n", p->precision);
	printf("format = %s\n", p->format);
	printf("length = %s\n", p->length);
	printf("tmp = %s\n", p->tmp);
	printf("specifier = %c\n", p->specifier);
	printf("---------------------------------------------------------------\n");
}

void	ft_all_to_0(t_parameter *p)
{
	p->sharp = 0;
	p->zero = 0;
	p->minus = 0;
	p->plus = 0;
	p->space = 0;
	p->width = 0;
	p->dot = 0;
	p->precision = 0;
	p->specifier = 0;
	p->format = NULL;
	p->length = NULL;
	p->tmp = NULL;
}
