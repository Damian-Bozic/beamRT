/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:10:53 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/08 16:30:32 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
	Prints a green or red (passed or failed) message
*/
void	print_result(int test, int result)
{
	if (1 == result)
		printf("\033[0;32m\033[1m	Test %i\n\033[0m", test);
	else
		printf("\033[0;31m\033[1m	Test %i\n\033[0m", test);
}

/*
	Create a matrix with specific values to use in the tests
*/
t_matrix	create_matrix(const float *values)
{
	t_matrix		matrix;
	unsigned int	i;
	unsigned int	j;

	matrix = create_empty_matrix();
	i = 0;
	while (i < VEC_SIZE)
	{
		j = 0;
		while (j < VEC_SIZE)
		{
			matrix.vals[i][j] = values[(i * VEC_SIZE) + j];
			j++;
		}
		i++;
	}
	return (matrix);
}

/*
	Runs all the matrix tests
*/
static void	test_matrices(void)
{
	test_create_matrix();
	test_multiply_matrices();
	test_multiple_matrix_and_vector();
	test_determinant_2x2();
	test_determinant_3x3();
	test_determinant_4x4();
	test_submatrix();
	test_multiply_identity();
	test_minor();
	test_cofactor();
	test_invertibility();
	test_invert();
	test_translation();
	test_transpose_matrix();
	test_scaling();
	test_rotate_x();
	test_rotate_y();
	test_rotate_z();
}

/*
	Run all the tests
*/
int	main(void)
{
	printf("Testing...");
	test_is_point_or_vector();
	test_add_tuples();
	test_subtract_tuples();
	test_negate_tuple();
	test_scale_tuple();
	test_vector_magnitude();
	test_normalise_vector();
	test_dot_product();
	test_cross_product();
	test_matrices();
	test_parsing();
	return (0);
}
