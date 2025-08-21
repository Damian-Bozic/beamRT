/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:12:44 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:12:45 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
	Converts a string into an object enum
*/
t_type	get_type(char *str)
{
	if (0 == ft_strcmp("a", str) || 0 == ft_strcmp("A", str))
		return (AMBIENT);
	if (0 == ft_strcmp("c", str) || 0 == ft_strcmp("C", str))
		return (CAMERA);
	if (0 == ft_strcmp("cy", str) || 0 == ft_strcmp("CY", str))
		return (CYLINDER);
	if (0 == ft_strcmp("l", str) || 0 == ft_strcmp("L", str))
		return (LIGHT);
	if (0 == ft_strcmp("pl", str) || 0 == ft_strcmp("PL", str))
		return (PLANE);
	if (0 == ft_strcmp("sp", str) || 0 == ft_strcmp("SP", str))
		return (SPHERE);
	if (0 == ft_strcmp("bm", str) || 0 == ft_strcmp("BM", str))
		return (BEAM);
	if (0 == ft_strcmp("mrr", str) || 0 == ft_strcmp("MRR", str))
		return (MIRROR);
	return (UNKNOWN);
}

/*
	Checks an object is well-formed
*/
static	int	check_object(char *line)
{
	char	**split;
	t_type	type;
	int		error_code;

	split = ft_split(line, ' ');
	type = get_type(split[0]);
	error_code = 0;
	if (AMBIENT == type)
		error_code = check_ambient(split);
	if (CAMERA == type)
		error_code = check_camera(split);
	if (CYLINDER == type)
		error_code = check_cylinder(split);
	if (LIGHT == type)
		error_code = check_light(split);
	if (PLANE == type)
		error_code = check_plane(split);
	if (SPHERE == type)
		error_code = check_sphere(split);
	if (BEAM == type)
		error_code = check_beam(split);
	if (MIRROR == type)
		error_code = check_mirror(split);
	ft_free_stringlist(split);
	return (error_code);
}

/*
	Checks if the file is good enough to continue
*/
int	check_file(char *filename)
{
	int		fd;
	char	*line;
	int		error_code;
	char	*trimmed;

	fd = open(filename, O_RDONLY);
	line = "";
	error_code = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			trimmed = ft_strtrim(line, "\n");
			free(line);
			if (ft_strlen(trimmed) > 0)
				error_code = check_object(trimmed);
			free(trimmed);
			if (0 != error_code)
				break ;
		}
	}
	close(fd);
	return (error_code);
}
