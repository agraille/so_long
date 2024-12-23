/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:54:25 by agraille          #+#    #+#             */
/*   Updated: 2024/12/23 13:29:48 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	render_animation(t_win *p)
{
    int x;;
    int y;
	int temp;

	printmoove(p);
	y = -1;
	temp = 0;
	while (p->map[++y] && p->last_frame != p->item_frame)
	{
		x = -1;
		while (p->map[y][++x] != '\n')
		{
			
			if (p->map[y][x] == 'C')
			{
				mlx_put_image_to_window(p->mlx, p->win, p->pc[p->item_frame], x * p->pix, y * p->pix);
				temp = 1;
			}
		}
	}
	check_frame(p);
	if (temp == 1)
		p->last_frame = p->item_frame;
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
				mlx_put_image_to_window(p->mlx, p->win, p->pp9, x * p->pix, y * p->pix);
				p->player_x = x;
				p->player_y = y;
			}
			else if (p->map[y][x] == 'K')
			{
				mlx_put_image_to_window(p->mlx, p->win, p->pk, x * p->pix, y * p->pix);
				p->wolf_x = x;
				p->wolf_y = y;
			}
		}
	}
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
			else if (p->map[y][x] == '0' && (x % 2 == 0))
				mlx_put_image_to_window(p->mlx, p->win, p->pb, x * p->pix, y * p->pix);
			else if (p->map[y][x] == '0')
				mlx_put_image_to_window(p->mlx, p->win, p->pb2, x * p->pix, y * p->pix);
			else if (p->map[y][x] == 'E' && p->coin > 0)
				mlx_put_image_to_window(p->mlx, p->win, p->pe, x * p->pix, y * p->pix);
			else if (p->map[y][x] == 'E' && p->coin == 0)
				mlx_put_image_to_window(p->mlx, p->win, p->pe2, x * p->pix, y * p->pix);
		}
	}
}

static void load_pictures_item(t_win *p)
{
	int	i;

	i = 0;
	p->pc[0] = mlx_xpm_file_to_image(p->mlx, "xpm/C1.xpm", &p->pix, &p->pix);
	p->pc[1] = mlx_xpm_file_to_image(p->mlx, "xpm/C2.xpm", &p->pix, &p->pix);
	p->pc[2] = mlx_xpm_file_to_image(p->mlx, "xpm/C3.xpm", &p->pix, &p->pix);
	p->pc[3] = mlx_xpm_file_to_image(p->mlx, "xpm/C4.xpm", &p->pix, &p->pix);
	p->pc[4] = mlx_xpm_file_to_image(p->mlx, "xpm/C5.xpm", &p->pix, &p->pix);
	p->pc[5] = mlx_xpm_file_to_image(p->mlx, "xpm/C6.xpm", &p->pix, &p->pix);
	p->pc[6] = mlx_xpm_file_to_image(p->mlx, "xpm/C7.xpm", &p->pix, &p->pix);
	p->pc[7] = mlx_xpm_file_to_image(p->mlx, "xpm/C8.xpm", &p->pix, &p->pix);
	while (i < ITEM_FRAME)
	{
		if (!p->pc[i])
		{
			free_pictures(p);
			exit_window(p);
		}
		i++;
	}
}

void	load_pictures(t_win *p)
{
	p->pe = mlx_xpm_file_to_image(p->mlx, "xpm/End.xpm", &p->pix, &p->pix);
	p->pe2 = mlx_xpm_file_to_image(p->mlx, "xpm/End2.xpm", &p->pix, &p->pix);
	p->pb = mlx_xpm_file_to_image(p->mlx, "xpm/floor.xpm", &p->pix, &p->pix);
	p->pb2 = mlx_xpm_file_to_image(p->mlx, "xpm/floor2.xpm", &p->pix, &p->pix);
	p->pp = mlx_xpm_file_to_image(p->mlx, "xpm/hero.xpm", &p->pix, &p->pix);
	p->pp2 = mlx_xpm_file_to_image(p->mlx, "xpm/hero2.xpm", &p->pix, &p->pix);
	p->pp3 = mlx_xpm_file_to_image(p->mlx, "xpm/hero3.xpm", &p->pix, &p->pix);
	p->pp4 = mlx_xpm_file_to_image(p->mlx, "xpm/hero4.xpm", &p->pix, &p->pix);
	p->pp5 = mlx_xpm_file_to_image(p->mlx, "xpm/hero5.xpm", &p->pix, &p->pix);
	p->pp6 = mlx_xpm_file_to_image(p->mlx, "xpm/hero6.xpm", &p->pix, &p->pix);
	p->pp7 = mlx_xpm_file_to_image(p->mlx, "xpm/hero7.xpm", &p->pix, &p->pix);
	p->pp8 = mlx_xpm_file_to_image(p->mlx, "xpm/hero8.xpm", &p->pix, &p->pix);
	p->pp9 = mlx_xpm_file_to_image(p->mlx, "xpm/hero9.xpm", &p->pix, &p->pix);
	p->pw = mlx_xpm_file_to_image(p->mlx, "xpm/wall.xpm", &p->pix, &p->pix);
	p->pw2 = mlx_xpm_file_to_image(p->mlx, "xpm/wall2.xpm", &p->pix, &p->pix);
	p->pw3 = mlx_xpm_file_to_image(p->mlx, "xpm/wall3.xpm", &p->pix, &p->pix);
	p->pw4 = mlx_xpm_file_to_image(p->mlx, "xpm/wall4.xpm", &p->pix, &p->pix);
	p->pw5 = mlx_xpm_file_to_image(p->mlx, "xpm/wall5.xpm", &p->pix, &p->pix);
	p->pw6 = mlx_xpm_file_to_image(p->mlx, "xpm/wall6.xpm", &p->pix, &p->pix);
	p->pk = mlx_xpm_file_to_image(p->mlx, "xpm/enemy.xpm", &p->pix, &p->pix);
	if (!p->pe || !p->pb || !p->pb2 || !p->pp || !p->pp2 || !p->pp3 || !p->pp4 || !p->pp5 || !p->pp6 || !p->pp7 || !p->pp8 || !p->pp9 || !p->pw || !p->pw2 || !p->pw3 || !p->pw4 || !p->pw5 || !p->pw6 || !p->pe2 || !p->pk)
	{
		free_pictures(p);
		exit_window(p);
	}
	load_pictures_item(p);
}
