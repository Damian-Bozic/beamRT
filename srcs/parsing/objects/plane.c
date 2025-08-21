/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:13:44 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:13:45 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

/*
	Checks if the line has all the right elements
*/
int	check_plane(char **split)
{
	if (4 != ft_count_array(split))
		return (BAD_PLANE);
	if (BAD_INPUT == check_coordinates(split[1]))
		return (BAD_PLANE);
	if (BAD_INPUT == check_float_range(split[2], -1, 1))
		return (BAD_PLANE);
	if (BAD_INPUT == check_rgb(split[3]))
		return (BAD_PLANE);
	return (0);
}

/*
	Creates from a line. Note this doesn't do any checking
*/
t_plane	create_plane(char *line)
{
	t_plane		plane;
	char		**split;

	split = ft_split(line, ' ');
	plane.pos = create_point_from_str(split[1]);
	plane.normal = create_point_from_str(split[2]);
	plane.rgb = rgb_from_str(split[3]);
	ft_free_stringlist(split);
	return (plane);
}

/*
	Debugs a plane
*/
void	print_plane(t_plane *plane)
{
	print_tuple(&plane->pos, "Plane pos:");
	print_tuple(&plane->normal, "Plane normal:");
	printf("Plane rgb:\n");
	print_rgb(&plane->rgb);
}

// pl	0.0,0.0,-10.0	0.0,1.0,0.0		0,0,225
// ∗ x,y,z coordinates of a point in the plane
// ∗ 3d normalized normal vector. In range [-1,1] for each x,y,z axis
// ∗ R,G,B colors in range [0-255]

// typedef struct s_plane
// {
// 	t_tuple	pos;
// 	t_tuple	normal;
// 	t_rgb	rgb;
// }	t_plane;
