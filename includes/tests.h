/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:08:18 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:08:19 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

// tests
void		print_matrix(t_matrix *matrix);
void		print_tuple(t_tuple *tuple, char *message);
void		print_result(int test, int result);

// test_invert
void		test_invert(void);

// test_parsing
void		test_parsing(void);

// test_tuple1
void		test_is_point_or_vector(void);
void		test_add_tuples(void);
void		test_subtract_tuples(void);
void		test_negate_tuple(void);
void		test_scale_tuple(void);

// test_tuple2
void		test_vector_magnitude(void);
void		test_normalise_vector(void);
void		test_dot_product(void);
void		test_cross_product(void);

// test_matrix1
t_matrix	create_smaller_matrix(unsigned int size, const float *values);
void		test_create_matrix(void);
void		test_multiply_matrices(void);
void		test_multiple_matrix_and_vector(void);

// test_matrix2
void		test_determinant_2x2(void);
void		test_determinant_3x3(void);
void		test_determinant_4x4(void);
void		test_submatrix(void);

// test_matrix3
void		test_multiply_identity(void);
void		test_minor(void);
void		test_cofactor(void);
void		test_invertibility(void);
void		test_translation(void);

// test_matrix4
void		test_transpose_matrix(void);
void		test_scaling(void);
void		test_rotate_x(void);
void		test_rotate_y(void);
void		test_rotate_z(void);

#endif
