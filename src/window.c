/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:37:27 by agraille          #+#    #+#             */
/*   Updated: 2024/12/21 13:16:00 by agraille         ###   ########.fr       */
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
		y++;
	}
}

static void	init_window(t_win *p, int height)
{
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
	if (p->pe)
		mlx_destroy_image(p->mlx, p->pe);
	if (p->pb)
		mlx_destroy_image(p->mlx, p->pb);
	if (p->pc)
		mlx_destroy_image(p->mlx, p->pc);
	if (p->pp)
		mlx_destroy_image(p->mlx, p->pp);
	if (p->pw)
		mlx_destroy_image(p->mlx, p->pw);
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
	init_window(p, height);
	load_pictures(p);
	count_coins(p);
	render_map(p);
	mlx_hook(p->win, WINDOW_CLOSED, 1L << 0, &exit_window, p);
	mlx_key_hook(p->win, &keyboard_touch, p);
	mlx_loop(p->mlx);
}
