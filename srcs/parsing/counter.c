/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:12:57 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:12:58 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
	Increments the count for an object
*/
static void	inc_object(char *str, t_count *count, t_count *unique)
{
	if (0 == ft_strcmp("a", str))
		count->ambient++;
	if (0 == ft_strcmp("c", str))
		count->camera++;
	if (0 == ft_strcmp("cy", str))
		count->cylinder++;
	if (0 == ft_strcmp("l", str))
		count->light++;
	if (0 == ft_strcmp("pl", str))
		count->plane++;
	if (0 == ft_strcmp("sp", str))
		count->sphere++;
	if (0 == ft_strcmp("A", str))
		unique->ambient++;
	if (0 == ft_strcmp("C", str))
		unique->camera++;
	if (0 == ft_strcmp("CY", str))
		unique->cylinder++;
	if (0 == ft_strcmp("L", str))
		unique->light++;
	if (0 == ft_strcmp("PL", str))
		unique->plane++;
	if (0 == ft_strcmp("SP", str))
		unique->sphere++;
}

/*
	Extracts the object type for counting
*/
static void	count_line(char *line, t_count *count, t_count *unique)
{
	char	**split;

	while (*line && (' ' == *line || '\t' == *line))
		line++;
	split = ft_split(line, ' ');
	inc_object(split[0], count, unique);
	ft_free_stringlist(split);
}

/*
	Checks whether the file has the right extension and is readable
*/
static int	valid_filename(char *filename)
{
	int	len;
	int	fd;

	len = ft_strlen(filename);
	if ('t' != filename[len - 1] || 'r' != filename[len - 2]
		|| '.' != filename[len - 3])
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

/*
	Counts how many of each object are in an .rt file
*/
int	count_objects(char *filename, t_count *count, t_count *unique)
{
	int		fd;
	char	*line;
	char	*trimmed;

	if (0 == valid_filename(filename))
		return (BAD_FILENAME);
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
				count_line(trimmed, count, unique);
			free(trimmed);
		}
	}
	close(fd);
	if (0 == count->camera + unique->camera)
		return (BAD_CAMERA);
	return (check_count(count, unique));
}
