/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:45:11 by thibnguy          #+#    #+#             */
/*   Updated: 2022/12/22 13:07:40 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static size_t	ft_putstr(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	else
		return (write(1, "(null)", 6), 6);
	return (ft_strlen(s));
}

static size_t	ft_putnbr_base(long long nb, char *base)
{
	int			sign;

	sign = 0;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		sign = 1;
	}
	if (nb >= (long long)10)
	{
		ft_putnbr_base(nb / 10, base);
		ft_putnbr_base(nb % 10, base);
	}
	else
		ft_putchar(base[nb]);
	if (nb == 0)
		return (sign + ft_intlen(nb, base) + 1);
	return (sign + ft_intlen(nb, base));
}

static int	ft_write(char s, va_list ap)
{
	if (s == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (s == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (s == 'd')
		return (ft_putnbr_base(va_arg(ap, int), "0123456789"));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	int		counter;
	va_list	ap;

	i = -1;
	counter = 0;
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] != '%')
			counter += write(1, &s[i], 1);
		else
		{
			i++;
			counter += ft_write(s[i], ap);
		}
	}
	va_end(ap);
	return (counter);
}
