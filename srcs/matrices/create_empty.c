/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:09:57 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:09:58 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
	Creates a new tuple
*/
t_tuple	create_empty_tuple(void)
{
	t_tuple			vector;
	unsigned int	i;

	i = 0;
	while (i < VEC_SIZE)
	{
		vector.values[i] = 0.0f;
		i++;
	}
	return (vector);
}

/*
	Creates a new point
*/
t_tuple	create_empty_point(void)
{
	t_tuple		point;

	point.values[0] = 0.0f;
	point.values[1] = 0.0f;
	point.values[2] = 0.0f;
	point.values[3] = 1.0f;
	return (point);
}

/*
	Creates a new vector
*/
t_tuple	create_empty_vector(void)
{
	t_tuple			vector;
	unsigned int	i;

	i = 0;
	while (i < VEC_SIZE)
	{
		vector.values[i] = 0.0f;
		i++;
	}
	return (vector);
}

/*
	Creates a new matrix
*/
t_matrix	create_empty_matrix(void)
{
	t_matrix		matrix;
	unsigned int	i;
	unsigned int	j;

	matrix.size = VEC_SIZE;
	i = 0;
	while (i < VEC_SIZE)
	{
		j = 0;
		while (j < VEC_SIZE)
		{
			matrix.vals[i][j] = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}
