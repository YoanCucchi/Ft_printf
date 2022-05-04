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
# define FLAGS "#0-+ "
# define WIDTH "0123456789"
# define LENGTH "hlL"
# define LENGTH_DISPATCH "diouxX"
# define HEXALOWCASE "0123456789abcdef"
# define HEXAUPCASE "0123456789ABCDEF"

/*
** Headers
*/

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h> // A VIRER !!!!!

/*
** Prototypes
*/

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
	char	specifier;
	int		zero;
	int		dot;
	int		space;
	int		sharp;
	char	*format;
	char	*length;
}			t_parameter;

/*
** main.c
*/

int			ft_printf(const char *str, ...);
int			conversion_type(t_parameter p, va_list *ap);

/*
** ft_print_utils.c
*/

int			ft_print_char(int c);
int			ft_putnstr(char const *s, int n);
void		is_it_double_specifier(char *str, t_parameter p, char *tmp, int i);
void		param_free(t_parameter p);

/*
** ft_print_str.c
*/

int			ft_print_str(t_parameter p, va_list *ap);
int			ft_print_c(va_list *ap);
int			ft_print_percent(t_parameter p);

/*
** ft_print_nbr.c
*/

int			ft_print_nbr(t_parameter p, va_list *ap);
int			ft_print_unsigned_nbr(t_parameter p, va_list *ap);
int			ft_print_long_nbr(t_parameter p, va_list *ap);
int			ft_print_long_unsigned_nbr(t_parameter p, va_list *ap);

/*
** ft_print_hex.c
*/

int			ft_print_hex(t_parameter p, va_list *ap);
int			ft_print_hex_hh(t_parameter p, va_list *ap);
int			ft_print_p(t_parameter p, va_list *ap);
int			ft_print_short_nbr(t_parameter p, va_list *ap);

/*
** ft_parse.c
*/

int			ft_parse(char *str, va_list *ap);

/*
** ft_initialize_parameter.c
*/

void		parameter_print(t_parameter p); // A VIRER !!!
t_parameter	ft_all_to_0(void);

/*
** ft_length_flags.c
*/

int			ft_length_flags (t_parameter p, va_list *ap);

/*
** colors.c
*/


#endif
