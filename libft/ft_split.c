/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoldagu <amoldagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:33:37 by amoldagu          #+#    #+#             */
/*   Updated: 2025/01/11 14:46:37 by amoldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **result, int string_index)
{
	int	i;

	i = 0;
	while (i < string_index)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static void	vars_init(size_t *i, int *string_i, int *size, int *word_start)
{
	*i = 0;
	*string_i = 0;
	*size = 0;
	*word_start = -1;
}

static int	count_words(char const *s, char c)
{
	int		number_of_words;
	int		i;
	int		orig_i;

	number_of_words = 0;
	i = 0;
	orig_i = 0;
	while (s[i] != '\0')
	{
		while (s[i] && (s[i] != c))
			i++;
		while (s[i] && (s[i] == c))
			i++;
		if (orig_i < i)
		{
			number_of_words++;
			orig_i = i;
		}
	}
	return (number_of_words);
}

static char	*create_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	int		string_index;
	int		size;
	int		word_start;

	vars_init(&i, &string_index, &size, &word_start);
	result = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && word_start < 0)
			word_start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && word_start >= 0)
		{
			result[string_index] = create_word(s, word_start, i);
			if (!(result[string_index]))
				return (ft_free(result, string_index));
			word_start = -1;
			string_index++;
		}
		i++;
	}
	return (result);
}
