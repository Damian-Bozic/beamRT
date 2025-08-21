/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:18:02 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:10:43 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*
Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
specified in ’set’ removed from the beginning and the end of the string.

Quits if either parameter is missing.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	while (j > 0 && is_in_set(s1[j], set))
		j--;
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	result = malloc((j - i) + 2);
	if (!result)
		return (NULL);
	ft_strlcpy(result, (char *)&s1[i], (j - i) + 2);
	return (result);
}
