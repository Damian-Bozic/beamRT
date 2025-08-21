/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:13:10 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:13:11 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	check_rgb(char *str)
{
	char	**split;
	int		error_code;
	int		value;
	int		i;

	split = ft_split(str, ',');
	if (3 != ft_count_array(split))
	{
		ft_free_stringlist(split);
		return (BAD_INPUT);
	}
	i = -1;
	error_code = 0;
	while (split[++i])
	{
		if (BAD_INPUT == check_positive_ints(split[i]))
			error_code = BAD_INPUT;
		value = ft_strtof(split[i]);
		if (value < 0 || value > 255)
			error_code = BAD_INPUT;
	}
	ft_free_stringlist(split);
	return (error_code);
}

int	rgb_to_int(t_rgb rgb)
{
	int	hex;

	hex = rgb.r;
	hex = (hex << 8) + rgb.g;
	hex = (hex << 8) + rgb.b;
	return (hex);
}

t_rgb	create_rgb(int r, int g, int b)
{
	t_rgb	rtn;

	rtn.r = r;
	rtn.g = g;
	rtn.b = b;
	return (rtn);
}

t_rgb	rgb_from_str(char *str)
{
	t_rgb	result;
	char	**split;

	split = ft_split(str, ',');
	result.r = ft_atoi(split[0]);
	result.g = ft_atoi(split[1]);
	result.b = ft_atoi(split[2]);
	ft_free_stringlist(split);
	return (result);
}

/*
	Debugs an rgb struct
*/
void	print_rgb(t_rgb *rgb)
{
	printf("\tr: %i g: %i b: %i\n", rgb->r, rgb->g, rgb->b);
}
