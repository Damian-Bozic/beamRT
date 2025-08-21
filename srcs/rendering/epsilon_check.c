/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epsilon_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:14:50 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:14:51 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	zero_epsilon_check(float input)
{
	double	temp;

	temp = input;
	if (input > 0)
	{
		temp -= EPSILON;
		if (temp > 0)
			return (1);
	}
	else
	{
		temp += EPSILON;
		if (temp < 0)
			return (1);
	}
	return (0);
}
// return (0) = close to 0
// return (1) = not close to 0
