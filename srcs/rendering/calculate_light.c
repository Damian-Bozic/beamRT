/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:14:28 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:14:28 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	find_ambient(t_mini *mini, t_pixel *pixel)
{
	pixel->rgb.r = ((float)mini->objs->amb->rgb.r
			* mini->objs->amb->ratio * (float)pixel->hit_rgb.r) / 255;
	pixel->rgb.g = ((float)mini->objs->amb->rgb.g
			* mini->objs->amb->ratio * (float)pixel->hit_rgb.g) / 255;
	pixel->rgb.b = ((float)mini->objs->amb->rgb.b
			* mini->objs->amb->ratio * (float)pixel->hit_rgb.b) / 255;
}

void	rgb_clamp(t_rgb *rgb)
{
	if (rgb->r > 255)
		rgb->r = 255;
	else if (rgb->r < 0)
		rgb->r = 0;
	if (rgb->g > 255)
		rgb->g = 255;
	else if (rgb->g < 0)
		rgb->g = 0;
	if (rgb->b > 255)
		rgb->b = 255;
	else if (rgb->b < 0)
		rgb->b = 0;
}

void	find_diffuse(t_pixel *pixel, t_light *light)
{
	t_tuple	vector_to_light;
	float	diffuse_brightness;

	vector_to_light = subtract_tuples(&light->pos, &pixel->hit_pos);
	vector_to_light = normalise_vector(&vector_to_light);
	diffuse_brightness = dot_product(&pixel->hit_normal, &vector_to_light);
	if (diffuse_brightness > 0)
	{
		pixel->rgb.r += (pixel->hit_rgb.r * light->rgb.r
				* diffuse_brightness * light->brightness) / 255;
		pixel->rgb.g += (pixel->hit_rgb.g * light->rgb.g
				* diffuse_brightness * light->brightness) / 255;
		pixel->rgb.b += (pixel->hit_rgb.b * light->rgb.b
				* diffuse_brightness * light->brightness) / 255;
		rgb_clamp(&pixel->rgb);
	}
}

static int	find_theta(t_tuple *view_v, t_pixel *pix, t_light *li, float *theta)
{
	float	projection_scale;
	t_tuple	reflection_vector;
	t_tuple	hit_light;
	t_tuple	projected_hit;

	hit_light = subtract_tuples(&li->pos, &pix->hit_pos);
	hit_light = normalise_vector(&hit_light);
	projection_scale = dot_product(&pix->hit_normal, &hit_light);
	if (projection_scale < 0)
		return (1);
	projected_hit = scale_tuple(&pix->hit_normal, 2 * projection_scale);
	hit_light = invert_tuple(&hit_light);
	reflection_vector = add_tuples(&projected_hit, &hit_light);
	*theta = dot_product(&reflection_vector, view_v);
	return (0);
}

void	find_specular(t_pixel *pixel, t_light *light)
{
	float	theta_value;
	t_tuple	view_vector;
	float	specular_intensity;

	view_vector = subtract_tuples(&pixel->ray.origin, &pixel->hit_pos);
	view_vector = normalise_vector(&view_vector);
	if (find_theta(&view_vector, pixel, light, &theta_value))
		return ;
	if (theta_value > 0)
	{
		specular_intensity = powf(theta_value, 50.0f);
		pixel->rgb.r += specular_intensity * light->rgb.r
			* (float)pixel->hit_rgb.r / 255;
		pixel->rgb.g += specular_intensity * light->rgb.g
			* (float)pixel->hit_rgb.g / 255;
		pixel->rgb.b += specular_intensity * light->rgb.b
			* (float)pixel->hit_rgb.b / 255;
		rgb_clamp(&pixel->rgb);
	}
}
