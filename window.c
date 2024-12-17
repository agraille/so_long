/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:37:27 by agraille          #+#    #+#             */
/*   Updated: 2024/12/17 12:26:09 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	init_window(t_game *p)
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

int	exit_window(t_game *p)
{
	mlx_destroy_window(p->ptr_mlx, p->window);
	mlx_destroy_display(p->ptr_mlx);
	free(p->ptr_mlx);
	free(p);
	exit(EXIT_SUCCESS);
}

void	start_init(void)
{
	t_game *p;
	
	p = malloc(sizeof(t_game));
	if (!p)
		exit(EXIT_FAILURE);
	p->pos_x = 640;
	p->pos_y = 360;
	init_window(p);
	mlx_hook(p->window, 17, 0, exit_window, p);
	// mlx_key_hook
	mlx_loop(p->ptr_mlx);
}
