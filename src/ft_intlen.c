/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:48:06 by thibnguy          #+#    #+#             */
/*   Updated: 2022/12/22 12:49:09 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_intlen(long n, char *base)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= ft_strlen(base);
		len++;
	}
	return (len);
}
