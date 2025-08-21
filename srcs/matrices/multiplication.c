/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:11:19 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:11:20 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
	Multiplies 2 matrices together, returning a new one
*/
t_matrix	multiply_matrices(t_matrix *matrix, t_matrix *other)
{
	t_matrix		result;
	int				i;
	unsigned int	j;
	unsigned int	k;
	float			total;

	result = create_empty_matrix();
	i = -1;
	while (++i < (int)matrix->size)
	{
		j = 0;
		while (j < matrix->size)
		{
			k = 0;
			total = 0;
			while (k < matrix->size)
			{
				total += matrix->vals[i][k] * other->vals[k][j];
				k++;
			}
			result.vals[i][j] = total;
			j++;
		}
	}
	return (result);
}

/*
	Multiplies 2 matrices together, returning a new one
*/
t_tuple	multiply_matrix_and_tuple(t_matrix *matrix, t_tuple *vector)
{
	unsigned int	i;
	unsigned int	j;
	t_tuple			result;

	i = 0;
	result = create_empty_vector();
	while (i < matrix->size)
	{
		j = 0;
		while (j < matrix->size)
		{
			result.values[i] += matrix->vals[i][j] * vector->values[j];
			j++;
		}
		i++;
	}
	return (result);
}

float	dot_product(t_tuple *vector1, t_tuple *vector2)
{
	float	result;

	result = vector1->values[0] * vector2->values[0];
	result += vector1->values[1] * vector2->values[1];
	result += vector1->values[2] * vector2->values[2];
	result += vector1->values[3] * vector2->values[3];
	return (result);
}

t_tuple	cross_product(t_tuple *vector1, t_tuple *vector2)
{
	t_tuple	vector;

	vector = create_empty_vector();
	vector.values[0] = (vector1->values[1] * vector2->values[2])
		- (vector1->values[2] * vector2->values[1]);
	vector.values[1] = (vector1->values[2] * vector2->values[0])
		- (vector1->values[0] * vector2->values[2]);
	vector.values[2] = (vector1->values[0] * vector2->values[1])
		- (vector1->values[1] * vector2->values[0]);
	return (vector);
}
