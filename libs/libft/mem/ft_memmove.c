/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:28:42 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:09:29 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*start;
	unsigned char	*end;

	if (!dest && !src)
		return (NULL);
	start = (unsigned char *)src;
	end = (unsigned char *)dest;
	if (start < end && (start + n) > end)
		while (n--)
			end[n] = start[n];
	else
		while (n--)
			*(end++) = *(start++);
	return (dest);
}
