/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:44:48 by thibnguy          #+#    #+#             */
/*   Updated: 2023/02/08 12:08:11 by thibnguy         ###   ########.fr       */
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

# define EOC "\033[0;0m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define BLUE "\033[0;36m"
# define WHITE "\033[0;37m"

int		ft_atoi(const char *nptr);
int		ft_check_pid(int pid);
int		ft_intlen(long n, char *base);
int		ft_printf(const char *s, ...);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *s);

#endif
