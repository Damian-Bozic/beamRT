/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:13:34 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:13:35 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

/*
	Checks if the line has all the right elements
*/
int	check_ambient(char **split)
{
	float	ratio;

	if (3 != ft_count_array(split))
		return (BAD_AMBIENT);
	if (BAD_INPUT == check_numbers(split[1]))
		return (BAD_AMBIENT);
	ratio = ft_strtof(split[1]);
	if (ratio < 0.0f || ratio > 1.0f)
		return (BAD_AMBIENT);
	if (BAD_INPUT == check_rgb(split[2]))
		return (BAD_AMBIENT);
	return (0);
}

/*
	Creates from a line. Note this doesn't do any checking
*/
t_ambient	create_ambient(char *line)
{
	t_ambient	ambient;
	char		**split;

	split = ft_split(line, ' ');
	ambient.ratio = ft_strtof(split[1]);
	ambient.rgb = rgb_from_str(split[2]);
	ft_free_stringlist(split);
	return (ambient);
}

/*
	Debugs an ambient
*/
void	print_ambient(t_ambient *ambient)
{
	printf("Ambient rgb: ");
	print_rgb(&ambient->rgb);
	printf("Ambient ratio: %f\n", ambient->ratio);
}

// A	0.2		255,255,255
// ∗ ambient lighting ratio in range [0.0,1.0]
// ∗ R,G,B colors in range [0-255]

// typedef struct s_ambient
// {
// 	float	ratio;
// 	t_rgb	rgb;
// }	t_ambient;
