/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:09:00 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:09:01 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	bad_input(int argc)
{
	if (argc == 1)
		printf("Error\nNo map file specified\n");
	else
		printf("Error\nToo many inputs");
	return (1);
}

/*
	Here we go...
*/
int	main(int argc, char **argv)
{
	t_count		count;
	t_count		unique;
	t_objects	objects;
	t_mini		mini;
	int			error_code;

	if (argc != 2)
		return (bad_input(argc));
	if (SCREEN_X <= 0 || SCREEN_Y <= 0 || SCREEN_X > 1920 || SCREEN_Y > 1080)
		printf("Error\nBad Screen Size\n");
	if (SCREEN_X <= 0 || SCREEN_Y <= 0 || SCREEN_X > 1920 || SCREEN_Y > 1080)
		return (0);
	init_count(&count);
	init_count(&unique);
	error_code = count_objects(argv[1], &count, &unique);
	if (0 != error_code)
		print_count_error_and_exit(error_code);
	error_code = check_file(argv[1]);
	if (0 != error_code)
		print_parse_error_and_exit(error_code);
	init_objects(&count, &unique, &objects);
	// print_object_counts(&count, &unique);
	parse_file(argv[1], &objects);
	mini.objs = &objects;
	init_mlx(&mini);
	return (0);
}
