/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:15:02 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:15:03 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// float	pixel_size;			0
// float	half_view;			1
// float	aspect;				2
// float	camera_half_width;	3
// float	camera_half_height;	4
// float	canvas_x;			5
// float	canvas_y;			6	
void	find_ray_orientation(t_pixel *pixel, t_mini *mini, int x, int y)
{
	float	norm[7];

	norm[1] = tan(((mini->objs->cams->fov * M_PI) / 180) / 2);
	norm[2] = (float)SCREEN_X / (float)SCREEN_Y;
	if (norm[2] >= 1)
	{
		norm[3] = norm[1];
		norm[4] = norm[1] / norm[2];
	}
	else
	{
		norm[3] = norm[1] * norm[2];
		norm[4] = norm[1];
	}
	norm[0] = (norm[3] * 2) / SCREEN_X;
	norm[5] = ((float)x + 0.5) * norm[0] - norm[3];
	norm[6] = (((float)y + 0.5) * norm[0] - norm[4]) * -1;
	pixel->ray.origin = mini->objs->cams->pos;
	pixel->ray.orient = create_vector(norm[5], norm[6], 1);
	pixel->ray.orient = normalise_vector(&pixel->ray.orient);
	pixel->ray.orient = rotate_to_world(&mini->objs->cams->orient,
			&pixel->ray.orient);
}

void	find_closer_point(t_pixel *temp_pixel, t_pixel *final_pixel, t_rgb *rgb)
{
	if (distance_between_points(final_pixel->hit_pos, temp_pixel->ray.origin)
		> distance_between_points(temp_pixel->hit_pos, temp_pixel->ray.origin))
	{
		final_pixel->hit_pos = temp_pixel->hit_pos;
		final_pixel->hit_normal = temp_pixel->hit_normal;
		final_pixel->rgb = *rgb;
	}
}

void	find_all_intersections(t_pixel *temp, t_pixel	*final, t_mini *mini)
{
	int		i;

	i = -1;
	while (++i < mini->objs->count.sphere)
		if (!find_sphere_intersect(&mini->objs->sprs[i], temp))
			find_closer_point(temp, final, &mini->objs->sprs[i].rgb);
	i = -1;
	while (++i < mini->objs->count.plane)
		if (find_plane_intersect(&mini->objs->plns[i], temp))
			find_closer_point(temp, final, &mini->objs->plns[i].rgb);
	i = -1;
	while (++i < mini->objs->count.cylinder)
	{
		if (find_cylinder_intersect(&mini->objs->cyls[i], temp))
			find_closer_point(temp, final, &mini->objs->cyls[i].rgb);
		if (find_end_cap_intersect(&mini->objs->cyls[i], temp))
			find_closer_point(temp, final, &mini->objs->cyls[i].rgb);
	}
}

void	copy_pixel_hit(t_pixel *orig, t_pixel *copy)
{
	orig->hit_pos = copy->hit_pos;
	orig->hit_normal = copy->hit_normal;
	orig->hit_rgb = copy->rgb;
}

int	cast_ray(t_mini *mini, int x, int y)
{
	int		i;
	t_pixel	temp_pixel;
	t_pixel	final_pixel;

	find_ray_orientation(&temp_pixel, mini, x, y);
	final_pixel.hit_pos = scale_tuple(&temp_pixel.ray.orient, 100000);
	final_pixel.hit_normal = create_vector(0, 1, 0);
	final_pixel.rgb = create_rgb(0, 0, 0);
	find_all_intersections(&temp_pixel, &final_pixel, mini);
	copy_pixel_hit(&temp_pixel, &final_pixel);
	find_ambient(mini, &temp_pixel);
	i = -1;
	if (vector_magnitude(&temp_pixel.hit_pos) < 999)
	{
		while (++i < mini->objs->count.light)
		{
			if (!check_for_shadow(mini, &temp_pixel.hit_pos,
					&mini->objs->lgts[i].pos))
			{
				find_diffuse(&temp_pixel, &mini->objs->lgts[i]);
				find_specular(&temp_pixel, &mini->objs->lgts[i]);
			}
		}
	}
	return (rgb_to_int(temp_pixel.rgb));
}

// /*
// 	Debugs a ray
// */
// void	print_ray(t_ray *ray)
// {
// 	print_tuple(&ray->orient, "Ray orient");
// 	print_tuple(&ray->origin, "Ray origin");
// }

// VVV VERY COOL FILTER VVV

// int	cast_ray(t_mini *mini, int x, int y)
// {
// 	t_pixel	temp_pixel;
// 	t_pixel	final_pixel;

// 	find_ray_orientation(&temp_pixel, mini, x, y);
// 	int i = -1;

// 	final_pixel.hit_pos = scale_tuple(&temp_pixel.ray.orient, 100000);
// 	final_pixel.hit_normal = create_vector(0,1,0);
// 	final_pixel.rgb = create_rgb(0,0,0);
// 	while(++i < mini->objs->count.sphere)
// 	{
// 		if (!find_sphere_intersect(&mini->objs->sprs[i], &temp_pixel))
// 		{
// 			if (distance_between_points(final_pixel.hit_pos, 
// temp_pixel.ray.origin) > 
// 					distance_between_points(temp_pixel.hit_pos,
//  temp_pixel.ray.origin))
// 			{
// 				final_pixel.hit_pos = temp_pixel.hit_pos;
// 				final_pixel.hit_normal = temp_pixel.hit_normal;
// 				final_pixel.rgb = mini->objs->sprs[i].rgb;
// 			}
// 		}
// 	}
// 	i = -1;
// 	while(++i < mini->objs->count.plane)
// 	{
// 		if (find_plane_intersect(&mini->objs->plns[i], &temp_pixel))
// 		{
// 			if (distance_between_points(final_pixel.hit_pos, 
// temp_pixel.ray.origin) > 
// 					distance_between_points(temp_pixel.hit_pos, 
// temp_pixel.ray.origin))
// 			{
// 				final_pixel.hit_pos = temp_pixel.hit_pos;
// 				final_pixel.hit_normal = temp_pixel.hit_normal;
// 				final_pixel.rgb = mini->objs->plns[i].rgb;
// 			}
// 		}
// 	}
// 	i = -1;
// 	while(++i < mini->objs->count.cylinder)
// 	{
// 		if (find_cylinder_intersect(&mini->objs->cyls[i], &temp_pixel))
// 		{
// 			if (distance_between_points(final_pixel.hit_pos, 
// temp_pixel.ray.origin) > 
// 					distance_between_points(temp_pixel.hit_pos, 
// temp_pixel.ray.origin))
// 			{
// 				final_pixel.hit_pos = temp_pixel.hit_pos;
// 				final_pixel.hit_normal = temp_pixel.hit_normal;
// 				final_pixel.rgb = mini->objs->cyls[i].rgb;
// 			}
// 		}
// 	}
// 	i = -1;
// 	while(++i < mini->objs->count.cylinder)
// 	{
// 		if (find_end_cap_intersect(&mini->objs->cyls[i], &temp_pixel))
// 		{
// 			if (distance_between_points(final_pixel.hit_pos,
//  temp_pixel.ray.origin) > 
// 					distance_between_points(temp_pixel.hit_pos, 
// temp_pixel.ray.origin))
// 			{
// 				final_pixel.hit_pos = temp_pixel.hit_pos;
// 				final_pixel.hit_normal  = temp_pixel.hit_normal;
// 				final_pixel.rgb = mini->objs->cyls[i].rgb;
// 			}
// 		}
// 	}
// 	temp_pixel.hit_pos = final_pixel.hit_pos;
// 	temp_pixel.hit_normal = final_pixel.hit_normal;
// 	temp_pixel.hit_rgb = final_pixel.rgb;
// 	find_ambient(mini, &final_pixel);
// 	i = 0;
// 	if (vector_magnitude(&final_pixel.hit_pos) < 999)
// 		while (i < mini->objs->count.light)
// 		{
// 			if(!check_for_shadow(mini, &final_pixel.hit_pos,
//  &mini->objs->lgts[i].pos))
// 			{
// 				find_diffuse(&final_pixel, &mini->objs->lgts[i]);
// 				find_specular(&final_pixel, &mini->objs->lgts[i]);
// 			}
// 			i++;
// 		}
// 	return (rgb_to_int(final_pixel.rgb));
// }

// VAULT

// int	cast_ray(t_mini *mini, int x, int y)
// {
// 	t_pixel	temp_pixel;
// 	t_pixel	final_pixel;

// 	find_ray_orientation(&temp_pixel, mini, x, y);
// 	int i = -1;

// 	final_pixel.hit_pos = 
// scale_tuple(&temp_pixel.ray.orient, 100000);
// 	final_pixel.hit_normal = create_vector(0,1,0);
// 	final_pixel.rgb = create_rgb(0,0,0);

// 	while(++i < mini->objs->count.sphere)
// 	{
// 		if (!find_sphere_intersect(&mini->objs->sprs[i], &temp_pixel))
// 		{
// 			if (distance_between_points(final_pixel.hit_pos,
//  temp_pixel.ray.origin) > 
// 					distance_between_points(temp_pixel.hit_pos, 
// temp_pixel.ray.origin))
// 			{
// 				final_pixel.hit_pos = temp_pixel.hit_pos;
// 				final_pixel.hit_normal = temp_pixel.hit_normal;
// 				final_pixel.rgb = mini->objs->sprs[i].rgb;
// 			}
// 		}
// 	}
// 	i = -1;
// 	while(++i < mini->objs->count.plane)
// 	{
// 		if (find_plane_intersect(&mini->objs->plns[i], &temp_pixel))
// 		{
// 			if (distance_between_points(final_pixel.hit_pos,
//  temp_pixel.ray.origin) > 
// 					distance_between_points(temp_pixel.hit_pos,
//  temp_pixel.ray.origin))
// 			{
// 				final_pixel.hit_pos = temp_pixel.hit_pos;
// 				final_pixel.hit_normal = temp_pixel.hit_normal;
// 				final_pixel.rgb = mini->objs->plns[i].rgb;
// 			}
// 		}
// 	}
// 	i = -1;
// 	while(++i < mini->objs->count.cylinder)
// 	{
// 		if (find_cylinder_intersect(&mini->objs->cyls[i], &temp_pixel))
// 		{
// 			if (distance_between_points(final_pixel.hit_pos, 
// temp_pixel.ray.origin) > 
// 					distance_between_points(temp_pixel.hit_pos, 
// temp_pixel.ray.origin))
			// {
// 				final_pixel.hit_pos = temp_pixel.hit_pos;
// 				final_pixel.hit_normal = temp_pixel.hit_normal;
// 				final_pixel.rgb = mini->objs->cyls[i].rgb;
// 			}
// 		}
// 	}
// 	i = -1;
// 	while(++i < mini->objs->count.cylinder)
// 	{
// 		if (find_end_cap_intersect(&mini->objs->cyls[i], &temp_pixel))
// 		{
// 			if (distance_between_points(final_pixel.hit_pos, 
// temp_pixel.ray.origin) > 
// 					distance_between_points(temp_pixel.hit_pos,
//  temp_pixel.ray.origin))
// 			{
// 				final_pixel.hit_pos = temp_pixel.hit_pos;
// 				final_pixel.hit_normal  = temp_pixel.hit_normal;
// 				final_pixel.rgb = mini->objs->cyls[i].rgb;
// 			}
// 		}
// 	}

// 	temp_pixel.hit_pos = final_pixel.hit_pos;
// 	temp_pixel.hit_normal = final_pixel.hit_normal;
// 	temp_pixel.hit_rgb = final_pixel.rgb;
// 	find_ambient(mini, &temp_pixel);
// 	i = 0;
// 	if (vector_magnitude(&temp_pixel.hit_pos) < 999)
// 		while (i < mini->objs->count.light)
// 		{
// 			if(!check_for_shadow(mini, &temp_pixel.hit_pos,
//  &mini->objs->lgts[i].pos))
// 			{
// 				find_diffuse(&temp_pixel, &mini->objs->lgts[i]);
// 				find_specular(&temp_pixel, &mini->objs->lgts[i]);
// 			}
// 			i++;
// 		}
// 	return (rgb_to_int(temp_pixel.rgb));
// }
