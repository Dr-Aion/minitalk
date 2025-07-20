/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 05:00:40 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/20 20:30:01 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, pid_t pid_server)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0x80 >> bit))
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		bit++;
		usleep(100);
	}
}

int	main(int ac, char **argv)
{
	pid_t	pid_server;
	char	*message;

	if (ac != 3)
	{
		write(STDERR_FILENO, "Usage: ./client <PID> <message>\n", 33);
		exit(EXIT_FAILURE);
	}
	pid_server = ft_atoi(argv[1]);
	message = argv[2];
	while (*message)
	{
		send_char(*message, pid_server);
		message++;
	}
	send_char('\0', pid_server);
	return (EXIT_SUCCESS);
}
