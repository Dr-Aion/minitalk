/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 04:54:02 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/20 20:32:32 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig)
{
	static int	bit;
	static char	c;

	if (sig == SIGUSR1)
		c |= (0x80 >> bit);
	else if (sig == SIGUSR2)
		c &= ~(0x80 >> bit);
	bit++;
	if (bit == CHAR_BIT)
	{
		if (c == '\0')
			write(STDOUT_FILENO, "\n", 1);
		else
			write(STDOUT_FILENO, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("pid = %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
