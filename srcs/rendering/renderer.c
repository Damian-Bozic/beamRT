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

#include <sys/time.h>
#include <pthread.h>

typedef struct s_thread_info
{
	int				corenumber;
	int				**bitmap;
	t_mini			*mini;
	pthread_mutex_t *mutex;
	pthread_t		thread;
}	t_thread_info;

void *threaded_process(void *sent)
{
	t_thread_info	*info;
	int 			x;
	int				y;

	info = (t_thread_info *)sent;
	y = info->corenumber;
	while (y < SCREEN_Y)
	{
		x = -1;
		while (++x < SCREEN_X)
		{
			info->bitmap[y][x] = cast_ray(info->mini, x, y);
		}
		y += N_OF_CORES;
	}
	return(NULL);
}

static int	**init_bitmap(void)
{
	int	x;
	int	y;
	int	**bitmap;

	bitmap = (int **)malloc(sizeof(int *) * SCREEN_Y);
	if (!bitmap)
		return (NULL);
	y = 0;
	while (y < SCREEN_Y)
	{
		bitmap[y] = (int *)malloc(sizeof(int) * SCREEN_X);
		if (!bitmap[y])
			return (NULL);
		x = 0;
		while (x < SCREEN_X)
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
	info = malloc (sizeof(t_thread_info) * N_OF_CORES);
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
	int		x;
	int		y;
	int		**bitmap;
	char	*data;

	//DEBUG TODO
	struct timeval				*tv1;
	struct timeval				*tv2;
	tv1 = malloc(sizeof(struct timeval));
	tv2 = malloc(sizeof(struct timeval));
	gettimeofday(tv1, NULL);

	x = 0;
	y = 0;
	bitmap = make_bitmap(mini);
	data = mlx_get_data_addr(mini->img_buf, &mini->bpp,
			&mini->size_line, &mini->endian);
	while (y != SCREEN_Y * RES_SCALE)
	{
		while (x != SCREEN_X * RES_SCALE)
		{
			// colour = cast_ray(mini, x, y);
			ft_pixel_put_img(mini, data, x, y, bitmap[y/RES_SCALE][x/RES_SCALE]);
			x++;
		}
		x = 0;
		y++;
	}

	//DEBUG TODO
	gettimeofday(tv2, NULL);
	long seconds = tv2->tv_sec - tv1->tv_sec;
	long usec = tv2->tv_usec - tv1->tv_usec;
	if (usec < 0) {
		seconds -= 1;
		usec += 1000000;
	}
	printf("bitmap generated in %lds and %ldms\n", seconds, usec / 1000);
	mlx_put_image_to_window(mini->mlx, mini->win, mini->img_buf, 0, 0);
}
