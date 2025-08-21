/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:14:58 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:14:59 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ft_pixel_put_img(t_mini *mini, char *data, int x, int y, int colour)
{
	char	*pixel_addr;

	pixel_addr = data + (y * mini->size_line) + (x * (mini->bpp / 8));
	*(unsigned int *)pixel_addr = colour;
}

/*
	Debugs a pixel
*/
void	print_pixel(t_pixel *pixel)
{
	print_tuple(&pixel->hit_normal, "Pixel hit_normal:");
	print_tuple(&pixel->hit_pos, "Pixel hit_pos:");
	printf("Pixel rgb:\n");
	print_rgb(&pixel->rgb);
	printf("Pixel ray:\n");
	print_tuple(&pixel->ray.orient, "Ray orient");
	print_tuple(&pixel->ray.origin, "Ray origin");
}
