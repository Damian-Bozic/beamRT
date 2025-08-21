/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:57:44 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:10:01 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	count_letters(char const *s, char c)
{
	int	letters;

	letters = 0;
	if (*s == '\'')
	{
		s++;
		c = '\'';
		letters++;
	}
	while (*s && *s++ != c)
		letters++;
	if (c == '\'')
		letters++;
	return (letters);
}

static size_t	count_words(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			s += count_letters(s, c);
			words++;
		}
		else
			s++;
	}
	return (words);
}

static void	*return_empty(char **words)
{
	size_t	i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
	return (NULL);
}

static char	**fill_array(char **words, const char *str, char c)
{
	size_t	i;
	size_t	letter_count;
	char	*new_str;

	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			letter_count = count_letters(str, c);
			new_str = ft_substr(str, 0, letter_count);
			if (!new_str)
				return (return_empty(words));
			words[i] = ft_strtrim(new_str, "'");
			free(new_str);
			str += letter_count;
			i++;
		}
		else
			str++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	words = malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	words = fill_array(words, s, c);
	if (words)
		words[word_count] = NULL;
	return (words);
}
