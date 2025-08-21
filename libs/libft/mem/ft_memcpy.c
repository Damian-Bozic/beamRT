/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:24:55 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:09:26 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	if (!dest && !src)
		return (NULL);
	s = (char *)src;
	d = (char *)dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}
