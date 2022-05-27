/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:50:38 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/27 11:50:39 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strduprev(char *s1)
{
	char	*dup;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	dup = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	len--;
	while (len >= 0)
	{
		dup[i] = s1[len];
		len--;
		i++;
	}
	dup[i] = '\0';
	free(s1);
	return (dup);
}

unsigned long long	set_amount(t_parameter *p)
{
	unsigned long long	amount;
	int					temp;

	temp = p->precision;
	amount = 10;
	while (--temp > 0)
		amount *= 10;
	return (amount);
}

char	*f_join(t_float f, char *nbr)
{
	char	*s1;
	char	*s2;

	s1 = ft_unsigned_long_itoa(f.trunc);
	s2 = ft_unsigned_long_itoa(f.decimal);
	s1[ft_strlen(s1)] = '.';
	nbr = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return(nbr);
}

t_float	split_float(long double n, t_parameter *p, t_float f)
{
	unsigned long long	amount;
	unsigned long long	test;
	int					sign;
	long double			one_point;
	char				*reverse;
	int					increment;

	sign = 1;
	if (n < 0)
		sign = -1;
	n *= sign;
	amount = set_amount(p);
	f.trunc = (unsigned long long)n;
	one_point = n - f.trunc;
	f.decimal = one_point * amount;
	test = one_point * (amount * 10);
	reverse = ft_itoa(test);
	reverse = ft_strduprev(reverse);
	increment = ft_atoi(reverse) / amount;
	if (increment >= 5)
		f.decimal++;
	free(reverse);
	if (!p->precision && p->dot)
	{
		if (f.decimal >= 5)
			f.trunc++;
	}
	return(f);
}