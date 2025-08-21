/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_shade.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:14:32 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:14:32 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// t_tuple temp_tuple;		0
// t_tuple closest_point;	1
// t_tuple hit_position;	2
// t_tuple B_to_A_vector;	3
static int	is_sp_blocking_light(t_sphere *sp, t_tuple *pnt_A, t_tuple *pnt_B)
{
	t_tuple	norm[4];
	float	t;
	float	ys;
	float	xs;

	norm[3] = subtract_tuples(pnt_B, pnt_A);
	norm[3] = normalise_vector(&norm[3]);
	norm[0] = subtract_tuples(&sp->pos, pnt_A);
	t = dot_product(&norm[0], &norm[3]);
	if (t < 0)
		return (0);
	norm[0] = scale_tuple(&norm[3], t);
	norm[1] = add_tuples(pnt_A, &norm[0]);
	ys = distance_between_points(sp->pos, norm[1]);
	if (ys > sp->diameter / 2)
		return (0);
	xs = sqrt(ft_pow(sp->diameter / 2, 2) - ft_pow(ys, 2));
	norm[0] = scale_tuple(&norm[3], t - xs);
	norm[2] = add_tuples(pnt_A, &norm[0]);
	if (distance_between_points(*pnt_A, norm[2])
		< distance_between_points(*pnt_A, *pnt_B))
		return (1);
	return (0);
}
// if (distance_between_points(*point_A, norm[2])
// < distance_between_points(*point_A, *point_B))
// might not be needed, not touching it though

static int	is_plane_blocking_l(t_plane *pln, t_tuple *pnt_A, t_tuple *pnt_B)
{
	float	temp;
	float	a_side_of_plane;
	float	b_side_of_plane;

	pln->normal = normalise_vector(&pln->normal);
	pln->normal.values[3] = 1.0;
	temp = -dot_product(&pln->normal, &pln->pos);
	a_side_of_plane = dot_product(&pln->normal, pnt_A);
	a_side_of_plane += temp;
	temp = -dot_product(&pln->normal, &pln->pos);
	b_side_of_plane = dot_product(&pln->normal, pnt_B);
	b_side_of_plane += temp;
	if ((a_side_of_plane > 0 && b_side_of_plane < 0)
		|| (a_side_of_plane < 0 && b_side_of_plane > 0))
	{
		if (!zero_epsilon_check(a_side_of_plane)
			|| !zero_epsilon_check(b_side_of_plane))
			return (0);
		return (1);
	}
	return (0);
}

int	check_for_shadow(t_mini *mini, t_tuple *point_A, t_tuple *point_B)
{
	int		i;
	t_tuple	a_and_b[2];

	a_and_b[0] = *point_A;
	a_and_b[1] = *point_B;
	i = -1;
	while (++i < mini->objs->count.sphere)
		if (is_sp_blocking_light(&mini->objs->sprs[i], point_A, point_B))
			return (1);
	i = -1;
	while (++i < mini->objs->count.plane)
		if (is_plane_blocking_l(&mini->objs->plns[i], point_A, point_B))
			return (1);
	if (is_cylinder_blocking_light(mini, point_A, point_B)
		|| is_cyl_cap_blocking_light(mini, a_and_b))
		return (1);
	return (0);
}
