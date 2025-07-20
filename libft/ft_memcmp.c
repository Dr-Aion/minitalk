/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:19 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/01/03 18:47:53 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char			*ptr1;
	char			*ptr2;
	unsigned char	c1;
	unsigned char	c2;
	size_t			i;

	i = 0;
	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	while (i < n)
	{
		c1 = ptr1[i];
		c2 = ptr2[i];
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}
