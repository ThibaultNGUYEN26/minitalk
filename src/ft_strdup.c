/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:47:00 by thibnguy          #+#    #+#             */
/*   Updated: 2023/02/08 11:47:29 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*dup;

	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}
