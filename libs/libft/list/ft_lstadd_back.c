/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:40:23 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:08:46 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
Adds the node ’new’ at the end of the list.

If the list is empty is becomes new.
Otherwise get the last item and set its next to new
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
