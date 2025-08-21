/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add-subtract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:09:48 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:09:49 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
	Combines the values from two tuples and returns a new one
*/
t_tuple	add_tuples(t_tuple *orig, t_tuple *other)
{
	t_tuple			new_tuple;
	unsigned int	i;

	new_tuple = create_empty_tuple();
	i = 0;
	while (i < VEC_SIZE)
	{
		new_tuple.values[i] = orig->values[i] + other->values[i];
		i++;
	}
	return (new_tuple);
}

/*
	Subtracts the values from two tuples and returns a new one
*/
t_tuple	subtract_tuples(t_tuple *orig, t_tuple *other)
{
	t_tuple			new_tuple;
	unsigned int	i;

	new_tuple = create_empty_tuple();
	i = 0;
	while (i < VEC_SIZE)
	{
		new_tuple.values[i] = orig->values[i] - other->values[i];
		i++;
	}
	return (new_tuple);
}
