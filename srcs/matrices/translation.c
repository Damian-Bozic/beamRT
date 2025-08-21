/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:11:24 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:11:24 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
	Muliplies all a tuple's values by a scalar
*/
t_tuple	scale_tuple(t_tuple *orig, float scalar)
{
	t_tuple			new_tuple;
	unsigned int	i;

	new_tuple = create_empty_tuple();
	i = 0;
	while (i < VEC_SIZE)
	{
		new_tuple.values[i] = orig->values[i] * scalar;
		i++;
	}
	return (new_tuple);
}

t_matrix	translation(float x, float y, float z)// or vector?
{
	t_matrix	result;

	result = identity_matrix();
	result.vals[0][3] = x;
	result.vals[1][3] = y;
	result.vals[2][3] = z;
	return (result);
}

t_matrix	scaling(float x, float y, float z)// or vector?
{
	t_matrix	result;

	result = identity_matrix();
	result.vals[0][0] = x;
	result.vals[1][1] = y;
	result.vals[2][2] = z;
	return (result);
}
