/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:14:42 by agraille          #+#    #+#             */
/*   Updated: 2024/12/23 13:31:46 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_winner(t_win *p)
{
    if (p->wolf_x == p->player_x && p->wolf_y == p->player_y)
    {
        printmoove(p);
		write(1, "Wolf: Better than you!\n", 23);
		exit_window(p);
    }
}

static void	move_wolf_x(t_win *p, t_ff new, int dx)
{
	if (dx != 0)
    {
        new.p_x = p->wolf_x + dx;
        new.p_y = p->wolf_y;
        if (p->map[new.p_y][new.p_x] == '0' || p->map[new.p_y][new.p_x] == 'P')
        {
            p->map[p->wolf_y][p->wolf_x] = '0';
            mlx_put_image_to_window(p->mlx, p->win, p->pb, p->wolf_x * p->pix, p->wolf_y * p->pix);
            p->map[new.p_y][new.p_x] = 'K';
            p->wolf_x = new.p_x;
            p->wolf_y = new.p_y;
            mlx_put_image_to_window(p->mlx, p->win, p->pk, p->wolf_x * p->pix, p->wolf_y * p->pix);
            return ;
        }
        else if (p->map[new.p_y][new.p_x] == 'C' && (p->map[new.p_y][new.p_x + dx] == '0' || p->map[new.p_y][new.p_x] == 'P'))
        {
            p->map[p->wolf_y][p->wolf_x] = '0';
            mlx_put_image_to_window(p->mlx, p->win, p->pb, p->wolf_x * p->pix, p->wolf_y * p->pix);
            p->map[new.p_y][new.p_x + dx] = 'K';
            p->wolf_x = new.p_x + dx;
            p->wolf_y = new.p_y;
            mlx_put_image_to_window(p->mlx, p->win, p->pk, p->wolf_x * p->pix, p->wolf_y * p->pix);
            return ;
        }
    }
}

static void	move_wolf_y(t_win *p, t_ff new, int dy, int dx)
{
	 if (dy != 0)
    {
        new.p_x = p->wolf_x;
        new.p_y = p->wolf_y + dy;
        if (p->map[new.p_y][new.p_x] == '0' || p->map[new.p_y][new.p_x] == 'P')
        {
            p->map[p->wolf_y][p->wolf_x] = '0';
            mlx_put_image_to_window(p->mlx, p->win, p->pb, p->wolf_x * p->pix, p->wolf_y * p->pix);
            p->map[new.p_y][new.p_x] = 'K';
            p->wolf_x = new.p_x;
            p->wolf_y = new.p_y;
            mlx_put_image_to_window(p->mlx, p->win, p->pk, p->wolf_x * p->pix, p->wolf_y * p->pix);
            return ;
        }
        else if (p->map[new.p_y][new.p_x] == 'C' && (p->map[new.p_y][new.p_x + dx] == '0' || p->map[new.p_y][new.p_x] == 'P'))
        {
            p->map[p->wolf_y][p->wolf_x] = '0';
            mlx_put_image_to_window(p->mlx, p->win, p->pb, p->wolf_x * p->pix, p->wolf_y * p->pix);
            p->map[new.p_y + dy][new.p_x] = 'K';
            p->wolf_x = new.p_x;
            p->wolf_y = new.p_y + dy;
            mlx_put_image_to_window(p->mlx, p->win, p->pk, p->wolf_x * p->pix, p->wolf_y * p->pix);
            return ;
        }
    }
}

void move_wolf(t_win *p)
{
    int dx, dy;
    t_ff	new;

	new.p_x = 0;
	new.p_y = 0;
    dx = (p->player_x > p->wolf_x) - (p->player_x < p->wolf_x);
    dy = (p->player_y > p->wolf_y) - (p->player_y < p->wolf_y);
    move_wolf_x(p, new, dx);
    move_wolf_y(p, new, dy, dx);
    check_winner(p);
}
