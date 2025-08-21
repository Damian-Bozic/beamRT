/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:50:15 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:10:30 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	while (i < n)
	{
		if (!s1[i] || s1[i] != s2[i])
		{
			diff = (unsigned char)s1[i] - (unsigned char)s2[i];
			if (diff > 0)
				return (1);
			if (diff < 0)
				return (-1);
			return (0);
		}
		i++;
	}
	return (0);
}
