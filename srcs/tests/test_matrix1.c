/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:07:50 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/03 16:49:09 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_matrix	create_smaller_matrix(unsigned int size, const float *values)
{
	t_matrix		matrix;
	unsigned int	i;
	unsigned int	j;

	matrix = create_empty_matrix();
	matrix.size = size;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			matrix.vals[i][j] = values[(i * size) + j];
			j++;
		}
		i++;
	}
	return (matrix);
}

void	test_create_matrix(void)
{
	t_matrix		matrix;
	float			total;
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;

	printf("Testing create...\n");
	size = 1;
	while (++size < 5)
	{
		matrix = create_empty_matrix();
		matrix.size = size;
		total = 0.0f;
		i = -1;
		while (++i < matrix.size)
		{
			j = -1;
			while (++j < matrix.size)
				total += matrix.vals[i][j];
		}
		print_result(1, are_floats_equal(size, matrix.size));
		print_result(1, are_floats_equal(0.0f, total));
	}
}

static void	test_multiply_matrices_helper(t_matrix matrix1, t_matrix matrix2)
{
	t_matrix	check;
	t_matrix	result;
	const float	check_values[] = {20, 22, 50, 48, 44, 54, 114, 108, 40, 58,
		110, 102, 16, 26, 46, 42};

	check = create_matrix(check_values);
	result = multiply_matrices(&matrix1, &matrix2);
	print_result(1, are_matrices_equal(&result, &check));
}

void	test_multiply_matrices(void)
{
	t_matrix	matrix1;
	t_matrix	matrix2;
	const float	m1_values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2};
	const float	m2_values[] = {-2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6,
		5, 1, 2, 7, 8};

	printf("Testing multiply matrices...\n");
	matrix1 = create_matrix(m1_values);
	matrix2 = create_matrix(m2_values);
	test_multiply_matrices_helper(matrix1, matrix2);
}

void	test_multiple_matrix_and_vector(void)
{
	t_matrix	matrix;
	t_tuple		vector;
	t_tuple		check;
	t_tuple		result;
	const float	m_values[] = {1, 2, 3, 4, 2, 4, 4, 2, 8, 6, 4, 1, 0, 0, 0, 1};

	printf("Testing multiply matrix and vector...\n");
	matrix = create_matrix(m_values);
	vector = create_point(1, 2, 3);
	check = create_point(18, 24, 33);
	result = multiply_matrix_and_tuple(&matrix, &vector);
	print_result(1, are_tuples_equal(&result, &check));
}
