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

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnstr(char const *s, int n)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0' && n > 0)
		{
			ft_putchar(s[i]);
			i++;
			n--;
		}
	}
	return (i);
}

void	is_it_double_specifier(char *str, t_parameter p, char *tmp, int i)
{
	if (str[i] == 'l' && str[i + 1] == 'l')
	{
		i++;
		p.format++;
		tmp[i] = str[i];
	}
	if (str[i] == 'h' && str[i + 1] == 'h')
	{
		i++;
		p.format++;
		tmp[i] = str[i];
	}
}

void	param_free(t_parameter p)
{
	p.sharp = 0;
	p.zero = 0;
	p.minus = 0;
	p.plus = 0;
	p.space = 0;
	p.width = 0;
	p.dot = 0;
	p.precision = 0;
	p.specifier = 0;
	free(p.format);
	free(p.length);
}
