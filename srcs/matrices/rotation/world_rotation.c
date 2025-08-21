/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:11:30 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:11:30 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_tuple	rotate_to_world2(t_tuple *z_orient, t_tuple *up, t_tuple *w_for)
{
	t_matrix	rotation;
	t_tuple		right;
	t_tuple		true_up;

	right = cross_product(up, w_for);
	right = normalise_vector(&right);
	true_up = cross_product(w_for, &right);
	rotation = identity_matrix();
	rotation.vals[0][0] = right.values[0];
	rotation.vals[1][0] = right.values[1];
	rotation.vals[2][0] = right.values[2];
	rotation.vals[0][1] = true_up.values[0];
	rotation.vals[1][1] = true_up.values[1];
	rotation.vals[2][1] = true_up.values[2];
	rotation.vals[0][2] = w_for->values[0];
	rotation.vals[1][2] = w_for->values[1];
	rotation.vals[2][2] = w_for->values[2];
	return (multiply_matrix_and_tuple(&rotation, z_orient));
}

t_tuple	rotate_to_world(t_tuple *world_orient, t_tuple *z_aligned_orient)
{
	t_tuple	world_forward;
	t_tuple	up_hint;

	world_forward = normalise_vector(world_orient);
	up_hint = create_vector(0, 1, 0);
	if (fabs(dot_product(&world_forward, &up_hint)) > 0.999f)
		up_hint = create_vector(1, 0, 0);
	return (rotate_to_world2(z_aligned_orient, &up_hint, &world_forward));
}
