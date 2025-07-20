/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoldagu <amoldagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:28:23 by amoldagu          #+#    #+#             */
/*   Updated: 2025/01/11 13:46:56 by amoldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	return_number(const char *str, int sign)
{
	int	nbr;
	int	start;
	int	end;

	nbr = 0;
	start = 0;
	end = 0;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
		end++;
	}
	if (sign == 1 && ((end - start) > 19))
		nbr = -1;
	else if (sign == -1 && (end - start) > 19)
		nbr = 0;
	nbr = nbr * sign;
	while (!(*str >= '0' && *str <= '9'))
		str++;
	return (nbr);
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	return (return_number(str, sign));
}
