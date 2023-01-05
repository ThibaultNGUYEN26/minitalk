/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:44:48 by thibnguy          #+#    #+#             */
/*   Updated: 2023/01/05 17:52:41 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdarg.h>
# include <sys/types.h>
# include <stdio.h>

# define EXIT_SUCCESS		0
# define EXIT_ERROR			1
# define MESSAGE_SENT		0
# define MESSAGE_RECEIVED	1

int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *s, ...);
int		ft_intlen(long n, char *base);

#endif
