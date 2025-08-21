/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:53:05 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:10:27 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
Applies the function f to each character of the string s, passing its index
as the first argument and the character itself as the second. A new
string is created (using malloc(3)) to collect the results from the
successive applications of f.

Quits if either parameter is missing.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*result;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
