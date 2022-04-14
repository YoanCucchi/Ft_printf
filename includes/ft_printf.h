/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:17:40 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/12 11:49:21 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Headers
*/

#include "../libft/libft.h"
#include <stdarg.h>

/*
** Prototypes
*/

// typedef struct  s_parameter {
//	t_uchar 	flags;	//Store les flags
//	int			width; // taille de width
//	char		conv; // letter de conv
//	t_bool		upper;  // check si le flag est Upper case OK
//	int			precision; // taille dela precision
//	int 		char_to_skip; //  nombre de cahr to skip
//	char 		*sizePrefix; // Sizeprefix conv
//	int			size; // taille total de str
//}               t_parameter;

/*DISPACHT TABLE*/
/*FUNCTION IN DISPACHT FLAG ARRAY*/
//int	conversion_to_str(t_parameter *li, va_list ap);
//int	conversion_to_char(t_parameter *li, va_list ap);
//int	conversion_to_int(t_parameter *li, va_list ap);
// char *argtohexoroct(t_parameter *li, va_list ap);
// char *argtoptraddress(t_parameter *li, va_list ap);
// char *argtofloat(t_parameter *li, va_list ap);
// char *argto_u_int(t_parameter *li, va_list ap);

/*

typedef int (*dispachtFlags)(t_parameter *li, va_list ap);

static const dispachtFlags	funcFlagsArray[26] = {
	NULL,		//A
	NULL,		//B
	argtochar,	//C
	argtoint,	//D
	NULL,		//E
	NULL,		//F
	NULL,		//G
	NULL,		//H
	argtoint,	//I
	NULL,		//J
	NULL,		//K
	NULL,		//L
	NULL,//M
	NULL,//N
	NULL,//O
	NULL,//P
	NULL,//Q
	NULL,//R
	argtostr,	//S
	NULL,//T
	NULL,//U
	NULL,//V
	NULL,//W
	NULL,//X
	NULL,//Y
	NULL,//Z
};
*/

/*
** main.c
*/
int	ft_print_char(int c);
int	ft_printf(const char *str, ...);
int	conversion_type(va_list args, const char type);

/*
** ft_utils.c
*/

int	ft_print_str(char *str);
int	ft_print_ptr(void *ptr);
int	ft_print_nbr(signed int nb);
int	ft_print_percent(void);

#endif
