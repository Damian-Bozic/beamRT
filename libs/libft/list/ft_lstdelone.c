/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:50:27 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:08:54 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
Takes as a parameter a node and frees the memory of the node’s content using
the function ’del’ given as a parameter and free the node. The memory of
’next’ must not be freed.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
