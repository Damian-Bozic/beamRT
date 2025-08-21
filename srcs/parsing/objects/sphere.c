/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:13:46 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:13:47 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

/*
	Checks if the line has all the right elements
*/
int	check_sphere(char **split)
{
	if (4 != ft_count_array(split))
		return (BAD_SPHERE);
	if (BAD_INPUT == check_coordinates(split[1]))
		return (BAD_SPHERE);
	if (BAD_INPUT == check_numbers(split[2]))
		return (BAD_SPHERE);
	if (BAD_INPUT == check_rgb(split[3]))
		return (BAD_SPHERE);
	return (0);
}

/*
	Creates from a line. Note this doesn't do any checking
*/
t_sphere	create_sphere(char *line)
{
	t_sphere	sphere;
	char		**split;

	split = ft_split(line, ' ');
	sphere.pos = create_point_from_str(split[1]);
	sphere.diameter = ft_strtof(split[2]);
	sphere.rgb = rgb_from_str(split[3]);
	ft_free_stringlist(split);
	return (sphere);
}

/*
	Debugs sphere info
*/
void	print_sphere(t_sphere *sphere)
{
	print_tuple(&sphere->pos, "Sphere pos:");
	printf("Sphere rgb: ");
	print_rgb(&sphere->rgb);
	printf("Sphere diameter: %f\n", sphere->diameter);
}

// sp	0.0,0.0,20.6		12.6	10,0,255
// ∗ x,y,z coordinates of the sphere center
// ∗ the sphere diameter
// ∗ R,G,B colors in range [0-255]

// typedef struct s_sphere
// {
// 	t_tuple	pos;
// 	float	diameter;
// 	t_rgb	rgb;
// }	t_sphere;
