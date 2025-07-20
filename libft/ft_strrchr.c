/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:19:06 by amoldagu          #+#    #+#             */
/*   Updated: 2025/01/08 09:54:30 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	size_t	i;
	char	*last;
	size_t	len;

	last = NULL;
	ptr = (char *)s;
	len = ft_strlen(ptr);
	i = 0;
	while (i <= len)
	{
		if (ptr[i] == (unsigned char) c)
			last = &ptr[i];
		i++;
	}
	if (last != NULL)
		return (last);
	return (NULL);
}
