/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:21:27 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 15:22:39 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
	Counts the elements in the array
*/
int	ft_count_array(char **array)
{
	int	count;

	if (!array)
		return (0);
	count = -1;
	while (array[++count])
		;
	return (count);
}
