/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:54:25 by agraille          #+#    #+#             */
/*   Updated: 2024/12/23 14:39:39 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	render_animation(t_win *p)
{
	int	x;
	int	y;
	int	temp;

	printmoove(p);
	y = -1;
	temp = 0;
	while (p->map[++y] && p->last_frame != p->i_frame)
	{
		x = -1;
		while (p->map[y][++x] != '\n')
		{
			if (p->map[y][x] == 'C')
			{
				mlx_put_image_to_window(p->mlx, p->win, p->pc[p->i_frame],
					x * p->pix, y * p->pix);
				temp = 1;
			}
		}
	}
	check_frame(p);
	if (temp == 1)
		p->last_frame = p->i_frame;
	return (0);
}

void	render_map_bis(t_win *p)
{
	int	x;
	int	y;

	y = -1;
	while (p->map[++y])
	{
		x = -1;
		while (p->map[y][++x] != '\n')
		{
			if (p->map[y][x] == 'P')
			{
				mlx_put_image_to_window(p->mlx, p->win, p->pp9,
					x * p->pix, y * p->pix);
				p->p_x = x;
				p->p_y = y;
			}
			else if (p->map[y][x] == 'K')
			{
				mlx_put_image_to_window(p->mlx, p->win, p->pk,
					x * p->pix, y * p->pix);
				p->wx = x;
				p->wy = y;
			}
		}
	}
}

static void	render_wall(t_win *p, int x, int y)
{
	if (x == 0 && y == 0)
		mlx_put_image_to_window(p->mlx, p->win, p->pw6, x * p->pix, y * p->pix);
	else if (x == 0 && y == p->y_size)
		mlx_put_image_to_window(p->mlx, p->win, p->pw3, x * p->pix, y * p->pix);
	else if (y == 0 && x == p->x_size)
		mlx_put_image_to_window(p->mlx, p->win, p->pw4, x * p->pix, y * p->pix);
	else if (y == p->y_size && x == p->x_size)
		mlx_put_image_to_window(p->mlx, p->win, p->pw5, x * p->pix, y * p->pix);
	else if (p->map[y][x] == '1' && (y == 0 || y == p->y_size))
		mlx_put_image_to_window(p->mlx, p->win, p->pw, x * p->pix, y * p->pix);
	else if (p->map[y][x] == '1' && (x == 0 || x == p->x_size))
		mlx_put_image_to_window(p->mlx, p->win, p->pw2, x * p->pix, y * p->pix);
	else if (p->map[y][x] == '1')
		mlx_put_image_to_window(p->mlx, p->win, p->pe, x * p->pix, y * p->pix);
}

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
			render_wall(p, x, y);
			if (p->map[y][x] == '0' && (x % 2 == 0))
				mlx_put_image_to_window(p->mlx, p->win, p->pb,
					x * p->pix, y * p->pix);
			else if (p->map[y][x] == '0')
				mlx_put_image_to_window(p->mlx, p->win, p->pb2,
					x * p->pix, y * p->pix);
			else if (p->map[y][x] == 'E' && p->coin > 0)
				mlx_put_image_to_window(p->mlx, p->win, p->pe,
					x * p->pix, y * p->pix);
			else if (p->map[y][x] == 'E' && p->coin == 0)
				mlx_put_image_to_window(p->mlx, p->win, p->pe2,
					x * p->pix, y * p->pix);
		}
	}
}
