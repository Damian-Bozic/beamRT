/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:08:02 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:08:06 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "parsing.h"
# include "rendering.h"
# include "structs.h"
# include "tests.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define EPSILON 0.00001

# define SCREEN_X 1820
# define SCREEN_Y 1024

// # define SCREEN_X 1280
// # define SCREEN_Y 720

// # define SCREEN_X 480
// # define SCREEN_Y 720

// # define SCREEN_X 480
// # define SCREEN_Y 270
// # define RES_SCALE 4

// # define SCREEN_X 240
// # define SCREEN_Y 135

// # define SCREEN_X 240
// # define SCREEN_Y 160

// # define SCREEN_X 80
// # define SCREEN_Y 50

# define RES_SCALE 4
// 1 2 4 8

# define DOTTED 0
// 0 1

# define MSAA 1
// 1 2 4 8 16

# define N_OF_CORES 20
// use the amount of physical cores your computer
//	has for optimal speed

# define MOUSE_MOVE 1
// 0 1

# define MOUSE_SENSE 0.5

// calculate_light
void		find_specular(t_pixel *pixel, t_light *light);
void		find_diffuse(t_pixel *pixel, t_light *light);
void		find_ambient(t_mini *mini, t_pixel *pixel);
void		rgb_clamp(t_rgb *rgb);

// add-subtract
t_tuple		add_tuples(t_tuple *orig, t_tuple *other);
t_tuple		subtract_tuples(t_tuple *orig, t_tuple *other);

// cofactor
float		determinant(t_matrix *matrix);
t_matrix	submatrix(t_matrix *matrix, unsigned int del_row,
				unsigned int del_col);
float		minor_3x3(t_matrix *matrix, unsigned int row, unsigned int col);
float		minor_4x4(t_matrix *matrix, unsigned int row, unsigned int col);
float		cofactor(t_matrix *matrix, unsigned int row, unsigned int col);

// create_empty
t_tuple		create_empty_tuple(void);
t_tuple		create_empty_point(void);
t_tuple		create_empty_vector(void);
t_matrix	create_empty_matrix(void);

// create_full
t_tuple		create_tuple(float x, float y, float z, float w);
t_tuple		create_vector(float x, float y, float z);
t_tuple		create_point(float x, float y, float z);
t_tuple		create_vector_from_str(char *str);
t_tuple		create_point_from_str(char *str);
t_matrix	create_matrix(const float *values);

// equality
int			are_floats_equal(float f1, float f2);
int			are_tuples_equal(t_tuple *v1, t_tuple *v2);
int			are_matrices_equal(t_matrix *m1, t_matrix *m2);

// inversion
t_tuple		invert_tuple(t_tuple *orig);
int			is_invertible(t_matrix *matrix);
t_matrix	invert(t_matrix *matrix);

// misc
float		vector_magnitude(t_tuple *vector);
t_tuple		normalise_vector(t_tuple *vector);
t_matrix	transpose_matrix(t_matrix *matrix);
t_matrix	identity_matrix(void);
t_tuple		rotate_to_world_orientation(t_tuple *world_orient,
				t_tuple *z_aligned_orient);
int			zero_epsilon_check(float input);

// mlx_handling
void		init_mlx(t_mini *mini);

// multiplication
float		dot_product(t_tuple *vector1, t_tuple *vector2);
t_tuple		cross_product(t_tuple *vector1, t_tuple *vector2);
t_tuple		multiply_matrix_and_tuple(t_matrix *matrix, t_tuple *tuple);
t_matrix	multiply_matrices(t_matrix *matrix, t_matrix *other);

// translation
t_tuple		scale_tuple(t_tuple *orig, float scalar);
t_matrix	translation(float x, float y, float z);
t_matrix	scaling(float x, float y, float z);

// x-/y-/z-rotation
t_matrix	x_rotation_degrees(double degrees);
t_matrix	x_rotation_radians(double radians);
t_matrix	y_rotation_degrees(double degrees);
t_matrix	y_rotation_radians(double radians);
t_matrix	z_rotation_degrees(double degrees);
t_matrix	z_rotation_radians(double radians);
t_tuple		rotate_x_degrees(t_tuple *tuple, double degrees);
t_tuple		rotate_x_radians(t_tuple *tuple, double radians);
t_tuple		rotate_y_degrees(t_tuple *tuple, double degrees);
t_tuple		rotate_y_radians(t_tuple *tuple, double radians);
t_tuple		rotate_z_degrees(t_tuple *tuple, double degrees);
t_tuple		rotate_z_radians(t_tuple *tuple, double radians);
t_tuple		rotate_to_world(t_tuple *world_orient, t_tuple *z_aligned_orient);

#endif
