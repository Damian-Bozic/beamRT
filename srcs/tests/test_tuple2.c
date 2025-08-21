/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tuple2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:52:05 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/03 13:52:06 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	test_vector_magnitude(void)
{
	t_tuple	vector;

	printf("Checking vector_magnitude...\n");
	vector = create_vector(1, 0, 0);
	print_result(1, vector_magnitude(&vector));
	vector = create_vector(0, 1, 0);
	print_result(2, vector_magnitude(&vector));
	vector = create_vector(0, 0, 1);
	print_result(3, vector_magnitude(&vector));
	vector = create_vector(1, 2, 3);
	print_result(4, are_floats_equal(3.741657, vector_magnitude(&vector)));
	vector = create_vector(-1, -2, -3);
	print_result(5, are_floats_equal(3.741657, vector_magnitude(&vector)));
}

void	test_normalise_vector(void)
{
	t_tuple	vector;
	t_tuple	check;
	t_tuple	result;

	printf("Checking normalise_vector...\n");
	vector = create_vector(4, 0, 0);
	check = create_vector(1, 0, 0);
	result = normalise_vector(&vector);
	print_result(1, are_tuples_equal(&result, &check));
	vector = create_vector(1, 2, 3);
	check = create_vector(0.26726, 0.53452, 0.80178);
	result = normalise_vector(&vector);
	print_result(2, are_tuples_equal(&result, &check));
	print_result(3, are_floats_equal(1, vector_magnitude(&result)));
}

void	test_dot_product(void)
{
	t_tuple	vector1;
	t_tuple	vector2;

	printf("Checking test_dot_product...\n");
	vector1 = create_vector(1, 2, 3);
	vector2 = create_vector(2, 3, 4);
	print_result(1, are_floats_equal(20, dot_product(&vector1, &vector2)));
}

void	test_cross_product(void)
{
	t_tuple	vector1;
	t_tuple	vector2;
	t_tuple	check;
	t_tuple	result;

	printf("Checking test_cross_product...\n");
	vector1 = create_vector(1, 2, 3);
	vector2 = create_vector(2, 3, 4);
	check = create_vector(-1, 2, -1);
	result = cross_product(&vector1, &vector2);
	print_result(1, are_tuples_equal(&result, &check));
	check = create_vector(1, -2, 1);
	result = cross_product(&vector2, &vector1);
	print_result(2, are_tuples_equal(&result, &check));
}
