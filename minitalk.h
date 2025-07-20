/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 02:08:45 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/20 05:18:46 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

# include "libft/libft.h"

# define BUSY	0
# define READY	1

void	my_signal_func(int sig, void *signal_handler, bool flag_siginfo);
void	my_kill_func(pid_t pid, int sig);

#endif