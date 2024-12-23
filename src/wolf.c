/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:14:42 by agraille          #+#    #+#             */
/*   Updated: 2024/12/23 15:04:06 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_winner(t_win *p)
{
	if (p->wx == p->p_x && p->wy == p->p_y)
	{
		printmoove(p);
		write(1, "Wolf: Better than you!\n", 23);
		exit_window(p);
	}
}

static	void	put_for_norm(t_win *p, char c)
{
	if (c == '1')
		mlx_put_image_to_window(p->mlx, p->win, p->pb,
			p->wx * p->pix, p->wy * p->pix);
	else
		mlx_put_image_to_window(p->mlx, p->win, p->pk,
			p->wx * p->pix, p->wy * p->pix);
}

static void	move_wolf_x(t_win *p, t_ff n, int dx)
{
	if (dx != 0)
	{
		n.p_x = p->wx + dx;
		n.p_y = p->wy;
		if (p->map[n.p_y][n.p_x] == '0' || p->map[n.p_y][n.p_x] == 'P')
		{
			p->map[p->wy][p->wx] = '0';
			put_for_norm(p, '1');
			p->map[n.p_y][n.p_x] = 'K';
			p->wx = n.p_x;
			p->wy = n.p_y;
			put_for_norm(p, '0');
		}
		else if (p->map[n.p_y][n.p_x] == 'C' &&
			(p->map[n.p_y][n.p_x + dx] == '0' || p->map[n.p_y][n.p_x] == 'P'))
		{
			p->map[p->wy][p->wx] = '0';
			put_for_norm(p, '1');
			p->map[n.p_y][n.p_x + dx] = 'K';
			p->wx = n.p_x + dx;
			p->wy = n.p_y;
			put_for_norm(p, '0');
		}
	}
}

static void	move_wolf_y(t_win *p, t_ff n, int dy, int dx)
{
	if (dy != 0)
	{
		n.p_x = p->wx;
		n.p_y = p->wy + dy;
		if (p->map[n.p_y][n.p_x] == '0' || p->map[n.p_y][n.p_x] == 'P')
		{
			p->map[p->wy][p->wx] = '0';
			put_for_norm(p, '1');
			p->map[n.p_y][n.p_x] = 'K';
			p->wx = n.p_x;
			p->wy = n.p_y;
			put_for_norm(p, '0');
		}
		else if (p->map[n.p_y][n.p_x] == 'C' &&
			(p->map[n.p_y][n.p_x + dx] == '0' || p->map[n.p_y][n.p_x] == 'P'))
		{
			p->map[p->wy][p->wx] = '0';
			put_for_norm(p, '1');
			p->map[n.p_y + dy][n.p_x] = 'K';
			p->wx = n.p_x;
			p->wy = n.p_y + dy;
			put_for_norm(p, '0');
		}
	}
}

void	move_wolf(t_win *p)
{
	int		dx;
	int		dy;
	t_ff	n;

	n.p_x = 0;
	n.p_y = 0;
	dx = (p->p_x > p->wx) - (p->p_x < p->wx);
	dy = (p->p_y > p->wy) - (p->p_y < p->wy);
	move_wolf_x(p, n, dx);
	move_wolf_y(p, n, dy, dx);
	check_winner(p);
}
