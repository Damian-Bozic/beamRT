/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:15:16 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:15:17 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_tuple	find_sphere_normal(t_sphere *sphere, t_tuple *T)
{
	t_tuple	normal;

	normal = subtract_tuples(T, &sphere->pos);
	normal = normalise_vector(&normal);
	return (normal);
}

int	find_sphere_intersect(t_sphere *sphere, t_pixel *pixel)
{
	t_tuple	temp_tuple;
	t_tuple	closest_point;
	float	t;
	float	xs;
	float	ys;

	temp_tuple = subtract_tuples(&sphere->pos, &pixel->ray.origin);
	t = dot_product(&temp_tuple, &pixel->ray.orient);
	if (t < 0)
		return (1);
	temp_tuple = scale_tuple(&pixel->ray.orient, t);
	closest_point = add_tuples(&pixel->ray.origin, &temp_tuple);
	ys = distance_between_points(sphere->pos, closest_point);
	if (ys > sphere->diameter / 2)
		return (1);
	xs = sqrt(ft_pow(sphere->diameter / 2, 2) - ft_pow(ys, 2));
	temp_tuple = scale_tuple(&pixel->ray.orient, t - xs);
	pixel->hit_pos = add_tuples(&pixel->ray.origin, &temp_tuple);
	pixel->hit_normal = find_sphere_normal(sphere, &pixel->hit_pos);
	return (0);
}

// int	find_sphere_intersect(t_sphere *sphere, t_pixel *pixel)
// {
// 	t_tuple temp_tuple;
// 	t_tuple closest_point;
// 	float	t;
// 	float	xs;
// 	float	ys;

// 	//pixel hit pos is used as T throughout this function
// 	temp_tuple = subtract_tuples(&sphere->pos, &pixel->ray.origin);
// 	// print_tuple(&pixel->ray.orient, "ray orient");
// 	t = dot_product(&temp_tuple, &pixel->ray.orient);
// 	if (t < 0)
// 		return (1); // check if behind camera
// 	temp_tuple = scale_tuple(&pixel->ray.orient, t); 
// 	closest_point = add_tuples(&pixel->ray.origin, &temp_tuple); // finds T

// 	ys = distance_between_points(sphere->pos, closest_point); // find Ys

// 	if (ys > sphere->diameter / 2)
// 		return (1); // if ys is greater than rs then the ray misses
// 	xs = sqrt(ft_pow(sphere->diameter / 2, 2) - ft_pow(ys, 2)); // find Xs
// 	temp_tuple = scale_tuple(&pixel->ray.orient, t - xs);
// 	pixel->hit_pos = add_tuples(&pixel->ray.origin, &temp_tuple);
// 	pixel->hit_normal = find_sphere_normal(sphere, &pixel->hit_pos);
// 	return (0);
// }
