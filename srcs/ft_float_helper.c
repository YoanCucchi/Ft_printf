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

char	*f_join(unsigned long long decimal, unsigned long long trunc)
{
	char	*s1;
	char	*s2;
	char	*tmp;
	int		len;

	tmp = NULL;
	len = ft_strlen(s1);
	s1 = ft_unsigned_long_itoa(trunc);
	tmp = (char *)ft_memalloc(sizeof(char) * (len + 1));
	tmp = s1;
	tmp[len + 1] = '.';
	s2 = ft_unsigned_long_itoa(decimal);
	return(ft_strjoin(s1, s2));
}

char	*split_float(long double n, t_parameter *p)
{
	unsigned long long	amount;
	unsigned long long	trunc;
	unsigned long long	decimal;
	int					sign;
	long double			one_point;
	unsigned long long	test;
	char				*reverse;
	int					increment;

	sign = 1;
	if (n < 0)
		sign = -1;
	n *= sign;
	amount = set_amount(p);
	trunc = (unsigned long long)n;
	one_point = n - trunc;
	printf("one point = %Lf\n", one_point);
	decimal = one_point * amount;
	printf("decimal = %llu\n", decimal);
	test = one_point * (amount * 10);
	printf("test = %llu\n", test);
	reverse = ft_itoa(test);
	reverse = ft_strduprev(reverse);
	printf("reverse = %s\n", reverse);
	increment = ft_atoi(reverse) / amount;
	printf("increment = %d\n", increment);
	if (increment >= 5)
		decimal++;
	printf("decimal = %llu\n", decimal);
	printf("trunc = %llu\n", trunc);
	free(reverse);
	return(f_join(decimal, trunc));
}