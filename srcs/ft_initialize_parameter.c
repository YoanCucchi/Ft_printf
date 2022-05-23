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
	printf("dot = %d\n", p->dot);
	printf("space = %d\n", p->space);
	printf("width = %d\n", p->width);
	printf("precision = %d\n", p->precision);
	printf("return_value = %d\n", p->return_value);
	printf("highest_value = %d\n", p->highest_value);
	printf("checked = %d\n", p->checked);
	printf("minus_check = %d\n", p->minus_check);
	printf("format = %s\n", p->format);
	printf("length = %s\n", p->length);
	printf("specifier = %c\n", p->specifier);
	printf("---------------------------------------------------------------\n");
}

t_parameter	*memalloc_struct(t_parameter *p)
{
	p = (t_parameter *)malloc(sizeof(t_parameter));
	if (!p)
		exit(EXIT_FAILURE);
	ft_init_params(p);
	return (p);
}

void	ft_init_params(t_parameter *p)
{
	p->sharp = 0;
	p->zero = 0;
	p->minus = 0;
	p->plus = 0;
	p->space = 0;
	p->dot = 0;
	p->width = 0;
	p->precision = 0;
	p->specifier = 0;
	p->return_value = 0;
	p->highest_value = 0;
	p->checked = 0;
	p->minus_check = 0;
	p->format = NULL;
	p->length = NULL;
}

void	ft_reset_params(t_parameter *p)
{
	p->sharp = 0;
	p->zero = 0;
	p->minus = 0;
	p->plus = 0;
	p->dot = 0;
	p->space = 0;
	p->width = 0;
	p->precision = 0;
	p->specifier = 0;
	p->highest_value = 0;
	p->checked = 0;
	p->minus_check = 0;
	p->format = NULL;
	p->length = NULL;
}

void	param_free(t_parameter *p)
{
	p->sharp = 0;
	p->zero = 0;
	p->minus = 0;
	p->plus = 0;
	p->space = 0;
	p->width = 0;
	p->precision = 0;
	p->specifier = 0;
	p->highest_value = 0;
	p->checked = 0;
	p->minus_check = 0;
	free(p->length);
}
