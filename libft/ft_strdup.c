/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoldagu <amoldagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:18:48 by amoldagu          #+#    #+#             */
/*   Updated: 2025/01/04 19:59:44 by amoldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	n;

	n = ft_strlen(s1) + 1;
	ptr = (char *)malloc(n * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	else
	{
		ft_strlcpy(ptr, s1, n + 1);
		return (ptr);
	}
}
