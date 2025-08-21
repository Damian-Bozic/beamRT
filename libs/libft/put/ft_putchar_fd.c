/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:26:37 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:09:40 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
Outputs the character ’c’ to the given file descriptor.
*/
void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0 || c < 0)
		return ;
	write(fd, &c, 1);
}
