/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:53:35 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:08:52 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
Deletes and frees the given node and every successor of that node, using the
function ’del’ and free(3).Finally, the pointer to the list must be set to
NULL.

If the lst pointer, the list head, or the function is missing, return.
Loop through the lst, passing each node to the delone function.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
	lst = NULL;
}
