/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:56:05 by agraille          #+#    #+#             */
/*   Updated: 2024/12/23 13:17:00 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void animate_player_right(t_win *p, int x, int y)
{
    if (p->animation_frame == 0)
        mlx_put_image_to_window(p->mlx, p->win, p->pp2, x * p->pix, y * p->pix);
    else if (p->animation_frame == 1)
        mlx_put_image_to_window(p->mlx, p->win, p->pp3, x * p->pix, y * p->pix);
    else if (p->animation_frame == 2)
        mlx_put_image_to_window(p->mlx, p->win, p->pp4, x * p->pix, y * p->pix);
    else if (p->animation_frame == 3)
        mlx_put_image_to_window(p->mlx, p->win, p->pp, x * p->pix, y * p->pix);
    p->animation_frame = (p->animation_frame + 1) % 4;
}

static void animate_player_left(t_win *p, int x, int y)
{
    if (p->animation_frame == 0)
        mlx_put_image_to_window(p->mlx, p->win, p->pp5, x * p->pix, y * p->pix);
    else if (p->animation_frame == 1)
        mlx_put_image_to_window(p->mlx, p->win, p->pp6, x * p->pix, y * p->pix);
    else if (p->animation_frame == 2)
        mlx_put_image_to_window(p->mlx, p->win, p->pp7, x * p->pix, y * p->pix);
    else if (p->animation_frame == 3)
        mlx_put_image_to_window(p->mlx, p->win, p->pp8, x * p->pix, y * p->pix);
    p->animation_frame = (p->animation_frame + 1) % 4;
}

int	keyboard_touch(int keycode, t_win *p)
{
	if (keycode == ESCAPE)
		exit_window(p);
	if (keycode == W_KEY || keycode == UP_ARROW)
		move_player(p, 0, -1);
	else if (keycode == A_KEY || keycode == LEFT_ARROW)
		move_player(p, -1, 0);
	else if (keycode == S_KEY || keycode == DOWN_ARROW)
		move_player(p, 0, 1);
	else if (keycode == D_KEY || keycode == RIGHT_ARROW)
		move_player(p, 1, 0);
	return (1);
}

static void	print_moove(t_win *p)
{
	write (1, "Numbers of moove = ", 19);
	p->moove++;
	ft_putnbr_fd(p->moove, STDOUT_FILENO);
	write(1, "\n", 1);
}

void	move_player(t_win *p, int dir_x, int dir_y)
{
	int	x;
	int	y;

	check_winner(p);
	x = p->player_x + dir_x;
	y = p->player_y + dir_y;
	if (p->map[y][x] != '1' && p->map[y][x] != 'E' && p->map[y][x] != 'K')
	{
		p->map[p->player_y][p->player_x] = '0';
		mlx_put_image_to_window(p->mlx, p->win, p->pb, p->player_x * p->pix, p->player_y * p->pix);
		p->player_x = x;
		p->player_y = y;
		if (p->map[p->player_y][p->player_x] == 'C')
			p->coin--;
		p->map[p->player_y][p->player_x] = 'P';
		if (dir_x < 0)
			animate_player_left(p, p->player_x, p->player_y);
		else if (dir_x >= 0)
			animate_player_right(p, p->player_x, p->player_y);
		print_moove(p);
	}
	render_map(p);
	if ((p->map[y][x] == 'E' && p->coin == 0) || p->map[y][x] == 'K')
	{
		p->map[p->player_y][p->player_x] = '0';
		p->player_x = x;
		p->player_y = y;
		print_moove(p);
		exit_window(p);
	}
	render_map(p);
}
