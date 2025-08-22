/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:08:15 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:08:16 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define VEC_SIZE 4

typedef enum e_type
{
	AMBIENT, //		a
	CAMERA, //		c
	CYLINDER, //	cy
	LIGHT, //		l
	PLANE, //		pl
	SPHERE, //		sp
	BEAM, //		bm
	MIRROR, //		mrr
	UNKNOWN
}	t_type;

typedef struct s_tuple
{
	float	values[VEC_SIZE];
}	t_tuple;

typedef struct s_matrix
{
	float			vals[VEC_SIZE][VEC_SIZE];
	unsigned int	size;
}	t_matrix;

typedef struct s_rgb
{
	int	r; // 0 -> 255
	int	g; // 0 -> 255
	int	b; // 0 -> 255
}	t_rgb;

typedef struct s_count
{
	int	ambient;
	int	camera;
	int	cylinder;
	int	light;
	int	plane;
	int	sphere;
	int	beam;
	int mirror;
}	t_count;

typedef struct s_ambient
{
	float	ratio; // 0.0 -> 1.0
	t_rgb	rgb;
}	t_ambient;

typedef struct s_camera
{
	t_tuple	pos;
	t_tuple	orient; // normalised, -1 -> 1 for each
	int		fov; // 0 -> 180
}	t_camera;

typedef struct s_cyl
{
	t_tuple	pos;
	t_tuple	axis; // normalised, -1 -> 1 for each
	float	diameter;
	float	height;
	t_rgb	rgb;
}	t_cyl;

typedef struct s_light
{
	t_tuple	pos;
	float	brightness; // 0.0 => 1.0
	t_rgb	rgb; // bonus only
}	t_light;

typedef struct s_plane
{
	t_tuple	pos;
	t_tuple	normal; // normalised, -1 -> 1 for each
	t_rgb	rgb;
}	t_plane;

typedef struct s_sphere
{
	t_tuple	pos;
	float	diameter;
	t_rgb	rgb;
}	t_sphere;

typedef struct s_beam
{
	t_tuple pos;
	t_tuple	normal;
	t_rgb	rgb;
	t_tuple	end_pos;
}	t_beam;

typedef struct s_mirror
{
	t_tuple pos;
	t_tuple normal;
	float	diameter;
	t_rgb	rgb;
}	t_mirror;

typedef struct s_objects
{
	t_ambient	*amb;
	t_camera	*cams;
	t_cyl		*cyls;
	t_light		*lgts;
	t_plane		*plns;
	t_sphere	*sprs;
	t_beam		*bms;
	t_mirror	*mrrs;
	t_count		count;
}	t_objects;

typedef struct s_ray
{
	// we have camera
	t_tuple	orient;
	t_tuple	origin;
}	t_ray;

typedef struct s_pixel
{
	t_tuple	hit_normal;
	t_tuple	hit_pos;
	t_rgb	hit_rgb;
	t_rgb	rgb;
	t_ray	ray; // can be made into ray[4] later for super sampling
}	t_pixel;

typedef struct s_mini
{
	void		*mlx;
	void		*win;
	void		*img_buf;
	int			bpp;
	int			size_line;
	int			endian;
	t_objects	*objs;
}	t_mini;

#endif
