/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:53:14 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/03 16:49:21 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	test_determinant_2x2(void)
{
	t_matrix	matrix;
	const float	m_values[] = {1, 5, -3, 2};
	float		result;

	printf("Testing determinant 2x2...\n");
	matrix = create_smaller_matrix(2, m_values);
	result = determinant(&matrix);
	print_result(1, are_floats_equal(17.0f, result));
}

void	test_determinant_3x3(void)
{
	t_matrix	matrix;
	const float	m_values[] = {1, 2, 6, -5, 8, -4, 2, 6, 4};
	float		result;

	printf("Testing determinant 3x3...\n");
	matrix = create_smaller_matrix(3, m_values);
	result = determinant(&matrix);
	print_result(1, are_floats_equal(-196.0f, result));
}

void	test_determinant_4x4(void)
{
	t_matrix	matrix;
	const float	m_values[] = {-2, -8, 3, 5, -3, 1, 7, 3, 1, 2, -9, 6,
		-6, 7, 7, -9};
	float		result;

	printf("Testing determinant 4x4...\n");
	matrix = create_matrix(m_values);
	result = determinant(&matrix);
	print_result(1, are_floats_equal(-4071.0f, result));
}

static void	test_submarix_helper(t_matrix matrix1, t_matrix matrix2)
{
	t_matrix	check;
	t_matrix	result;
	const float	check1_values[] = {-3, 2, 0, 6};
	const float	check2_values[] = {-6, 1, 6, -8, 8, 6, -7, -1, 1};

	check = create_smaller_matrix(2, check1_values);
	result = submatrix(&matrix1, 0, 2);
	print_result(1, are_matrices_equal(&result, &check));
	check = create_smaller_matrix(3, check2_values);
	result = submatrix(&matrix2, 2, 1);
	print_result(2, are_matrices_equal(&result, &check));
}

void	test_submatrix(void)
{
	t_matrix	matrix1;
	t_matrix	matrix2;
	const float	m1_values[] = {1, 5, 0, -3, 2, 7, 0, 6, -3};
	const float	m2_values[] = {-6, 1, 1, 6, -8, 5, 8, 6, -1, 0, 8, 2,
		-7, 1, -1, 1};

	printf("Testing submatrix...\n");
	matrix1 = create_smaller_matrix(3, m1_values);
	matrix2 = create_matrix(m2_values);
	test_submarix_helper(matrix1, matrix2);
}
