/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:37:27 by agraille          #+#    #+#             */
/*   Updated: 2024/12/17 22:32:29 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_window(t_win *p)
{
	p->ptr_mlx = mlx_init();
	if (!p->ptr_mlx)
	{
		free(p);
		exit(EXIT_FAILURE);
	}
	p->window = mlx_new_window(p->ptr_mlx, p->pos_x, p->pos_y, "so_long");
	if (!p->window)
	{
		free(p->ptr_mlx);
		free(p);
		exit(EXIT_FAILURE);
	}
	
}

int	exit_window(t_win *p)
{
	mlx_destroy_window(p->ptr_mlx, p->window);
	mlx_destroy_display(p->ptr_mlx);
	free(p->ptr_mlx);
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
	t_win *p;
	
	p = malloc(sizeof(t_win));
	if (!p)
		exit(EXIT_FAILURE);
	p->pos_x = 640;
	p->pos_y = 360;
	init_window(p);
	mlx_hook(p->window, WINDOW_CLOSED, 0,&exit_window, p);
	mlx_key_hook(p->window, &keyboard_touch, p);
	mlx_loop(p->ptr_mlx);
}
