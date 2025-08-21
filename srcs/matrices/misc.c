/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:11:16 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:11:17 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
	Returns the length of a vector
*/
float	vector_magnitude(t_tuple *vector)
{
	float	total;

	total = vector->values[0] * vector->values[0];
	total += (vector->values[1] * vector->values[1]);
	total += (vector->values[2] * vector->values[2]);
	return (sqrt(total));
}

t_tuple	normalise_vector(t_tuple *vector)
{
	t_tuple			result;
	float			magnitude;
	unsigned int	i;

	result = create_empty_vector();
	magnitude = vector_magnitude(vector);
	i = 0;
	while (i < VEC_SIZE)
	{
		result.values[i] = vector->values[i] / magnitude;
		i++;
	}
	return (result);
}

/*
	Swaps a matrix's rows and cols, returning a new matrix
*/
t_matrix	transpose_matrix(t_matrix *matrix)
{
	unsigned int	i;
	unsigned int	j;
	t_matrix		result;

	result = create_empty_matrix();
	i = 0;
	while (i < matrix->size)
	{
		j = 0;
		while (j < matrix->size)
		{
			result.vals[i][j] = matrix->vals[j][i];
			j++;
		}
		i++;
	}
	return (result);
}

/*
	Returns an identity matrix (1s on the diagonal)
*/
t_matrix	identity_matrix(void)
{
	t_matrix		result;

	result = create_empty_matrix();
	result.vals[0][0] = 1.0f;
	result.vals[1][1] = 1.0f;
	result.vals[2][2] = 1.0f;
	result.vals[3][3] = 1.0f;
	return (result);
}
