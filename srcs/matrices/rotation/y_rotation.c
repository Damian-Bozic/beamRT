/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_rotation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:11:36 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:11:37 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

t_matrix	y_rotation_degrees(double degrees)
{
	t_matrix	matrix;

	degrees = (degrees / 180) * M_PI;
	matrix = identity_matrix();
	matrix.vals[0][0] = cos(degrees);
	matrix.vals[0][2] = sin(degrees);
	matrix.vals[2][0] = -1 * sin(degrees);
	matrix.vals[2][2] = cos(degrees);
	return (matrix);
}

t_tuple	rotate_y_degrees(t_tuple *vector, double degrees)
{
	t_matrix	matrix;

	matrix = y_rotation_degrees(degrees);
	return (multiply_matrix_and_tuple(&matrix, vector));
}

t_matrix	y_rotation_radians(double radians)
{
	t_matrix	matrix;

	matrix = identity_matrix();
	matrix.vals[0][0] = cos(radians);
	matrix.vals[0][2] = sin(radians);
	matrix.vals[2][0] = -1 * sin(radians);
	matrix.vals[2][2] = cos(radians);
	return (matrix);
}

t_tuple	rotate_y_radians(t_tuple *vector, double radians)
{
	t_matrix	matrix;

	matrix = y_rotation_radians(radians);
	return (multiply_matrix_and_tuple(&matrix, vector));
}
