/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:13:00 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:13:00 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
	Prints an error when the object counting fails
*/
void	print_count_error_and_exit(int error_code)
{
	printf("Error\n");
	if (BAD_FILENAME == error_code)
		printf("Bad extension or unable to read file!\n");
	if (BAD_CAMERA == error_code)
		printf("Missing camera!\n");
	if (BAD_UNIQUE == error_code)
		printf("Too many unique objects!\n");
	exit(error_code);
}

/*
	Prints an error when the object parsing fails
*/
void	print_parse_error_and_exit(int error_code)
{
	printf("Error\n");
	if (BAD_AMBIENT == error_code)
		printf("An ambient object is malformed!\n");
	if (BAD_CAMERA == error_code)
		printf("A camera object is malformed!\n");
	if (BAD_CYLINDER == error_code)
		printf("A cylinder object is malformed!\n");
	if (BAD_LIGHT == error_code)
		printf("A light object is malformed!\n");
	if (BAD_PLANE == error_code)
		printf("A plane object is malformed!\n");
	if (BAD_SPHERE == error_code)
		printf("A sphere object is malformed!\n");
	exit(error_code);
}

/*
	Prints the counts for debugging
*/
void	print_object_counts(t_count *count, t_count *unique)
{
	printf(" Ambient: %3i (%3i unique)\n", count->ambient, unique->ambient);
	printf("  Camera: %3i (%3i unique)\n", count->camera, unique->camera);
	printf("Cylinder: %3i (%3i unique)\n", count->cylinder, unique->cylinder);
	printf("   Light: %3i (%3i unique)\n", count->light, unique->light);
	printf("   Plane: %3i (%3i unique)\n", count->plane, unique->plane);
	printf("  Sphere: %3i (%3i unique)\n", count->sphere, unique->sphere);
}

/*
	Displays a tuple in a line
*/
void	print_tuple(t_tuple *tuple, char *message)
{
	int	i;

	i = -1;
	printf("%s", message);
	printf("\t| ");
	while (++i < VEC_SIZE)
		printf("%10f ", tuple->values[i]);
	printf("|\n");
}

/*
	Displays a matrix in a grid
*/
void	print_matrix(t_matrix *matrix)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < matrix->size)
	{
		j = 0;
		if (0 == j)
			printf("| ");
		while (j < matrix->size)
		{
			printf("%10f ", matrix->vals[i][j]);
			j++;
		}
		if (j == matrix->size)
			printf("|\n");
		i++;
	}
}
