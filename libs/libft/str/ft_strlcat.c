/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:40:02 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:10:15 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
Appends the NUL-terminated string src to the end of dst. It will append at
most size - strlen(dst) - 1 bytes, NUL-terminating the result.

Quits if size is 0 or dst is already longer than size.

*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	d_len;

	s_len = ft_strlen(src);
	if (0 == size)
		return (s_len);
	d_len = ft_strlen(dst);
	if (d_len >= size)
		return (s_len + size);
	dst += d_len;
	size -= d_len;
	while (*src && --size)
		*dst++ = *src++;
	*dst = '\0';
	return (s_len + d_len);
}
