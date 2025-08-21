/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:55:19 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:09:08 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
Allocates (with malloc(3)) and returns a new node. The member variable
’content’ is initialized with the value of the parameter ’content’. The
variable ’next’ is initialized to NULL.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->next = NULL;
	list->content = content;
	return (list);
}
