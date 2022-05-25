/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:33:48 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/25 13:33:49 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_strduprev(char *s1)
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
	return (dup);
}

static char	*dtoa(double n, t_parameter *p)
{
	int			i;
	int			test;
	char		arr[24];
	char		decimals[p->precision];
	unsigned long long	k;
	double	j;

	i = 0;
	k = (unsigned long long)n;
	ft_bzero(arr, 24);
	ft_bzero(decimals, p->precision);
	if (n < 0)
		k = k * -1;
	arr[i] = k % 10 + '0';
	i++;
	//this is k : 4256$
	// j : 0.444600$
	j = n - k;
	while (k / 10 > 0)
	{
		// printf("this is k : %llu\n", k);
		k = k / 10;
		arr[i] = (k % 10 + '0');
		i++;
	}
	while (p->precision-- > 0)
	{
		// printf("this is j : %f\n", j);
		j = j * 10;
	}
	printf(" j : %f\n", j);
	test = (int)j;
	printf("test : %d\n", test);
	i = 0;
	k = (long long)j;
	printf("HERE IS THE K : %lld\n", k);
	while (k / 10 > 0)
	{
		// printf("this is k : %lld\n", k);
		k = k / 10;
		decimals[i] = (k % 10 + '0');
		i++;
	}
	printf("decimals : %s\n", decimals);
	// check le moins avant le return
	if (n < 0)
		arr[i] = '-';
	return (ft_strduprev(arr));
}

static void	ft_len_zero_handling_float(t_parameter *p, double n)
{
	p->len = 1;
	n = n + 1;
	return ;
}

int	ft_print_float(t_parameter *p, va_list *ap)
{
	double	n;
	char	*nbr;

// precision = nbr of decimal to be printed
	n = va_arg(*ap, double);
	printf("n = %f\n", n);
	if (!p->precision)
		p->precision = 6;
	nbr = dtoa(n, p);
	printf("nbr = %s\n", nbr);
	p->len = 0;
	ft_len_zero_handling_float(p, n);
	return (0);
}
