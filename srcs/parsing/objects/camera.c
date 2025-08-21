/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:13:36 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:13:37 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

/*
	Checks if the line has all the right elements
*/
int	check_camera(char **split)
{
	int		degrees;

	if (4 != ft_count_array(split))
		return (BAD_CAMERA);
	if (BAD_INPUT == check_coordinates(split[1]))
		return (BAD_CAMERA);
	if (BAD_INPUT == check_float_range(split[2], -1, 1))
		return (BAD_CAMERA);
	if (BAD_INPUT == check_positive_ints(split[3]))
		return (BAD_CAMERA);
	degrees = ft_atoi(split[3]);
	if (degrees < 0 || degrees > 180)
		return (BAD_CAMERA);
	return (0);
}

/*
	Creates from a line. Note this doesn't do any checking
*/
t_camera	create_camera(char *line)
{
	t_camera	camera;
	char		**split;

	split = ft_split(line, ' ');
	camera.pos = create_point_from_str(split[1]);
	camera.orient = create_vector_from_str(split[2]);
	camera.fov = ft_strtof(split[3]);
	ft_free_stringlist(split);
	return (camera);
}

/*
	Debugs camera info
*/
void	print_camera(t_camera *camera)
{
	print_tuple(&camera->pos, "Camera pos:");
	print_tuple(&camera->orient, "Camera orient:");
	printf("Camera FOV: %i\n", camera->fov);
}

// C	-50.0,0,20		0,0,1	70
// ∗ x,y,z coordinates of the view point
// ∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis
// ∗ FOV : Horizontal field of view in degrees in range [0,180]

// typedef struct s_camera
// {
// 	t_tuple	pos;
// 	t_tuple	orient;
// 	int		fov;
// }	t_camera;
