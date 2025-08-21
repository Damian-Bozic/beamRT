/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:08:09 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:08:10 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structs.h"

// count error codes
# define BAD_FILENAME 1
# define BAD_CAMERA 2
# define BAD_UNIQUE 3

// parse error codes
# define BAD_INPUT 4
# define BAD_AMBIENT 5
# define BAD_CYLINDER 6
# define BAD_LIGHT 7
# define BAD_PLANE 8
# define BAD_SPHERE 9

// check_utils
int			check_float_range(char *str, int min, int max);
int			check_positive_ints(char *str);
int			check_numbers(char *str);
int			check_coordinates(char *str);

// checker
t_type		get_type(char *str);
int			check_file(char *filename);

// count
void		init_objects(t_count *count, t_count *unique, t_objects *objects);
int			check_count(t_count *count, t_count *unique);
void		init_count(t_count *count);

// counter
int			count_objects(char *filename, t_count *count, t_count *unique);

// log
void		print_object_counts(t_count *count, t_count *unique);
void		print_count_error_and_exit(int error_code);
void		print_parse_error_and_exit(int error_code);

// parser
void		parse_object(char *line, t_objects *objects);
void		free_objects(t_objects *objects);
void		parse_file(char *filename, t_objects *objects);

// rgb
int			check_rgb(char *str);
int			rgb_to_int(t_rgb rgb);
t_rgb		create_rgb(int r, int g, int b);
t_rgb		rgb_from_str(char *str);
void		print_rgb(t_rgb *rgb);

// ambient
int			check_ambient(char **split);
t_ambient	create_ambient(char *line);
void		print_ambient(t_ambient *ambient);

// camera
int			check_camera(char **split);
t_camera	create_camera(char *line);
void		print_camera(t_camera *camera);

// cylinder
int			check_cylinder(char **split);
t_cyl		create_cylinder(char *line);
void		print_cylinder(t_cyl *cylinder);

// light
int			check_light(char **split);
t_light		create_light(char *line);
void		print_light(t_light *light);

// plane
int			check_plane(char **split);
t_plane		create_plane(char *line);
void		print_plane(t_plane *plane);

// sphere
int			check_sphere(char **split);
t_sphere	create_sphere(char *line);
void		print_sphere(t_sphere *sphere);

#endif
