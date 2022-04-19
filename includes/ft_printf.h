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

# define SPECIFIERS "cspdiouxX%"
/*
** Headers
*/

#include "../libft/libft.h"
#include <stdarg.h>

/*
** Prototypes
*/




//%%
// #0-+ and space
// minimum field-width
// precision
// f with the following flags: l and L.
// diouxX with following flags: hh, h, l and ll.

typedef struct s_parameter
{
	int		minus;
	int		plus;
	int		width;
	int		precision;
	int		neg_prec;
	char	specifier;
	int		zero;
	int		dot;
	int		space;
	int		sharp;
}			t_parameter;

/*
** main.c
*/
int	ft_print_char(int c);
int	ft_printf(const char *str, ...);
int	conversion_type(t_parameter p, va_list args);

/*
** ft_print_utils.c
*/
int	ft_print_str(t_parameter p, va_list args);
int	ft_print_ptr(void *ptr);
int	ft_print_nbr(t_parameter p , va_list args);
int	ft_print_percent(void);

/*
** ft_parse.c
*/

int	ft_parse(char *str, va_list args);

/*
** ft_initialize_parameter.c
*/

void parameter_print(t_parameter p);
t_parameter	ft_all_to_0(void);

#endif
