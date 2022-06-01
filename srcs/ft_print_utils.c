/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:35:58 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/15 15:36:06 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	is_it_double_specifier(char *str, char *tmp, int i)
{
	if (str[i] == 'l' && str[i + 1] == 'l')
	{
		i++;
		tmp[i] = str[i];
	}
	if (str[i] == 'h' && str[i + 1] == 'h')
	{
		i++;
		tmp[i] = str[i];
	}
}

int	who_is_biggest_of_2(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	who_is_biggest_of_3(int a, int b, int c)
{
	if (a >= b && a >= c)
		return (a);
	else if (b >= a && b >= c)
		return (b);
	else
		return (c);
}

void	minus_flag(t_parameter *p, long long n)
{
	if (n == 0 && p->dot)
		p->len = 0;
	if (p->plus || n < 0)
		p->highest_value++;
	// if (p->specifier == 'p' && p->highest_value + 3 > p->len && n != 0)
	// {
	// 	printf("here");
	// 	// p->highest_value--;
	// }
	if (p->width > p->precision && p->width > p->len)
		while (p->highest_value-- > who_is_biggest_of_2(p->precision, p->len))
			p->return_value += ft_print_char(' ');
}
