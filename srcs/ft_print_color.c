/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:39:43 by ycucchi           #+#    #+#             */
/*   Updated: 2022/06/10 15:39:44 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
# define blue "\e[1;34m"
# define normal "\x1B[0m"

static char	*find_color(char *str)
{
	if (ft_strnstr(str, "{blue}", 6) == 0)
		return(blue);
	// else if (ft_strncmp(str, "{green}", 7) == 0)
	// else if (ft_strncmp(str, "{red}", 5) == 0)
	// else if (ft_strncmp(str, "{yellow}", 8) == 0)
	// else if (ft_strncmp(str, "{blue2}", 7) == 0)
	else
		return (NULL);
}

void	ft_print_color(char *str)
{
// ft_printf("{blue}%s", "yooo");
char *test;
char *tmp;
printf("str avant = %s\n", str);
while (*str != '}')
	str++;
str++;
printf("str apres = %s\n", str);
test = find_color(str);
tmp = ft_strjoin(test, str);
ft_printf(tmp);
}
