/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_between_points.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:14:47 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:14:47 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	distance_between_points(t_tuple point_a, t_tuple point_b)
{
	float	distance;
	t_tuple	temp;

	temp = subtract_tuples(&point_a, &point_b);
	distance = sqrt(ft_pow(temp.values[0], 2) + ft_pow(temp.values[1], 2)
			+ ft_pow(temp.values[2], 2));
	return (distance);
}
