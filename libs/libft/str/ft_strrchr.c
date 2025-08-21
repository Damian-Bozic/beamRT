/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:01:54 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:10:38 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *string, char c)
{
	int		len;
	char	*str;

	str = (char *)string;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == c)
			return (&str[len]);
		len--;
	}
	return (NULL);
}
