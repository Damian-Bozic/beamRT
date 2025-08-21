/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_full.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:10:12 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:10:12 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
	Creates a new tuple and fills it with values
*/
t_tuple	create_tuple(float x, float y, float z, float w)
{
	t_tuple		vector;

	vector.values[0] = x;
	vector.values[1] = y;
	vector.values[2] = z;
	vector.values[3] = w;
	return (vector);
}

/*
	Creates a new vector and fills it with values
*/
t_tuple	create_vector(float x, float y, float z)
{
	t_tuple		vector;

	vector.values[0] = x;
	vector.values[1] = y;
	vector.values[2] = z;
	vector.values[3] = 0.0f;
	return (vector);
}

/*
	Creates a new point and fills it with values
*/
t_tuple	create_point(float x, float y, float z)
{
	t_tuple		point;

	point.values[0] = x;
	point.values[1] = y;
	point.values[2] = z;
	point.values[3] = 1.0f;
	return (point);
}

/*
	Creates a new point from a string of values
*/
t_tuple	create_vector_from_str(char *str)
{
	t_tuple		vector;
	char		**split;

	split = ft_split(str, ',');
	vector.values[0] = ft_strtof(split[0]);
	vector.values[1] = ft_strtof(split[1]);
	vector.values[2] = ft_strtof(split[2]);
	vector.values[3] = 0.0f;
	ft_free_stringlist(split);
	return (vector);
}

/*
	Creates a new point from a string of values
*/
t_tuple	create_point_from_str(char *str)
{
	t_tuple		point;
	char		**split;

	split = ft_split(str, ',');
	point.values[0] = ft_strtof(split[0]);
	point.values[1] = ft_strtof(split[1]);
	point.values[2] = ft_strtof(split[2]);
	point.values[3] = 1.0f;
	ft_free_stringlist(split);
	return (point);
}
