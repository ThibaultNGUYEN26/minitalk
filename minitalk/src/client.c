/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:48:53 by thibnguy          #+#    #+#             */
/*   Updated: 2023/01/05 17:39:29 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/**
 * La fonction ft_receive_message permet de fermer le programme
 * a la reception d'un signal SIGUSR1.
 *
 * \param	sig_id	id du signal
 */
static void	ft_receive_message(int sig_id)
{
	(void) sig_id;
}

/**
 * La fonction ft_send_char permet d'envoyer un caractere unique via
 * les signaux SIGUSR1 et SIGUSR2.
 *
 * \param	pid	Le pid du server cible.
 * \param	c	Le caractere a envoyer.
 */
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

/**
 * La fonction ft_send_message envoie a un processus (via son pid)
 * une chaine de caractere. Les caracteres de cette chaine sont
 * lus bit a bit, et envoye un par un.
 *
 * \param	pid		Le pid du processus destination.
 * \param	message	La chaine de caracteres a envoyer.
 */
static void	ft_send_message(int pid, char *message)
{
	while (*message)
	{
		ft_send_char(pid, (unsigned char) *message);
		message++;
	}
	ft_send_char(pid, '\n');
	ft_send_char(pid, '\0');
}

static int	ft_verify_pid(int pid)
{
	int	i;

	i = 8;
	while (i-- && kill(pid, SIGUSR1) == 0)
	{
		pause();
		usleep(200);
	}
	return (i == -1);
}

int	main(int ac, char **av)
{
	unsigned int	pid;

	if (ac != 3)
	{
		ft_printf("Usage: ./client [server-pid] [message]\n");
		return (EXIT_ERROR);
	}
	pid = ft_atoi(av[1]);
	signal(SIGUSR2, ft_receive_message);
	if (!ft_verify_pid(pid))
	{
		ft_printf("Invalid PID\n");
		return (EXIT_ERROR);
	}
	ft_send_message(pid, av[2]);
	return (EXIT_SUCCESS);
}
