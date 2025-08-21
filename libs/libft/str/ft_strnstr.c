/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:17:58 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:10:32 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = (char *)big;
	if (!little[0] || (!str && 0 == len))
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] && little[j] == str[i + j])
			j++;
		if ((i + j) > len)
			return (NULL);
		if (!little[j])
			return (&str[i]);
		i++;
	}
	return (NULL);
}
