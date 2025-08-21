/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:15:11 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:15:12 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	find_plane_intersect(t_plane *plane, t_pixel *pixel)
{
	t_tuple	temp_tuple;
	t_tuple	c;
	float	projection_scale;
	float	denom;

	denom = dot_product(&plane->normal, &pixel->ray.orient);
	if (denom == 0)
		return (0);
	c = subtract_tuples(&plane->pos, &pixel->ray.origin);
	projection_scale = dot_product(&c, &plane->normal);
	projection_scale = projection_scale / denom;
	if (projection_scale < 0)
		return (0);
	temp_tuple = scale_tuple(&pixel->ray.orient, projection_scale);
	pixel->hit_pos = add_tuples(&pixel->ray.origin, &temp_tuple);
	pixel->hit_normal = normalise_vector(&plane->normal);
	if (dot_product(&pixel->hit_normal, &pixel->ray.orient) > 0)
		pixel->hit_normal = invert_tuple(&pixel->hit_normal);
	return (1);
}
