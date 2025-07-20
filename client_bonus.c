/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 01:07:24 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/20 20:29:50 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_flag;

void	ack_handler(int signal)
{
	(void)signal;
	g_flag = READY;
}

void	end_handler(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "Message received.", 18);
	exit(EXIT_SUCCESS);
}

void	send_char(char c, pid_t server)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0x80 >> bit))
			my_kill_func(server, SIGUSR1);
		else
			my_kill_func(server, SIGUSR2);
		bit++;
		usleep(100);
		while (g_flag == BUSY)
			usleep(300);
		g_flag = BUSY;
	}
}

int	main(int ac, char **argv)
{
	pid_t	pid_server;
	char	*message;

	g_flag = BUSY;
	if (ac != 3)
	{
		write(STDERR_FILENO, "Usage: ./client <PID> <message>\n", 33);
		exit(EXIT_FAILURE);
	}
	pid_server = ft_atoi(argv[1]);
	message = argv[2];
	my_signal_func(SIGUSR1, ack_handler, false);
	my_signal_func(SIGUSR2, end_handler, false);
	while (*message)
	{
		send_char(*message, pid_server);
		message++;
	}
	send_char('\0', pid_server);
	usleep(200);
	return (EXIT_SUCCESS);
}
