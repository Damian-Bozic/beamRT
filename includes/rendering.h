/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:08:12 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:08:13 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "structs.h"

# define KEY_A 97
# define KEY_D 100
# define KEY_E 101
# define KEY_Q 113
# define KEY_S 115
# define KEY_W 119
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

// pixel
void	ft_pixel_put_img(t_mini *mini, char *data, int x, int y, int colour);
void	print_pixel(t_pixel *pixel);

// rays
float	distance_between_points(t_tuple point_a, t_tuple point_b);
void	find_ambient(t_mini *mini, t_pixel *pixel);
void	find_diffuse(t_pixel *pixel, t_light *light);
t_rgb	cast_ray(t_mini *mini, int x, int y);
// void	print_ray(t_ray *ray);

// basic maths
float	distance_between_points(t_tuple point_a, t_tuple point_b);
int		zero_epsilon_check(float input);

// render_plane
int		find_plane_intersect(t_plane *plane, t_pixel *pixel);

// render_sphere
t_tuple	find_sphere_normal(t_sphere *sphere, t_tuple *T);
int		find_sphere_intersect(t_sphere *sphere, t_pixel *pixel);

// render_cylinder
int		find_end_cap_intersect(t_cyl *cy, t_pixel *pixel);
int		find_cylinder_intersect(t_cyl *cylinder, t_pixel *pixel);
int		end_cap2(t_cyl *cy, t_pixel *p, t_tuple *cap_pos, t_tuple *hit);

// render_shadow
int		is_cyl_cap_blocking_light(t_mini *mini, t_tuple *A_B);
int		is_cylinder_blocking_light(t_mini *mini, t_tuple *point_A,
			t_tuple *point_B);
int		check_for_shadow(t_mini *mini, t_tuple *point_A, t_tuple *point_B);

// renderer
void	render_frame(t_mini *mini);

#endif
