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
int	check_beam(char **split)
{
	if (4 != ft_count_array(split))
		return (BAD_BEAM);
	if (BAD_INPUT == check_coordinates(split[1]))
		return (BAD_BEAM);
	if (BAD_INPUT == check_float_range(split[2], -1, 1))
		return (BAD_BEAM);
	if (BAD_INPUT == check_rgb(split[3]))
		return (BAD_BEAM);
	return (0);
}

/*
	Creates from a line. Note this doesn't do any checking
*/
t_beam	create_beam(char *line)
{
	t_beam	beam;
	char	**split;

	split = ft_split(line, ' ');
	beam.pos = create_point_from_str(split[1]);
	beam.normal = create_point_from_str(split[2]);
	beam.rgb = rgb_from_str(split[3]);
	ft_free_stringlist(split);
	return (beam);
}

/*
	Debugs a cylinder
*/
void	print_beam(t_beam *beam)
{
	print_tuple(&beam->pos, "Beam pos:");
	print_tuple(&beam->normal, "Beam normal:");
	printf("Beam rgb: ");
	print_rgb(&beam->rgb);
}
