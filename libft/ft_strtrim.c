/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:39:56 by amoldagu          #+#    #+#             */
/*   Updated: 2025/01/07 12:11:23 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] != '\0')
	{
		if (ft_strchr(set, s1[start]) != NULL )
			start++;
		else
			break ;
	}
	return (start);
}

static size_t	str_end(char const *s1, char const *set, size_t start)
{
	size_t	end;

	end = ft_strlen(s1);
	while (end > start)
	{
		if (ft_strchr(set, s1[end - 1]) != NULL)
			end--;
		else
			break ;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	size;
	size_t	start;
	size_t	end;
	char	*ptr;

	if (!s1)
		return (NULL);
	i = 0;
	start = str_start(s1, set);
	end = str_end(s1, set, start);
	size = end - start + 1;
	ptr = (char *)malloc(size * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	else
	{
		while (start < end)
			ptr[i++] = s1[start++];
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}
