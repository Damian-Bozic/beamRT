/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:13:07 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:13:08 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
	Parses the object and adds it to the list
*/
void	parse_object(char *line, t_objects *objects)
{
	char	**split;
	t_type	type;

	split = ft_split(line, ' ');
	type = get_type(split[0]);
	if (AMBIENT == type)
		objects->amb[objects->count.ambient++] = create_ambient(line);
	if (CAMERA == type)
		objects->cams[objects->count.camera++] = create_camera(line);
	if (CYLINDER == type)
		objects->cyls[objects->count.cylinder++] = create_cylinder(line);
	if (LIGHT == type)
		objects->lgts[objects->count.light++] = create_light(line);
	if (PLANE == type)
		objects->plns[objects->count.plane++] = create_plane(line);
	if (SPHERE == type)
		objects->sprs[objects->count.sphere++] = create_sphere(line);
	if (BEAM == type)
		objects->bms[objects->count.beam++] = create_beam(line);
	if (MIRROR == type)
		objects->mrrs[objects->count.mirror++] = create_mirror(line);
	ft_free_stringlist(split);
}

/*
	Clean up after malloc'ing objects
*/
void	free_objects(t_objects *objects)
{
	free(objects->amb);
	free(objects->cams);
	free(objects->cyls);
	free(objects->lgts);
	free(objects->plns);
	free(objects->sprs);
	free(objects->bms);
	free(objects->mrrs);
}

void	parse_file(char *filename, t_objects *objects)
{
	int		fd;
	char	*line;
	char	*trimmed;

	fd = open(filename, O_RDONLY);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			trimmed = ft_strtrim(line, "\n");
			free(line);
			if (ft_strlen(trimmed) > 0)
				parse_object(trimmed, objects);
			free(trimmed);
		}
	}
	close(fd);
}
