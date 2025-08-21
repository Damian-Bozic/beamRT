/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:52:45 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/03 16:49:56 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	test_multiply_identity(void)
{
	t_matrix	matrix;
	t_matrix	identity;
	t_matrix	result;
	const float	m_values[] = {0, 1, 2, 4, 1, 2, 4, 8, 2, 4, 8, 16, 4,
		8, 16, 32};

	printf("Testing identity matrix...\n");
	matrix = create_matrix(m_values);
	identity = identity_matrix();
	result = multiply_matrices(&matrix, &identity);
	print_result(1, are_matrices_equal(&result, &matrix));
}

void	test_scaling(void)
{
	t_matrix	matrix;
	t_tuple		vector;
	t_tuple		result;
	t_tuple		check;

	printf("Testing scaling...\n");
	matrix = scaling(2, 3, 4);
	vector = create_point(-4, 6, 8);
	check = create_point(-8, 18, 32);
	result = multiply_matrix_and_tuple(&matrix, &vector);
	print_result(1, are_tuples_equal(&result, &check));
	vector.values[3] = 0;
	check.values[3] = 0;
	result = multiply_matrix_and_tuple(&matrix, &vector);
	print_result(2, are_tuples_equal(&result, &check));
	check = create_vector(-2, 2, 2);
	matrix = invert(&matrix);
	result = multiply_matrix_and_tuple(&matrix, &vector);
	print_result(3, are_tuples_equal(&result, &check));
	matrix = scaling(1, 1, 1);
	vector = create_point(2, 3, 4);
	check = create_point(2, 3, 4);
	result = multiply_matrix_and_tuple(&matrix, &vector);
	print_result(4, are_tuples_equal(&result, &check));
}

void	test_rotate_x(void)
{
	t_matrix	rotation;
	t_tuple		point;
	t_tuple		result;
	t_tuple		check;

	printf("Testing rotate_x...\n");
	point = create_point(0, 1, 0);
	check = create_point(0, 0.707107, 0.707107);
	rotation = x_rotation_radians(M_PI / 4);
	result = multiply_matrix_and_tuple(&rotation, &point);
	print_result(1, are_tuples_equal(&result, &check));
	check = create_point(0, 0, 1);
	rotation = x_rotation_radians(M_PI / 2);
	result = multiply_matrix_and_tuple(&rotation, &point);
	print_result(2, are_tuples_equal(&result, &check));
	check = create_point(0, 0.707107, -0.707107);
	rotation = x_rotation_radians(M_PI / 4);
	rotation = invert(&rotation);
	result = multiply_matrix_and_tuple(&rotation, &point);
	print_result(3, are_tuples_equal(&result, &check));
}

void	test_rotate_y(void)
{
	t_matrix	rotation;
	t_tuple		point;
	t_tuple		result;
	t_tuple		check;

	printf("Testing rotate_y...\n");
	point = create_point(0, 0, 1);
	check = create_point(0.707107, 0, 0.707107);
	rotation = y_rotation_radians(M_PI / 4);
	result = multiply_matrix_and_tuple(&rotation, &point);
	print_result(1, are_tuples_equal(&result, &check));
	check = create_point(1, 0, 0);
	rotation = y_rotation_radians(M_PI / 2);
	result = multiply_matrix_and_tuple(&rotation, &point);
	print_result(2, are_tuples_equal(&result, &check));
}

void	test_rotate_z(void)
{
	t_matrix	rotation;
	t_tuple		point;
	t_tuple		result;
	t_tuple		check;

	printf("Testing rotate_z...\n");
	point = create_point(0, 1, 0);
	check = create_point(-0.707107, 0.707107, 0);
	rotation = z_rotation_radians(M_PI / 4);
	result = multiply_matrix_and_tuple(&rotation, &point);
	print_result(1, are_tuples_equal(&result, &check));
	check = create_point(-1, 0, 0);
	rotation = z_rotation_radians(M_PI / 2);
	result = multiply_matrix_and_tuple(&rotation, &point);
	print_result(2, are_tuples_equal(&result, &check));
}
