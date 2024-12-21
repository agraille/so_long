/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:54:25 by agraille          #+#    #+#             */
/*   Updated: 2024/12/21 13:17:18 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_map(t_win *p)
{
	int	x;
	int	y;

	y = -1;
	while (p->map[++y])
	{
		x = -1;
		while (p->map[y][++x] != '\n')
		{
			if (p->map[y][x] == '1')
				mlx_put_image_to_window(p->mlx, p->win, p->pw, x * p->pix, y * p->pix);
			else if (p->map[y][x] == '0')
				mlx_put_image_to_window(p->mlx, p->win, p->pb, x * p->pix, y * p->pix);
			else if (p->map[y][x] == 'P')
			{
				mlx_put_image_to_window(p->mlx, p->win, p->pp, x * p->pix, y * p->pix);
				p->player_x = x;
				p->player_y = y;
			}
			else if (p->map[y][x] == 'C')
				mlx_put_image_to_window(p->mlx, p->win, p->pc, x * p->pix, y * p->pix);
			else if (p->map[y][x] == 'E')
				mlx_put_image_to_window(p->mlx, p->win, p->pe, x * p->pix, y * p->pix);
		}
	}
}

void	load_pictures(t_win *p)
{
	p->pe = mlx_xpm_file_to_image(p->mlx, "xpm/End.xpm", &p->pix, &p->pix);
	p->pb = mlx_xpm_file_to_image(p->mlx, "xpm/floor.xpm", &p->pix, &p->pix);
	p->pc = mlx_xpm_file_to_image(p->mlx, "xpm/item.xpm", &p->pix, &p->pix);
	p->pp = mlx_xpm_file_to_image(p->mlx, "xpm/hero.xpm", &p->pix, &p->pix);
	p->pw = mlx_xpm_file_to_image(p->mlx, "xpm/wall.xpm", &p->pix, &p->pix);
	if (!p->pe || !p->pb || !p->pc || !p->pp || !p->pw)
	{
		free_pictures(p);
		exit_window(p);
	}
}
