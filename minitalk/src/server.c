/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:48:52 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/10 21:07:31 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

static void	ft_display_str(siginfo_t *info, char **str)
{
	if (*str != NULL && ft_strlen(*str) > 0)
	{
		ft_printf(BLUE "[MESSAGE]" EOC ": %s", *str);
		free(*str);
		*str = ft_strdup("");
		usleep(100);
		kill(info->si_pid, SIGUSR1);
	}
}

static void	ft_signal_handler(int sig_id, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				i;
	static char				*str;
	char					tmp[2];

	(void) context;
	i++;
	c |= (sig_id == SIGUSR2);
	if (i < 8)
		c <<= 1;
	else
	{
		tmp[0] = c;
		tmp[1] = '\0';
		if (!str)
			str = ft_strdup("");
		str = ft_strjoin(str, tmp);
		i = 0;
		c = 0;
		if (!tmp[0])
			ft_display_str(info, &str);
	}
	usleep(10);
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_signal_handler;
	ft_printf(GREEN "[INFO]" EOC ": ");
	ft_printf(YELLOW "Server PID " BLUE "%d\n" EOC, getpid());
	ft_printf(GREEN "[INFO]" EOC ": ");
	ft_printf(YELLOW "./client [server-PID] [message]\n\n" EOC);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
