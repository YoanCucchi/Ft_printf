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
