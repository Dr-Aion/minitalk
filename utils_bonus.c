/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 03:12:45 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/20 20:25:55 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	my_signal_func(int sig, void *signal_handler, bool flag_siginfo)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	if (flag_siginfo)
	{
		sa.sa_sigaction = signal_handler;
		sa.sa_flags = SA_SIGINFO;
	}
	else
		sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(sig, &sa, NULL) < 0)
	{
		perror("Sigaction failed");
		exit(EXIT_FAILURE);
	}
}

void	my_kill_func(pid_t pid, int sig)
{
	if (kill(pid, sig) < 0)
	{
		perror("Could not send the signal, kill() failed");
		exit(EXIT_FAILURE);
	}
}
