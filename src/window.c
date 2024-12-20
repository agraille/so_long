/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:37:27 by agraille          #+#    #+#             */
/*   Updated: 2024/12/20 12:14:31 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	load_images(t_win *p)
{
	p->pe = mlx_xpm_file_to_image(p->mlx, "xpm/End.xpm", &p->pix, &p->pix);
	p->pb = mlx_xpm_file_to_image(p->mlx, "xpm/Grass32.xpm", &p->pix, &p->pix);
	p->pc = mlx_xpm_file_to_image(p->mlx, "xpm/Icon1.xpm", &p->pix, &p->pix);
	p->pp = mlx_xpm_file_to_image(p->mlx, "xpm/Player32.xpm", &p->pix, &p->pix);
	p->pw = mlx_xpm_file_to_image(p->mlx, "xpm/Stone32.xpm", &p->pix, &p->pix);
	if (!p->pe || !p->pb || !p->pc || !p->pp || !p->pw)
	{
		free_images(p);
		exit_window(p);
	}
}

void	init_window(t_win *p)
{
	p->pos_x = 1920;
	p->pos_y = 1080;
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

void	free_images(t_win *p)
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
	free_images(p);
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

void	start_init(void)
{
	t_win	*p;

	p = malloc(sizeof(t_win));
	if (!p)
		exit(EXIT_FAILURE);
	p->pix = 32;
	init_window(p);
	load_images(p);
	mlx_put_image_to_window(p->mlx, p->window, p->pb, 0, 0);
	mlx_put_image_to_window(p->mlx, p->window, p->pb, 32, 0);
	mlx_put_image_to_window(p->mlx, p->window, p->pb, 64, 0);
	mlx_hook(p->window, WINDOW_CLOSED, 0, &exit_window, p);
	mlx_key_hook(p->window, &keyboard_touch, p);
	mlx_loop(p->mlx);
}
