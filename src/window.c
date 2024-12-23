/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:37:27 by agraille          #+#    #+#             */
/*   Updated: 2024/12/23 01:23:28 by agraille         ###   ########.fr       */
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
	p->item_frame = 0;
	p->frame_delay = 2000;
	p->frame_counter = 0;
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

void	free_pictures(t_win *p)
{
	int	i;

	i = 0;
	while (i < ITEM_FRAME)
	{
		if (p->pc[i])
			mlx_destroy_image(p->mlx, p->pc[i]);
		i++;
	}
	if (p->pe)
		mlx_destroy_image(p->mlx, p->pe);
	if (p->pe2)
		mlx_destroy_image(p->mlx, p->pe2);
	if (p->pb)
		mlx_destroy_image(p->mlx, p->pb);
	if (p->pb2)
		mlx_destroy_image(p->mlx, p->pb2);
	if (p->pp)
		mlx_destroy_image(p->mlx, p->pp);
	if (p->pw)
		mlx_destroy_image(p->mlx, p->pw);
	if (p->pw2)
		mlx_destroy_image(p->mlx, p->pw2);
	if (p->pw3)
		mlx_destroy_image(p->mlx, p->pw3);
	if (p->pw4)
		mlx_destroy_image(p->mlx, p->pw4);
	if (p->pw5)
		mlx_destroy_image(p->mlx, p->pw5);
	if (p->pw6)
		mlx_destroy_image(p->mlx, p->pw6);	
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
	p->item_frame = 0;
	p->frame_delay = 10;
	p->map = map_in_tab(argv1, height);
	if (!p->map)
		exit(EXIT_FAILURE);
	init_window(p, height);
	load_pictures(p);
	count_coins(p);
	render_map(p);
	mlx_hook(p->win, WINDOW_CLOSED, 1L << 0, &exit_window, p);
	mlx_key_hook(p->win, &keyboard_touch, p);
	mlx_loop_hook(p->mlx, &render_animation, p);
	mlx_loop(p->mlx);
}
