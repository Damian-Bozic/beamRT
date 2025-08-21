/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:04:04 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/03 16:49:40 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	test_transpose_matrix(void)
{
	t_matrix	matrix;
	t_matrix	check;
	t_matrix	result;
	const float	m_values[] = {0, 9, 3, 0, 9, 8, 0, 8, 1, 8, 5, 3, 0, 0, 5, 8};
	const float	check_values[] = {0, 9, 1, 0, 9, 8, 8, 0, 3, 0, 5, 5,
		0, 8, 3, 8};

	printf("Testing transpose matrix...\n");
	matrix = create_matrix(m_values);
	check = create_matrix(check_values);
	result = transpose_matrix(&matrix);
	print_result(1, are_matrices_equal(&result, &check));
}

void	test_minor(void)
{
	t_matrix	matrix;
	t_matrix	sub;
	float		result;
	float		check;
	const float	m_values[] = {3, 5, 0, 2, -1, -7, 6, -1, 5};

	printf("Testing minor...\n");
	matrix = create_smaller_matrix(3, m_values);
	matrix.size = 3;
	sub = submatrix(&matrix, 1, 0);
	check = determinant(&sub);
	result = minor_3x3(&matrix, 1, 0);
	print_result(1, are_floats_equal(check, result));
}

void	test_cofactor(void)
{
	t_matrix	matrix;
	float		result;
	const float	m_values[] = {3, 5, 0, 2, -1, -7, 6, -1, 5};

	printf("Testing cofactor...\n");
	matrix = create_smaller_matrix(3, m_values);
	matrix.size = 3;
	result = cofactor(&matrix, 0, 0);
	print_result(1, are_floats_equal(-12.0f, result));
	result = cofactor(&matrix, 1, 0);
	print_result(1, are_floats_equal(-25.0f, result));
}

void	test_invertibility(void)
{
	t_matrix	matrix;
	int			result;
	const float	m1_values[] = {6, 4, 4, 4, 5, 5, 7, 6, 4, -9, 3, -7, 9,
		1, 7, -6};
	const float	m2_values[] = {-4, 2, -2, -3, 9, 6, 2, 6, 0, -5, 1, -5,
		0, 0, 0, 0};

	printf("Testing invertibility...\n");
	matrix = create_matrix(m1_values);
	result = is_invertible(&matrix);
	print_result(1, 1 == result);
	matrix = create_matrix(m2_values);
	result = is_invertible(&matrix);
	print_result(1, 0 == result);
}

void	test_translation(void)
{
	t_matrix	matrix;
	t_tuple		vector;
	t_tuple		result;
	t_tuple		check;

	printf("Testing translation...\n");
	matrix = translation(5, -3, 2);
	vector = create_point(-3, 4, 5);
	check = create_point(2, 1, 7);
	result = multiply_matrix_and_tuple(&matrix, &vector);
	print_result(1, are_tuples_equal(&result, &check));
	vector.values[3] = 0;
	result = multiply_matrix_and_tuple(&matrix, &vector);
	print_result(2, are_tuples_equal(&result, &vector));
	matrix = invert(&matrix);
	vector = create_vector(-3, 4, 5);
	result = multiply_matrix_and_tuple(&matrix, &vector);
	print_result(3, are_tuples_equal(&result, &vector));
}
