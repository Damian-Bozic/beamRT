/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:13:39 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:13:39 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

/*
	Checks if the line has all the right elements
*/
int	check_cylinder(char **split)
{
	if (6 != ft_count_array(split))
		return (BAD_CYLINDER);
	if (BAD_INPUT == check_coordinates(split[1]))
		return (BAD_CYLINDER);
	if (BAD_INPUT == check_float_range(split[2], -1, 1))
		return (BAD_CYLINDER);
	if (BAD_INPUT == check_numbers(split[3]))
		return (BAD_CYLINDER);
	if (BAD_INPUT == check_numbers(split[4]))
		return (BAD_CYLINDER);
	if (BAD_INPUT == check_rgb(split[5]))
		return (BAD_CYLINDER);
	return (0);
}

/*
	Creates from a line. Note this doesn't do any checking
*/
t_cyl	create_cylinder(char *line)
{
	t_cyl	cylinder;
	char	**split;

	split = ft_split(line, ' ');
	cylinder.pos = create_point_from_str(split[1]);
	cylinder.axis = create_point_from_str(split[2]);
	cylinder.diameter = ft_strtof(split[3]);
	cylinder.height = ft_strtof(split[4]);
	cylinder.rgb = rgb_from_str(split[5]);
	ft_free_stringlist(split);
	return (cylinder);
}

/*
	Debugs a cylinder
*/
void	print_cylinder(t_cyl *cylinder)
{
	print_tuple(&cylinder->pos, "Cylinder pos:");
	print_tuple(&cylinder->axis, "Cylinder axis:");
	printf("Cylinder rgb:\n");
	print_rgb(&cylinder->rgb);
	printf("Cylinder diameter: %f\n", cylinder->diameter);
	printf("Cylinder height: %f\n", cylinder->height);
}

// cy	50.0,0.0,20.6	0.0,0.0,1.0		14.2	21.42	10,0,255
// ∗ x,y,z coordinates of the center of the cylinder
// ∗ 3d normalized vector of axis. In range [-1,1] for each x,y,z axis
// ∗ the cylinder diameter
// ∗ the cylinder height
// ∗ R,G,B colors in range [0,255]

// typedef struct s_cylinder
// {
// 	t_tuple	pos;
// 	t_tuple	axis;
// 	float	diameter;
// 	float	height;
// 	t_rgb	rgb;
// }	t_cyl;
