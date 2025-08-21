/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:21:58 by lwillis           #+#    #+#             */
/*   Updated: 2025/03/01 16:04:23 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
	Returns nb to the power power
*/
float	ft_pow(float nb, float power)
{
	if (power < 0)
		return (0);
	if (0 == power)
		return (1);
	return (nb * ft_pow(nb, power - 1));
}
