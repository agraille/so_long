/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:56:05 by agraille          #+#    #+#             */
/*   Updated: 2025/01/02 07:31:17 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	animate_player_right(t_win *p, int x, int y)
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

static void	animate_player_left(t_win *p, int x, int y)
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

static void	move_player_bis(t_win *p, int x, int y)
{
	if ((p->map[y][x] == 'E' && p->coin == 0) || p->map[y][x] == 'K')
	{
		p->map[p->p_y][p->p_x] = '0';
		p->p_x = x;
		p->p_y = y;
		print_moove(p);
		exit_window(p);
	}
}

void	move_player(t_win *p, int dir_x, int dir_y)
{
	int	x;
	int	y;

	if (p->wy != 0)
		check_winner(p);
	x = p->p_x + dir_x;
	y = p->p_y + dir_y;
	if (p->map[y][x] != '1' && p->map[y][x] != 'E' && p->map[y][x] != 'K')
	{
		p->map[p->p_y][p->p_x] = '0';
		mlx_put_image_to_window(p->mlx, p->win, p->pb,
			p->p_x * p->pix, p->p_y * p->pix);
		p->p_x = x;
		p->p_y = y;
		if (p->map[p->p_y][p->p_x] == 'C')
			p->coin--;
		p->map[p->p_y][p->p_x] = 'P';
		if (dir_x < 0)
			animate_player_left(p, p->p_x, p->p_y);
		else if (dir_x >= 0)
			animate_player_right(p, p->p_x, p->p_y);
		print_moove(p);
	}
	move_player_bis(p, x, y);
	render_map(p);
}
