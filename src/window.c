/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:37:27 by agraille          #+#    #+#             */
/*   Updated: 2025/01/02 07:31:30 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	count_coins(t_win *p)
{
	int	x;
	int	y;

	p->coin = 0;
	y = 0;
	while (p->map[y])
	{
		x = 0;
		while (p->map[y][x] != '\n' && p->map[y][x] != '\0')
		{
			if (p->map[y][x] == 'C')
				p->coin += 1;
			x++;
		}
		p->x_size = x - 1;
		y++;
	}
	p->y_size = y - 1;
}

static void	init_window(t_win *p, int height)
{
	p->moove = 0;
	p->last_frame = -1;
	p->i_frame = 0;
	p->item_delay = 1200;
	p->wolf_delay2 = 3500;
	p->frame_counter = 0;
	p->frame_counter2 = 0;
	p->animation_frame = 0;
	p->pix = 32;
	p->size_x = (ft_strlen(p->map[0]) - 1) * 32;
	p->size_y = height * 32;
	p->mlx = mlx_init();
	if (!p->mlx)
	{
		free(p);
		exit(EXIT_FAILURE);
	}
	p->win = mlx_new_window(p->mlx, p->size_x, p->size_y, "so_long");
	if (!p->win)
	{
		free(p->mlx);
		free(p);
		exit(EXIT_FAILURE);
	}
}

int	exit_window(t_win *p)
{
	free_map(p->map);
	free_pictures(p);
	mlx_destroy_window(p->mlx, p->win);
	mlx_destroy_display(p->mlx);
	free(p->mlx);
	free(p);
	exit(EXIT_SUCCESS);
}

void	start_init(char *argv1, int height)
{
	t_win	*p;

	p = malloc(sizeof(t_win));
	if (!p)
		exit(EXIT_FAILURE);
	p->map = map_in_tab(argv1, height);
	if (!p->map)
		exit(EXIT_FAILURE);
	p->wx = 0;
	p->wy = 0;
	init_window(p, height);
	load_pictures(p);
	count_coins(p);
	render_map(p);
	render_map_bis(p);
	mlx_hook(p->win, WINDOW_CLOSED, 1L << 0, &exit_window, p);
	mlx_hook(p->win, 2, 1L << 0,  &keyboard_touch, p);
	mlx_loop_hook(p->mlx, &render_animation, p);
	mlx_loop(p->mlx);
}
