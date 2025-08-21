/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:31:42 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:09:43 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
Outputs the string ’s’ to the given file descriptor
followed by a newline.
*/
void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
