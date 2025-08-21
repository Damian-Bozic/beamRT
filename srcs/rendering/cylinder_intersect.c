/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:14:44 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:14:44 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// float	a;	0
// float	b;	1
// float	c;	2
// float	d1;	3
// float	d2;	4
// float	t;	5

static int	cyl_2(t_cyl *cyl, t_pixel *pixel, float i[6], t_tuple cy_base)
{
	t_tuple	temp_a;
	t_tuple	temp_b;

	if (isnan(i[3]))
		return (0);
	pixel->hit_pos = scale_tuple(&pixel->ray.orient, i[3]);
	pixel->hit_pos = add_tuples(&pixel->hit_pos, &pixel->ray.origin);
	temp_b = subtract_tuples(&pixel->hit_pos, &pixel->ray.origin);
	if (dot_product(&temp_b, &pixel->ray.orient) < 0)
		return (0);
	temp_a = subtract_tuples(&pixel->hit_pos, &cy_base);
	i[5] = dot_product(&cyl->axis, &temp_a);
	if (i[5] < 0 || i[5] > cyl->height)
		return (0);
	temp_a = subtract_tuples(&pixel->hit_pos, &cy_base);
	i[5] = dot_product(&cyl->axis, &temp_a);
	temp_b = scale_tuple(&cyl->axis, i[5]);
	pixel->hit_normal = subtract_tuples(&temp_a, &temp_b);
	pixel->hit_normal = normalise_vector(&pixel->hit_normal);
	return (1);
}

int	find_cylinder_intersect(t_cyl *cylinder, t_pixel *pixel)
{
	t_tuple	cy_base;
	t_tuple	temp_a;
	t_tuple	temp_b;
	float	i[6];

	cylinder->axis = normalise_vector(&cylinder->axis);
	cy_base = scale_tuple(&cylinder->axis, -cylinder->height / 2);
	cy_base = add_tuples(&cy_base, &cylinder->pos);
	cy_base.values[3] = 1;
	temp_b = subtract_tuples(&pixel->ray.origin, &cy_base);
	temp_a = cross_product(&cylinder->axis, &pixel->ray.orient);
	temp_b = cross_product(&cylinder->axis, &temp_b);
	i[0] = dot_product(&temp_a, &temp_a);
	i[1] = dot_product(&temp_b, &temp_a);
	i[2] = dot_product(&temp_b, &temp_b) - ft_pow(cylinder->diameter / 2, 2);
	i[3] = ((-i[1] * 2) - sqrt(ft_pow(2 * i[1], 2)
				- 4 * i[0] * i[2])) / (2 * i[0]);
	i[4] = ((-i[1] * 2) + sqrt(ft_pow(2 * i[1], 2)
				- 4 * i[0] * i[2])) / (2 * i[0]);
	if (i[3] < 0 && zero_epsilon_check(i[3]))
		i[3] = i[4];
	return (cyl_2(cylinder, pixel, i, cy_base));
}
