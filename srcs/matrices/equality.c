/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equality.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:10:21 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:10:22 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
	Checks if two floats are close enough to be called equal
*/
int	are_floats_equal(float f1, float f2)
{
	return (fabs(f1 - f2) < EPSILON);
}

/*
	Checks if two tuples have the same values
*/
int	are_tuples_equal(t_tuple *v1, t_tuple *v2)
{
	unsigned int	i;

	i = 0;
	while (i < VEC_SIZE)
	{
		if (0 == are_floats_equal(v1->values[i], v2->values[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
	Compares the size and all values of two matrices
*/
int	are_matrices_equal(t_matrix *m1, t_matrix *m2)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	j;

	size = m1->size * m1->size;
	if ((m2->size * m2->size) != size)
		return (0);
	i = 0;
	while (i < m1->size)
	{
		j = 0;
		while (j < m1->size)
		{
			if (0 == are_floats_equal(m1->vals[i][j], m2->vals[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
