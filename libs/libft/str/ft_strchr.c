/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:58:02 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:10:04 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *string, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)string;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (!c)
		return (&str[i]);
	return (NULL);
}
