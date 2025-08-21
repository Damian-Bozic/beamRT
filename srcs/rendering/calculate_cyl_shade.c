/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cyl_shade.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:14:05 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:14:06 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// float a; 0
// float b; 1
// float c; 2
// float d1; 3
// float d2; 4
// float discriminant; 5
int	cylinder_quadratic(t_tuple *temp_a, t_tuple *temp_b, t_cyl *cyl, float *d)
{
	float	i[6];

	i[0] = dot_product(temp_a, temp_a);
	i[1] = dot_product(temp_b, temp_a);
	i[2] = dot_product(temp_b, temp_b) - ft_pow(cyl->diameter / 2, 2);
	i[5] = i[1] * i[1] - i[0] * i[2];
	if (i[5] < 0)
		return (0);
	i[3] = (-i[1] - sqrt(i[5])) / i[0];
	i[4] = (-i[1] + sqrt(i[5])) / i[0];
	if (i[3] < 0 || i[4] < 0)
		return (0);
	if (i[3] > 0 && (i[3] < i[4] || i[4] < 0))
		i[4] = i[3];
	if (i[4] < 0)
		return (0);
	*d = i[4];
	return (1);
}

// float delta; 0
// float t; 1
// float a_hit_distance; 2
// float a_b_distance; 3

// t_tuple cy_base; 0
// t_tuple w; 1
// t_tuple temp_a; 2
// t_tuple temp_b; 3
// t_tuple B_to_A_vector 4
int	icbl2(t_cyl *cyl, t_tuple *norm, t_tuple *point_A, t_tuple *point_B)
{
	float	floats[4];

	if (!cylinder_quadratic(&norm[2], &norm[3], cyl, &floats[0]))
		return (0);
	norm[2] = scale_tuple(&norm[4], floats[0]);
	norm[2] = add_tuples(&norm[2], point_A);
	norm[3] = subtract_tuples(&norm[2], point_A);
	floats[2] = distance_between_points(*point_A, norm[2]);
	floats[3] = distance_between_points(*point_A, *point_B);
	if (floats[2] > floats[3] && zero_epsilon_check(floats[2] - floats[3]))
		return (0);
	norm[2] = subtract_tuples(&norm[2], &norm[0]);
	floats[1] = dot_product(&cyl->axis, &norm[2]);
	if (floats[1] < 0 || floats[1] > cyl->height)
		return (0);
	return (1);
}

// t_tuple cy_base; 0
// t_tuple w; 1
// t_tuple temp_a; 2
// t_tuple temp_b; 3
// t_tuple B_to_A_vector 4
int	is_cylinder_blocking_light(t_mini *mini, t_tuple *point_A, t_tuple *point_B)
{
	int		i;
	t_cyl	*cyl;
	t_tuple	norm[5];

	i = 0;
	norm[4] = subtract_tuples(point_B, point_A);
	while (i < mini->objs->count.cylinder)
	{
		cyl = &mini->objs->cyls[i];
		cyl->axis = normalise_vector(&cyl->axis);
		norm[0] = scale_tuple(&cyl->axis, -cyl->height / 2);
		norm[0] = add_tuples(&norm[0], &cyl->pos);
		norm[0].values[3] = 1;
		norm[1] = subtract_tuples(point_A, &norm[0]);
		norm[2] = cross_product(&cyl->axis, &norm[4]);
		norm[3] = cross_product(&cyl->axis, &norm[1]);
		if (icbl2(cyl, norm, point_A, point_B))
			return (1);
		i++;
	}
	return (0);
}
// 1 is blocking // 0 is not

static int	check_for_cap_hit(t_pixel *fp, t_tuple *norm, int *i, t_tuple *A_B)
{
	norm[4] = subtract_tuples(&norm[2], &A_B[0]);
	if (dot_product(&norm[4], &norm[5]) < 0)
		i[1] = 0;
	norm[4] = subtract_tuples(&norm[3], &A_B[0]);
	if (dot_product(&norm[4], &norm[5]) < 0)
		i[2] = 0;
	if (i[1] && i[2])
	{
		if (distance_between_points(A_B[0], norm[2])
			< distance_between_points(A_B[0], norm[3]))
			fp->hit_pos = norm[2];
		else
			fp->hit_pos = norm[3];
	}
	else if (i[1] && !i[2])
		fp->hit_pos = norm[2];
	else if (!i[1] && i[2])
		fp->hit_pos = norm[3];
	else
		return (0);
	if ((!zero_epsilon_check(distance_between_points(fp->hit_pos, A_B[0])))
		|| distance_between_points(fp->hit_pos, A_B[0])
		> distance_between_points(A_B[1], A_B[0]))
		return (0);
	return (1);
}
// if (!zero_epsilon_check(distance_between_points(fp->hit_pos, *A)))

// int	i; 0
// int	top; 1
// int	bottom; 2

// t_tuple cy_top; 0
// t_tuple cy_base; 1
// t_tuple top_cap_hit; 2
// t_tuple bottom_cap_hit; 3
// t_tuple temp; 4
// t_tuple B_to_A_vector 5

// t_tuple point_A = 0
// t_tuple point_B = 1
int	is_cyl_cap_blocking_light(t_mini *mini, t_tuple *A_and_B)
{
	t_tuple	norm[6];
	t_pixel	fake_pixel;
	t_cyl	*cyl;
	int		i[3];

	i[0] = -1;
	cyl = &mini->objs->cyls[i[0] + 1];
	norm[5] = subtract_tuples(&A_and_B[1], &A_and_B[0]);
	while (++i[0] < mini->objs->count.cylinder)
	{
		fake_pixel.ray.orient = norm[5];
		fake_pixel.ray.origin = A_and_B[0];
		cyl->axis = normalise_vector(&cyl->axis);
		norm[1] = scale_tuple(&cyl->axis, -cyl->height / 2);
		norm[1] = add_tuples(&norm[1], &cyl->pos);
		norm[1].values[3] = 1;
		norm[0] = scale_tuple(&cyl->axis, cyl->height / 2);
		norm[0] = add_tuples(&norm[0], &cyl->pos);
		norm[0].values[3] = 1;
		i[1] = end_cap2(cyl, &fake_pixel, &norm[0], &norm[2]);
		i[2] = end_cap2(cyl, &fake_pixel, &norm[1], &norm[3]);
		if (check_for_cap_hit(&fake_pixel, norm, i, A_and_B))
			return (1);
	}
	return (0);
}
