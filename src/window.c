/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:37:27 by agraille          #+#    #+#             */
/*   Updated: 2024/12/20 23:51:13 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_window(t_win *p, int height)
{
	p->pix = 32;
	p->pos_x = (ft_strlen(p->map[0]) - 1) * 32;
	p->pos_y = height * 32;
	p->mlx = mlx_init();
	if (!p->mlx)
	{
		free(p);
		exit(EXIT_FAILURE);
	}
	p->window = mlx_new_window(p->mlx, p->pos_x, p->pos_y, "so_long");
	if (!p->window)
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
	mlx_destroy_window(p->mlx, p->window);
	mlx_destroy_display(p->mlx);
	free(p->mlx);
	free(p);
	exit(EXIT_SUCCESS);
}

int	keyboard_touch(int keycode, t_win *p)
{
	if (keycode == ESCAPE)
		exit_window(p);
	return (1);
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
	render_map(p);
	mlx_hook(p->window, WINDOW_CLOSED, 0, &exit_window, p);
	mlx_key_hook(p->window, &keyboard_touch, p);
	mlx_loop(p->mlx);
}
