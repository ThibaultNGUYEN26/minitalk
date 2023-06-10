/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:48:53 by thibnguy          #+#    #+#             */
/*   Updated: 2023/06/10 17:50:35 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	ft_skip_sig_id(int sig_id)
{
	(void)sig_id;
}

static void	ft_send_char(int pid, unsigned char c)
{
	int		i;

	i = 8;
	while (i--)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
		usleep(200);
	}
}

static void	ft_send_msg(int pid, char *msg)
{
	while (*msg)
	{
		ft_send_char(pid, (unsigned char) *msg);
		msg++;
	}
	ft_send_char(pid, '\n');
	ft_send_char(pid, '\0');
}

static void	ft_msg_sent(int sig_id)
{
	(void)sig_id;
	ft_printf(GREEN "\n[INFO]" EOC ": ");
	ft_printf(YELLOW "Message received !\n" EOC);
}

int	main(int argc, char *argv[])
{
	unsigned int	pid;

	if (argc != 3)
	{
		ft_printf(RED "[ERROR]" EOC ": ");
		ft_printf(YELLOW "./client [server-pid] [message]\n" EOC);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, ft_msg_sent);
	signal(SIGUSR2, ft_skip_sig_id);
	if (!ft_check_pid(pid))
	{
		ft_printf(RED "[ERROR]" EOC ": " YELLOW "Unknown PID\n" EOC);
		return (1);
	}
	ft_send_msg(pid, argv[2]);
	return (0);
}
