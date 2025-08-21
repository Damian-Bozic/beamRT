/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stringlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:22:06 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/01 16:05:24 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
	Frees all the strings in a list, and the list itself
*/
void	ft_free_stringlist(char **list)
{
	int	i;

	i = -1;
	while (list[++i])
		free(list[i]);
	free(list);
	list = NULL;
}
