/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_rotation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:11:33 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:11:34 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

t_matrix	x_rotation_degrees(double degrees)
{
	t_matrix	matrix;

	degrees = (degrees / 180) * M_PI;
	matrix = identity_matrix();
	matrix.vals[1][1] = cos(degrees);
	matrix.vals[1][2] = -1 * sin(degrees);
	matrix.vals[2][1] = sin(degrees);
	matrix.vals[2][2] = cos(degrees);
	return (matrix);
}

t_tuple	rotate_x_degrees(t_tuple *vector, double degrees)
{
	t_matrix	matrix;

	matrix = x_rotation_degrees(degrees);
	return (multiply_matrix_and_tuple(&matrix, vector));
}

t_matrix	x_rotation_radians(double radians)
{
	t_matrix	matrix;

	matrix = identity_matrix();
	matrix.vals[1][1] = cos(radians);
	matrix.vals[1][2] = -1 * sin(radians);
	matrix.vals[2][1] = sin(radians);
	matrix.vals[2][2] = cos(radians);
	return (matrix);
}

t_tuple	rotate_x_radians(t_tuple *vector, double radians)
{
	t_matrix	matrix;

	matrix = x_rotation_radians(radians);
	return (multiply_matrix_and_tuple(&matrix, vector));
}
