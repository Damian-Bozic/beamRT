/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tuple1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:52:26 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/03 13:52:27 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	test_is_point_or_vector(void)
{
	t_tuple	vector;

	printf("Checking is_point_or_vector...\n");
	vector = create_point(4.3, -4.2, 3.1);
	print_result(2, are_floats_equal(1, vector.values[3]));
	vector = create_vector(4.3, -4.2, 3.1);
	print_result(2, are_floats_equal(0, vector.values[3]));
}

void	test_add_tuples(void)
{
	t_tuple	point;
	t_tuple	vector;
	t_tuple	check;
	t_tuple	result;

	printf("Checking add_vector...\n");
	point = create_point(3, -2, 5);
	vector = create_vector(-2, 3, 1);
	check = create_point(1, 1, 6);
	result = add_tuples(&vector, &point);
	print_result(1, are_tuples_equal(&result, &check));
}

void	test_subtract_tuples(void)
{
	t_tuple	point1;
	t_tuple	point2;
	t_tuple	check;
	t_tuple	result;

	printf("Checking subtract_vector...\n");
	point1 = create_point(3, 2, 1);
	point2 = create_point(5, 6, 7);
	check = create_vector(-2, -4, -6);
	result = subtract_tuples(&point1, &point2);
	print_result(1, are_tuples_equal(&result, &check));
	point2 = create_vector(5, 6, 7);
	check = create_point(-2, -4, -6);
	result = subtract_tuples(&point1, &point2);
	print_result(2, are_tuples_equal(&result, &check));
	point1 = create_vector(3, 2, 1);
	check = create_vector(-2, -4, -6);
	result = subtract_tuples(&point1, &point2);
	print_result(3, are_tuples_equal(&result, &check));
}

void	test_negate_tuple(void)
{
	t_tuple	point;
	t_tuple	check;

	printf("Checking negate_vector...\n");
	point = create_tuple(1, -2, 3, -4);
	check = create_tuple(-1, 2, -3, 4);
	point = invert_tuple(&point);
	print_result(1, are_tuples_equal(&point, &check));
}

void	test_scale_tuple(void)
{
	t_tuple	tuple;
	t_tuple	check;
	t_tuple	result;

	printf("Checking scale_tuple...\n");
	tuple = create_tuple(1, -2, 3, -4);
	check = create_tuple(3.5, -7, 10.5, -14);
	result = scale_tuple(&tuple, 3.5);
	print_result(1, are_tuples_equal(&result, &check));
	check = create_tuple(0.5, -1, 1.5, -2);
	result = scale_tuple(&tuple, 0.5);
	print_result(2, are_tuples_equal(&result, &check));
}
