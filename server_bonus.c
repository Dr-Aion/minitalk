/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 01:07:21 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/20 20:31:45 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int		bit;
	static char		c;
	static pid_t	client;

	(void)context;
	if (bit == 0)
		client = info->si_pid;
	if (sig == SIGUSR1)
		c |= (0x80 >> bit);
	else if (sig == SIGUSR2)
		c &= ~(0x80 >> bit);
	bit++;
	if (bit == CHAR_BIT)
	{
		bit = 0;
		if (c == '\0')
		{
			write(STDOUT_FILENO, "\n", 1);
			my_kill_func(client, SIGUSR2);
		}
		else
			write(STDOUT_FILENO, &c, 1);
		c = 0;
	}
	my_kill_func(client, SIGUSR1);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("pid = %d\n", pid);
	my_signal_func(SIGUSR1, signal_handler, true);
	my_signal_func(SIGUSR2, signal_handler, true);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
