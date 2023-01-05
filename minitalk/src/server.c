/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:48:52 by thibnguy          #+#    #+#             */
/*   Updated: 2023/01/05 17:50:53 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/**
 * Execute lors de la reception dun SIGUSR1 ou SIGUSR2,
 * la fonction ft_catch_signal interprete les signaux entrants
 * et les traduit en caracteres consecutifs qu'elle affiche.
 *
 * \param	sig_id	L'id du signal recu.
 */
static void	ft_catch_signal(int sig_id, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				i;

	(void) context;
	i += 1;
	c |= sig_id == SIGUSR2;
	if (i < 8)
		c <<= 1;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	usleep(200);
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_catch_signal;
	ft_printf("Server PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
