/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_cap_intersect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:14:39 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:14:39 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	end_cap2(t_cyl *cy, t_pixel *p, t_tuple *cap_pos, t_tuple *hit)
{
	float	d;
	t_tuple	temp;

	d = (dot_product(&cy->axis, cap_pos)
			- dot_product(&cy->axis, &p->ray.origin))
		/ dot_product(&cy->axis, &p->ray.orient);
	*hit = scale_tuple(&p->ray.orient, d);
	*hit = add_tuples(hit, &p->ray.origin);
	temp = subtract_tuples(hit, cap_pos);
	d = dot_product(&temp, &temp);
	if (d < ft_pow(cy->diameter / 2, 2))
		return (1);
	return (0);
}

static void	top_cap_hit(t_pixel *pixel, t_tuple *norm, t_cyl *cy)
{
	pixel->hit_pos = norm[2];
	pixel->hit_normal = cy->axis;
}

static void	bottom_cap_hit(t_pixel *pixel, t_tuple *norm, t_cyl *cy)
{
	pixel->hit_pos = norm[3];
	pixel->hit_normal = invert_tuple(&cy->axis);
}

static int	set_cap_hit_and_norm(t_tuple *norm, t_pixel *p, t_cyl *cy, int *i)
{
	if (i[0] && i[1])
	{
		if (distance_between_points(p->ray.origin, norm[2])
			< distance_between_points(p->ray.origin, norm[3]))
			top_cap_hit(p, norm, cy);
		else
			bottom_cap_hit(p, norm, cy);
	}
	else if (i[0] && !i[1])
		top_cap_hit(p, norm, cy);
	else if (!i[0] && i[1])
		bottom_cap_hit(p, norm, cy);
	else
		return (0);
	return (1);
}

// t_tuple	cy_top; 0
// t_tuple	cy_base; 1
// t_tuple	top_cap_hit; 2
// t_tuple	bottom_cap_hit; 3
// t_tuple	temp; 4

// int		top; 0
// int		bottom; 1
int	find_end_cap_intersect(t_cyl *cy, t_pixel *pixel)
{
	t_tuple	norm[5];
	int		top_and_bottom[2];

	cy->axis = normalise_vector(&cy->axis);
	norm[1] = scale_tuple(&cy->axis, -cy->height / 2);
	norm[1] = add_tuples(&norm[1], &cy->pos);
	norm[1].values[3] = 1;
	norm[0] = scale_tuple(&cy->axis, cy->height / 2);
	norm[0] = add_tuples(&norm[0], &cy->pos);
	norm[0].values[3] = 1;
	top_and_bottom[0] = end_cap2(cy, pixel, &norm[0], &norm[2]);
	top_and_bottom[1] = end_cap2(cy, pixel, &norm[1], &norm[3]);
	norm[4] = subtract_tuples(&norm[2], &pixel->ray.origin);
	if (dot_product(&norm[4], &pixel->ray.orient) < 0)
		top_and_bottom[0] = 0;
	norm[4] = subtract_tuples(&norm[3], &pixel->ray.origin);
	if (dot_product(&norm[4], &pixel->ray.orient) < 0)
		top_and_bottom[1] = 0;
	return (set_cap_hit_and_norm(norm, pixel, cy, top_and_bottom));
}
