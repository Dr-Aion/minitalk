/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:15:28 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/01/07 23:38:14 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_num_digits(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		num_digits;
	int		i;

	num_digits = find_num_digits(n);
	i = 0;
	if (n < 0)
		i++;
	num_digits = num_digits + i;
	s = (char *)malloc((num_digits + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[0] = '-';
	s[num_digits] = '\0';
	while ((num_digits - 1) >= i)
	{
		s[num_digits - 1] = ft_abs(n % 10) + '0';
		n = n / 10;
		num_digits--;
	}
	return (s);
}
