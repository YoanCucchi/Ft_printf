/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:38:06 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/15 15:38:06 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_nbr(t_parameter *p, va_list *ap)
{
	int		n;
	int		len;
	char	*nbr;

	n = va_arg(*ap, int);
	nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	ft_len_zero_handling(p, n, len);
	if (!p->precision && !p->width && n == 0 && p->dot)
	{
		free(nbr);
		return (0);
	}
	else if (nbr[0] == '-')
		p->return_value += write(1, nbr + 1, --len);
	else
		p->return_value += write(1, nbr, len);
	len = ft_strlen(nbr);
	if (p->minus)
		minus_flag(p, n, len);
	free(nbr);
	return (0);
}

int	ft_print_short_nbr(t_parameter *p, va_list *ap)
{
	int		len;
	char	*nbr;
	short	n;

	n = va_arg(*ap, int);
	nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	ft_len_zero_handling(p, n, len);
	if (!p->precision && !p->width && n == 0 && p->dot)
	{
		free(nbr);
		return (0);
	}
	else if (nbr[0] == '-')
		p->return_value += write(1, nbr + 1, --len);
	else
		p->return_value += write(1, nbr, len);
	len = ft_strlen(nbr);
	if (p->minus)
		minus_flag(p, n, len);
	free(nbr);
	return (0);
}

int	ft_print_long_nbr(t_parameter *p, va_list *ap)
{
	int		len;
	char	*nbr;
	long	n;

	n = va_arg(*ap, long);
	nbr = ft_long_itoa(n);
	len = ft_strlen(nbr);
	ft_len_zero_handling(p, n, len);
	if (!p->precision && !p->width && n == 0 && p->dot)
	{
		free(nbr);
		return (0);
	}
	else if (nbr[0] == '-')
		p->return_value += write(1, nbr + 1, --len);
	else
		p->return_value += write(1, nbr, len);
	len = ft_strlen(nbr);
	if (p->minus)
		minus_flag(p, n, len);
	free(nbr);
	return (0);
}

int	ft_print_long_long_nbr(t_parameter *p, va_list *ap)
{
	int					len;
	char				*nbr;
	unsigned long long	n;

	n = va_arg(*ap, long long);
	nbr = ft_long_itoa(n);
	len = ft_strlen(nbr);
	ft_len_zero_handling(p, n, len);
	if (!p->precision && !p->width && n == 0 && p->dot)
	{
		free(nbr);
		return (0);
	}
	else if (nbr[0] == '-')
		p->return_value += write(1, nbr + 1, --len);
	else
		p->return_value += write(1, nbr, len);
	len = ft_strlen(nbr);
	if (p->minus)
		minus_flag(p, n, len);
	free(nbr);
	return (0);
}

int	ft_print_char_nbr(t_parameter *p, va_list *ap)
{
	int			len;
	char		*nbr;
	signed char	n;

	n = va_arg(*ap, int);
	nbr = ft_long_itoa(n);
	len = ft_strlen(nbr);
	ft_len_zero_handling(p, n, len);
	if (!p->precision && !p->width && n == 0 && p->dot)
	{
		free(nbr);
		return (0);
	}
	else if (nbr[0] == '-')
		p->return_value += write(1, nbr + 1, --len);
	else
		p->return_value += write(1, nbr, len);
	len = ft_strlen(nbr);
	if (p->minus)
		minus_flag(p, n, len);
	free(nbr);
	return (0);
}
