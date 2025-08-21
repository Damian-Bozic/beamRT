/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:55:50 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:09:05 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
Iterates the list ’lst’ and applies the function ’f’ on the content of each
node. Creates a new list resulting of the successive applications of the
function ’f’. The ’del’ function is used to delete the content of a node if
needed.

If any of the parameters are missing, return.
For every lst item, call the f function on it, create a t_list from it.
If the new t_list is NULL, pass to del, clear the new list, and return NULL.
Otherwise, add all succeses to a new lst and return it.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*f_return;
	t_list	*f_node;
	t_list	*result;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		f_return = f(lst->content);
		f_node = ft_lstnew(f_return);
		if (!f_node)
		{
			del(f_return);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, f_node);
		lst = lst->next;
	}
	return (result);
}
