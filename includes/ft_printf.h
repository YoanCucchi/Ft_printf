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
# define OCTAL "012345678"

/*
** Headers
*/

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdio.h> // A VIRER !!!!!

/*
** Prototypes
*/

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
	int		return_value;
	int		highest_value;
}			t_parameter;

/*
** main.c
*/

int			ft_printf(const char *str, ...);
int			conversion_type(t_parameter *p, va_list *ap);

/*
** ft_print_utils.c
*/

void		is_it_double_specifier(char *str, char *tmp, int i);
int			who_is_biggest_of_2(int a, int b);
int			who_is_biggest_of_3(int a, int b, int c);
void		ft_len_zero_handling(t_parameter *p, long long n, int len);
void		minus_flag(t_parameter *p, long long n, int len);

/*
** ft_print_str.c
*/

int			ft_print_str(t_parameter *p, va_list *ap);
int			ft_print_c(t_parameter *p, va_list *ap);
int			ft_print_percent(t_parameter *p);

/*
** ft_print_nbr.c
*/

int			ft_print_nbr(t_parameter *p, va_list *ap);
int			ft_print_short_nbr(t_parameter *p, va_list *ap);
int			ft_print_long_nbr(t_parameter *p, va_list *ap);
int			ft_print_long_long_nbr(t_parameter *p, va_list *ap);
int			ft_print_char_nbr(t_parameter *p, va_list *ap);

/*
** ft_print_unbr.c
*/

int			ft_print_unsigned_nbr(t_parameter *p, va_list *ap);
int			ft_print_ushort_nbr(t_parameter *p, va_list *ap);
int			ft_print_ulong_nbr(t_parameter *p, va_list *ap);
int			ft_print_uchar_nbr(t_parameter *p, va_list *ap);

/*
** ft_print_hex.c
*/

int			ft_print_hex(t_parameter *p, va_list *ap);
int			ft_print_p(t_parameter *p, va_list *ap);

/*
** ft_print_flag_hex.c
*/

int			ft_print_char_hex(t_parameter *p, va_list *ap);
int			ft_print_short_hex(t_parameter *p, va_list *ap);
int			ft_print_long_hex(t_parameter *p, va_list *ap);
int			ft_print_long_long_hex(t_parameter *p, va_list *ap);

/*
** ft_parse.c
*/

int			ft_parse(char *str, va_list *ap, t_parameter *p);

/*
** ft_initialize_parameter.c
*/

void		parameter_print(t_parameter *p); // A VIRER !!!
void		ft_init_params(t_parameter *p);
void		ft_reset_params(t_parameter *p);
t_parameter	*memalloc_struct(t_parameter *p);
void		param_free(t_parameter *p);

/*
** ft_length_flags.c
*/

int			ft_length_flags(t_parameter *p, va_list *ap);

/*
** ft_print_octal.c
*/

int			ft_print_octal(t_parameter *p, va_list *ap);
int			ft_print_long_o(t_parameter *p, va_list *ap);
int			ft_print_llong_o(t_parameter *p, va_list *ap);
int			ft_print_short_o(t_parameter *p, va_list *ap);
int			ft_print_char_octal(t_parameter *p, va_list *ap);

/*
** ft_octal_helper.c
*/

int			ft_recursive_octal(t_parameter *p, size_t n, size_t iteration);
void		ft_len_zero_handling_octal(t_parameter *p, long long n, int len);

/*
** ft_hex_helper.c
*/

int			ft_recursive_hex(t_parameter *p, size_t n, size_t iteration);
void		ft_len_zero_handling_hex(t_parameter *p, long long n, int len);
void		ft_len_zero_handling_p(t_parameter *p, long long n, int len);

/*
** colors.c
*/

#endif
