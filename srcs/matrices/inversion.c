/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inversion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:11:09 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:11:09 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
	Swaps polarity on all a tuple's values
*/
t_tuple	invert_tuple(t_tuple *orig)
{
	t_tuple			new_tuple;
	unsigned int	i;

	new_tuple = create_empty_tuple();
	i = 0;
	while (i < VEC_SIZE)
	{
		new_tuple.values[i] = 0 - orig->values[i];
		i++;
	}
	return (new_tuple);
}

/*
	Checks whether a matrix can be inverted
*/
int	is_invertible(t_matrix *matrix)
{
	float	det;

	det = determinant(matrix);
	return (det != 0.0f);
}

/*
	Inverts a matrix
*/
t_matrix	invert(t_matrix *matrix)
{
	t_matrix		result;
	unsigned int	i;
	unsigned int	j;
	float			cf;

	if (0 == is_invertible(matrix))
		return (*matrix);
	result = create_empty_matrix();
	result.size = matrix->size;
	i = 0;
	while (i < matrix->size)
	{
		j = 0;
		while (j < matrix->size)
		{
			cf = cofactor(matrix, i, j);
			result.vals[j][i] = cf / determinant(matrix);
			j++;
		}
		i++;
	}
	return (result);
}
