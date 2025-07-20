/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:42:01 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/01/11 12:13:24 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*overflow(void)
{
	char	*ptr;

	ptr = (char *)malloc(1 * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	if (ptr)
		ptr[0] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	j;

	if (!s)
		return (NULL);
	else
	{
		if (start >= ft_strlen(s))
			return (overflow());
		if (len > ft_strlen(s) - start)
			len = ft_strlen(s) - start;
		if (len + 1 < len)
			return (NULL);
		ptr = (char *)malloc((len + 1) * sizeof(char));
		if (ptr == NULL)
			return (NULL);
		j = 0;
		while (start < ft_strlen(s) && j < len)
			ptr[j++] = s[start++];
		ptr[j] = '\0';
		return (ptr);
	}
}
