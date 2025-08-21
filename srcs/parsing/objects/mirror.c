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
int	check_mirror(char **split)
{
	if (5 != ft_count_array(split))
		return (BAD_MIRROR);
	if (BAD_INPUT == check_coordinates(split[1]))
		return (BAD_MIRROR);
	if (BAD_INPUT == check_float_range(split[2], -1, 1))
		return (BAD_MIRROR);
	if (BAD_INPUT == check_numbers(split[3]))
		return (BAD_MIRROR);
	if (BAD_INPUT == check_rgb(split[4]))
		return (BAD_MIRROR);
	return (0);
}

/*
	Creates from a line. Note this doesn't do any checking
*/
t_mirror	create_mirror(char *line)
{
	t_mirror	mirror;
	char		**split;

	split = ft_split(line, ' ');
	mirror.pos = create_point_from_str(split[1]);
	mirror.normal = create_point_from_str(split[2]);
	mirror.diameter = ft_strtof(split[3]);
	mirror.rgb = rgb_from_str(split[4]);
	ft_free_stringlist(split);
	return (mirror);
}

/*
	Debugs a cylinder
*/
void	print_mirror(t_mirror *mirror)
{
	print_tuple(&mirror->pos, "Mirror pos:");
	print_tuple(&mirror->normal, "Mirror axis:");
	printf("Mirror rgb: ");
	print_rgb(&mirror->rgb);
	printf("Mirror diameter: %f\n", mirror->diameter);
}
