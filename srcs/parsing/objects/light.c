/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:13:41 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:13:42 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

/*
	Checks if the line has all the right elements
*/
int	check_light(char **split)
{
	float	brightness;

	if (4 != ft_count_array(split))
		return (BAD_LIGHT);
	if (BAD_INPUT == check_coordinates(split[1]))
		return (BAD_LIGHT);
	if (BAD_INPUT == check_numbers(split[2]))
		return (BAD_LIGHT);
	brightness = ft_strtof(split[2]);
	if (brightness < 0.0f || brightness > 1.0f)
		return (BAD_LIGHT);
	if (BAD_INPUT == check_rgb(split[3]))
		return (BAD_LIGHT);
	return (0);
}

/*
	Creates from a line. Note this doesn't do any checking
*/
t_light	create_light(char *line)
{
	t_light		light;
	char		**split;

	split = ft_split(line, ' ');
	light.pos = create_point_from_str(split[1]);
	light.brightness = ft_strtof(split[2]);
	light.rgb = rgb_from_str(split[3]);
	ft_free_stringlist(split);
	return (light);
}

/*
	Debugs a light
*/
void	print_light(t_light *light)
{
	print_tuple(&light->pos, "light pos:");
	printf("Light rgb: ");
	print_rgb(&light->rgb);
	printf("Light brightness: %f\n", light->brightness);
}

// L	-40.0,50.0,0.0		0.6		10,0,255
// ∗ x,y,z coordinates of the light point
// ∗ the light brightness ratio in range [0.0,1.0]
// ∗ (unused in mandatory part)R,G,B colors in range [0-255]

// typedef struct s_light
// {
// 	t_tuple	pos;
// 	float	brightness;
// 	t_rgb	rgb;
// }	t_light;
