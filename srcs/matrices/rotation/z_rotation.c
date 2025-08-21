/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_rotation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:11:39 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:11:39 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

t_matrix	z_rotation_degrees(double degrees)
{
	t_matrix	matrix;

	degrees = (degrees / 180) * M_PI;
	matrix = identity_matrix();
	matrix.vals[0][0] = cos(degrees);
	matrix.vals[0][1] = -1 * sin(degrees);
	matrix.vals[1][0] = sin(degrees);
	matrix.vals[1][1] = cos(degrees);
	return (matrix);
}

t_tuple	rotate_z_degrees(t_tuple *vector, double degrees)
{
	t_matrix	matrix;

	matrix = z_rotation_degrees(degrees);
	return (multiply_matrix_and_tuple(&matrix, vector));
}

t_matrix	z_rotation_radians(double radians)
{
	t_matrix	matrix;

	matrix = identity_matrix();
	matrix.vals[0][0] = cos(radians);
	matrix.vals[0][1] = -1 * sin(radians);
	matrix.vals[1][0] = sin(radians);
	matrix.vals[1][1] = cos(radians);
	return (matrix);
}

t_tuple	rotate_z_radians(t_tuple *vector, double radians)
{
	t_matrix	matrix;

	matrix = z_rotation_radians(radians);
	return (multiply_matrix_and_tuple(&matrix, vector));
}
