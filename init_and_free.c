/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:37:27 by agraille          #+#    #+#             */
/*   Updated: 2024/12/17 10:59:35 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	init_window(t_game *ptr)
{
	ptr->ptr_mlx = mlx_init();
	if (!ptr->ptr_mlx)
	{
		free(ptr);
		exit(EXIT_FAILURE);
	}
	ptr->window = mlx_new_window(ptr->ptr_mlx, 640, 360, "so_long");
	if (!ptr->window)
	{
		free(ptr->ptr_mlx);
		free(ptr);
		exit(EXIT_FAILURE);
	}
	mlx_loop(ptr->ptr_mlx);
}

// void	exit_window(t_game *ptr)
// {
	
// }
