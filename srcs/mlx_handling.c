/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:09:03 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:09:04 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	clean_exit(t_mini *mini)
{
	free_objects(mini->objs);
	if (mini->img_buf)
		mlx_destroy_image(mini->mlx, mini->img_buf);
	if (mini->mlx && mini->win)
		mlx_destroy_window(mini->mlx, mini->win);
	if (mini->mlx)
	{
		mlx_destroy_display(mini->mlx);
		free(mini->mlx);
	}
	exit(0);
}

static void	handle_rotation_keys(int input, t_mini *mini)
{
	t_tuple	*orient;

	orient = &mini->objs->cams->orient;
	if (KEY_UP == input)
		mini->objs->cams->orient = rotate_x_degrees(orient, -10.0);
	if (KEY_DOWN == input)
		mini->objs->cams->orient = rotate_x_degrees(orient, 10.0);
	if (KEY_LEFT == input)
		mini->objs->cams->orient = rotate_y_degrees(orient, -10.0);
	if (KEY_RIGHT == input)
		mini->objs->cams->orient = rotate_y_degrees(orient, 10.0);
}

static int	detect_key_inputs(int input, t_mini *mini)
{
	if (KEY_ESC == input)
		clean_exit(mini);
	if (KEY_W == input)
		mini->objs->cams->pos.values[2] += 1;
	if (KEY_A == input)
		mini->objs->cams->pos.values[0] -= 1;
	if (KEY_S == input)
		mini->objs->cams->pos.values[2] -= 1;
	if (KEY_D == input)
		mini->objs->cams->pos.values[0] += 1;
	if (KEY_Q == input)
		mini->objs->cams->pos.values[1] += 1;
	if (KEY_E == input)
		mini->objs->cams->pos.values[1] -= 1;
	handle_rotation_keys(input, mini);
	// render_frame(mini);
	return (0);
}

/* int detect_mouse_movements(int x, int y, t_mini *mini)
{	
    t_tuple orient = mini->objs->cams->orient; // copy the current orientation
    int dx = x - SCREEN_X / 2;
    int dy = y - SCREEN_Y / 2;

    if (dy != 0) // vertical rotation
        orient = rotate_x_degrees(&orient, dy * MOUSE_SENSE);

    if (dx != 0) // horizontal rotation
        orient = rotate_y_degrees(&orient, dx * MOUSE_SENSE);

    mini->objs->cams->orient = orient;

    if (dx != 0 || dy != 0)
        mlx_mouse_move(mini->mlx, mini->win, SCREEN_X / 2, SCREEN_Y / 2);

    return (0);
} */
t_tuple rotate_around_axis_tuple(t_tuple *v, t_tuple *axis, float degrees)
{
    float rad = degrees * (M_PI / 180.0);
    t_tuple k = normalise_vector(axis);
    t_tuple v_parallel = scale_tuple(&k, dot_product(v, &k)); // component along axis
    t_tuple v_perp = subtract_tuples(v, &v_parallel);         // component perpendicular
    t_tuple w = cross_product(&k, &v_perp);

    t_tuple term1 = scale_tuple(&v_perp, cos(rad));
    t_tuple term2 = scale_tuple(&w, sin(rad));
    t_tuple result = add_tuples(&v_parallel, &term1);
    result = add_tuples(&result, &term2);

    return result;
}

int detect_mouse_movements(int x, int y, t_mini *mini)
{
    t_tuple forward = mini->objs->cams->orient;
    t_tuple world_up = create_vector(0, 1, 0);
    float dx = x - SCREEN_X / 2;
    float dy = y - SCREEN_Y / 2;
	dy = -dy;

    if (dx != 0 || dy != 0)
    {
        // --- YAW: horizontal rotation around world up ---
        if (dx != 0)
            forward = rotate_y_degrees(&forward, dx * MOUSE_SENSE);

        // --- compute camera right vector ---
        t_tuple right = cross_product(&world_up, &forward);
        right = normalise_vector(&right);

        // --- PITCH: vertical rotation around camera right axis ---
        if (dy != 0)
            forward = rotate_around_axis_tuple(&forward, &right, -dy * MOUSE_SENSE);

        // --- normalize and store orientation ---
        forward = normalise_vector(&forward);
        mini->objs->cams->orient = forward;

        // --- reset mouse to center ---
        mlx_mouse_move(mini->mlx, mini->win, SCREEN_X / 2, SCREEN_Y / 2);
    }
    return 0;
}


static int	detect_close(t_mini *mini)
{
	clean_exit(mini);
	return (0);
}

#include <sys/time.h>
#include <pthread.h>

long get_time_diff_in_ms(struct timeval *tv1, struct timeval *tv2)
{
	long usec_time_diff = tv2->tv_usec - tv1->tv_usec;
	long ms_time_diff;
	long sec_time_diff = tv2->tv_sec - tv1->tv_sec;

	if (usec_time_diff < 0)
	{
		sec_time_diff -= 1;
		usec_time_diff += 1000000;
	}
	ms_time_diff = (sec_time_diff * 1000) + (usec_time_diff / 1000);
	return (ms_time_diff);
}

int	temp_smoother(t_mini *mini)
{
	static struct timeval	*tv1 = NULL;
	static struct timeval	*tv2 = NULL;
	long					time_difference;

	if (tv1 == NULL)
	{
		tv1 = malloc(sizeof(struct timeval));
		tv2 = malloc(sizeof(struct timeval));
		gettimeofday(tv1, NULL);
	}
	gettimeofday(tv2, NULL);
	time_difference = get_time_diff_in_ms(tv1, tv2);
	if (time_difference > 1)
	{
		render_frame(mini);
		gettimeofday(tv1, NULL);
	}
	// printf("time_difference = %ldms\n", time_difference);
	return (0);
}
void	init_mlx(t_mini *mini)
{
	mini->mlx = mlx_init();
	// TEMP SCREEN SIZE INCREASE TODO
	mini->win = mlx_new_window(mini->mlx, SCREEN_X, SCREEN_Y,
			"Sisyphean RayTrace");
	mini->img_buf = mlx_new_image(mini->mlx, SCREEN_X, SCREEN_Y);
	mlx_string_put(mini->mlx, mini->win, (SCREEN_X / 2) - 96, (SCREEN_Y / 2)
		- 3, 0xFFFFCC, "A cylinder, a sphere, and a plane");
	mlx_string_put(mini->mlx, mini->win, (SCREEN_X / 2) - 120, (SCREEN_Y / 2)
		+ 9, 0xFFFFCC, "Caused the students a great deal of pain");
	mlx_string_put(mini->mlx, mini->win, (SCREEN_X / 2) - 63, (SCREEN_Y / 2)
		+ 21, 0xFFFFCC, "Ray_tracing's not fun");
	mlx_string_put(mini->mlx, mini->win, (SCREEN_X / 2) - 69, (SCREEN_Y / 2)
		+ 33, 0xFFFFCC, "But thank god it's done");
	mlx_string_put(mini->mlx, mini->win, (SCREEN_X / 2) - 90, (SCREEN_Y / 2)
		+ 45, 0xFFFFCC, "As for matrices - never again!");
	render_frame(mini);
	mlx_key_hook(mini->win, detect_key_inputs, mini);
	mlx_hook(mini->win, 17, 0, detect_close, mini);
	if (MOUSE_MOVE == 1)
		mlx_hook(mini->win, 6, 1L<<6, detect_mouse_movements, mini);
	mlx_loop_hook(mini->mlx, &temp_smoother, mini);
	mlx_loop(mini->mlx);
}
