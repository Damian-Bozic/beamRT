/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:15:07 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:15:08 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <pthread.h>
#include <sys/time.h>

typedef struct s_thread_info
{
	int				corenumber;
	int				**bitmap;
	t_mini			*mini;
	pthread_mutex_t	*mutex;
	pthread_t		thread;
}					t_thread_info;

void	*threaded_process(void *sent)
{
	t_thread_info	*info;
	int				x;
	int				y;
	int				i;
	t_rgb			sub_colour[16];
	t_rgb			final_rgb;
	int				j;

	static const float ss_offsets[16][2] = {
		// --- MSAA 2 ---
		{0.0625f, -0.1875f}, // S0
		{-0.0625f, 0.1875f}, // S1
		// --- MSAA 4 ---
		{0.3125f, -0.0625f},  // S2
		{-0.1875f, -0.3125f}, // S3
		// --- MSAA 8 ---
		{-0.3125f, 0.3125f},  // S4
		{-0.4375f, -0.0625f}, // S5
		{0.4375f, 0.0625f},   // S6
		{0.1875f, 0.4375f},   // S7
		// --- MSAA 16 ---
		{0.3750f, -0.3125f},  // S8
		{-0.3750f, -0.4375f}, // S9
		{-0.2500f, -0.1250f}, // S10
		{0.0f, 0.3750f},      // S11
		{0.2500f, 0.1250f},   // S12
		{-0.1250f, -0.3750f}, // S13
		{0.1250f, 0.2500f},   // S14
		{-0.0625f, 0.0f}      // S15
	};
	info = (t_thread_info *)sent;
	y = info->corenumber;
	while (y < SCREEN_Y / (RES_SCALE * RES_SCALE))
	{
		for (x = 0; x < SCREEN_X / (RES_SCALE * RES_SCALE); x++)
		{
			for (i = 0; i < MSAA; i++)
			{
				sub_colour[i] = cast_ray(info->mini, x * (RES_SCALE * RES_SCALE)
						+ ss_offsets[i][0], y * (RES_SCALE * RES_SCALE)
						+ ss_offsets[i][1]);
			}
			final_rgb.r = 0;
			final_rgb.g = 0;
			final_rgb.b = 0;
			for (i = 0; i < MSAA; i++)
			{
				final_rgb.r += sub_colour[i].r;
				final_rgb.g += sub_colour[i].g;
				final_rgb.b += sub_colour[i].b;
			}
			final_rgb.r /= MSAA;
			final_rgb.g /= MSAA;
			final_rgb.b /= MSAA;
			if (DOTTED)
				info->bitmap[y * RES_SCALE][x
					* RES_SCALE] = rgb_to_int(final_rgb);
			else
			{
				j = 0;
				for (i = 0; i < RES_SCALE; i++)
					for (j = 0; j < RES_SCALE; j++)
					{
						info->bitmap[(y * RES_SCALE) + i][(x * RES_SCALE)
							+ j] = rgb_to_int(final_rgb);
					}
			}
		}
		printf("Row %d out of %d complete (%.2f%%)\n", y + 1, SCREEN_Y
			/ (RES_SCALE * RES_SCALE), ((float)y / (float)(SCREEN_Y / (RES_SCALE
						* RES_SCALE)) * 100.0f));
		y += N_OF_CORES;
	}
	return (NULL);
}

static int	**init_bitmap(void)
{
	int	x;
	int	y;
	int	**bitmap;

	bitmap = (int **)malloc(sizeof(int *) * (SCREEN_Y / RES_SCALE));
	if (!bitmap)
		return (NULL);
	y = 0;
	while (y < SCREEN_Y / RES_SCALE)
	{
		bitmap[y] = (int *)malloc(sizeof(int) * (SCREEN_X / RES_SCALE));
		if (!bitmap[y])
			return (NULL);
		x = 0;
		while (x < SCREEN_X / RES_SCALE)
		{
			bitmap[y][x] = 0;
			x++;
		}
		y++;
	}
	return (bitmap);
}

int	**make_bitmap(t_mini *mini)
{
	int				**bitmap;
	t_thread_info	*info;
	pthread_mutex_t	*mutex;
	int				i;

	bitmap = init_bitmap();
	info = malloc(sizeof(t_thread_info) * N_OF_CORES);
	mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex, NULL); // TODO guard this too :D
	i = 0;
	while (i < N_OF_CORES)
	{
		info[i].bitmap = bitmap;
		info[i].corenumber = i;
		info[i].mutex = mutex;
		info[i].mini = mini;
		pthread_create(&info[i].thread, NULL, threaded_process, &info[i]);
		i++;
	}
	i = 0;
	while (i < N_OF_CORES)
	{
		pthread_join(info[i].thread, NULL);
		i++;
	}
	return (bitmap);
}

void	render_frame(t_mini *mini)
{
	int				x;
	int				y;
	int				**bitmap;
	char			*data;
	struct timeval	*tv1;
	struct timeval	*tv2;
	long			seconds;
	long			usec;

	// DEBUG TODO
	tv1 = malloc(sizeof(struct timeval));
	tv2 = malloc(sizeof(struct timeval));
	gettimeofday(tv1, NULL);
	x = 0;
	y = 0;
	bitmap = make_bitmap(mini);
	data = mlx_get_data_addr(mini->img_buf, &mini->bpp, &mini->size_line,
			&mini->endian);
	while (y != SCREEN_Y)
	{
		while (x != SCREEN_X)
		{
			// colour = cast_ray(mini, x, y);
			ft_pixel_put_img(mini, data, x, y, bitmap[y / RES_SCALE][x
				/ RES_SCALE]);
			x++;
		}
		x = 0;
		y++;
	}
	// DEBUG TODO
	gettimeofday(tv2, NULL);
	seconds = tv2->tv_sec - tv1->tv_sec;
	usec = tv2->tv_usec - tv1->tv_usec;
	if (usec < 0)
	{
		seconds -= 1;
		usec += 1000000;
	}
	printf("bitmap generated in %lds and %ldms\n", seconds, usec / 1000);
	mlx_put_image_to_window(mini->mlx, mini->win, mini->img_buf, 0, 0);
}
