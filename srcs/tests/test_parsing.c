/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:25:23 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/08 16:41:58 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	test_parsing(void)
{
	t_objects	objects;

	printf("Testing parsing - spheres\n");
	objects.count.sphere = 0;
	objects.sprs = malloc(sizeof(t_sphere) * 2);
	if (!objects.sprs)
		return ;
	parse_object("sp 5,5,5 5 255,0,0", &objects);
	print_sphere(&objects.sprs[0]);
	parse_object("sp -5,-5,-5 -5 255,0,0", &objects);
	print_sphere(&objects.sprs[1]);
	free(objects.sprs);
	printf("Testing parsing - planes\n");
	objects.count.plane = 0;
	objects.plns = malloc(sizeof(t_plane) * 2);
	if (!objects.plns)
		return ;
	parse_object("pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225", &objects);
	print_plane(&objects.plns[0]);
	parse_object("pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225", &objects);
	print_plane(&objects.plns[0]);
	free(objects.plns);
}
