/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:12:54 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:12:54 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
	Checks whether there is only one of an object, if needed
*/
static int	check_uniqueness(int normal, int unique)
{
	if (0 == unique || (0 == normal && 1 == unique))
		return (0);
	else
		return (1);
}

/*
	Prepares the objects container for parsing
*/
void	init_objects(t_count *count, t_count *unique, t_objects *objects)
{
	init_count(&objects->count);
	objects->amb = malloc(sizeof(t_ambient)
			* (count->ambient + unique->ambient));
	objects->cams = malloc(sizeof(t_camera)
			* (count->camera + unique->camera));
	objects->cyls = malloc(sizeof(t_cyl)
			* (count->cylinder + unique->cylinder));
	objects->lgts = malloc(sizeof(t_light)
			* (count->light + unique->light));
	objects->plns = malloc(sizeof(t_plane)
			* (count->plane + unique->plane));
	objects->sprs = malloc(sizeof(t_sphere)
			* (count->sphere + unique->sphere));
	objects->bms = malloc(sizeof(t_beam)
			* (count->beam + unique->beam));
	objects->mrrs = malloc(sizeof(t_mirror)
			* (count->mirror + unique->mirror));
}

/*
	Checks if object uniqueness is respected
*/
int	check_count(t_count *count, t_count *unique)
{
	int	error_code;

	error_code = check_uniqueness(count->ambient, unique->ambient)
		+ check_uniqueness(count->camera, unique->camera)
		+ check_uniqueness(count->cylinder, unique->cylinder)
		+ check_uniqueness(count->light, unique->light)
		+ check_uniqueness(count->plane, unique->plane)
		+ check_uniqueness(count->sphere, unique->sphere)
		+ check_uniqueness(count->beam, unique->beam)
		+ check_uniqueness(count->mirror, unique->mirror);
	if (0 == error_code)
		return (0);
	else
		return (BAD_UNIQUE);
}

/*
	Sets all the counts to 0;
*/
void	init_count(t_count *count)
{
	count->ambient = 0;
	count->camera = 0;
	count->cylinder = 0;
	count->light = 0;
	count->plane = 0;
	count->sphere = 0;
	count->beam = 0;
	count->mirror = 0;
}
