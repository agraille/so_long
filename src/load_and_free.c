/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:10:29 by agraille          #+#    #+#             */
/*   Updated: 2025/01/02 07:26:47 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_pictures_bis(t_win *p)
{
	if (p->pp5)
		mlx_destroy_image(p->mlx, p->pp5);
	if (p->pp6)
		mlx_destroy_image(p->mlx, p->pp6);
	if (p->pp7)
		mlx_destroy_image(p->mlx, p->pp7);
	if (p->pp8)
		mlx_destroy_image(p->mlx, p->pp8);
	if (p->pp9)
		mlx_destroy_image(p->mlx, p->pp9);
	if (p->pw)
		mlx_destroy_image(p->mlx, p->pw);
	if (p->pw2)
		mlx_destroy_image(p->mlx, p->pw2);
	if (p->pw3)
		mlx_destroy_image(p->mlx, p->pw3);
	if (p->pw4)
		mlx_destroy_image(p->mlx, p->pw4);
	if (p->pw5)
		mlx_destroy_image(p->mlx, p->pw5);
	if (p->pw6)
		mlx_destroy_image(p->mlx, p->pw6);
	if (p->pk)
		mlx_destroy_image(p->mlx, p->pk);
}

void	free_pictures(t_win *p)
{
	int	i;

	i = -1;
	while (++i < ITEM_FRAME)
	{
		if (p->pc[i])
			mlx_destroy_image(p->mlx, p->pc[i]);
	}
	if (p->pe)
		mlx_destroy_image(p->mlx, p->pe);
	if (p->pe2)
		mlx_destroy_image(p->mlx, p->pe2);
	if (p->pb)
		mlx_destroy_image(p->mlx, p->pb);
	if (p->pb2)
		mlx_destroy_image(p->mlx, p->pb2);
	if (p->pp)
		mlx_destroy_image(p->mlx, p->pp);
	if (p->pp2)
		mlx_destroy_image(p->mlx, p->pp2);
	if (p->pp3)
		mlx_destroy_image(p->mlx, p->pp3);
	if (p->pp4)
		mlx_destroy_image(p->mlx, p->pp4);
	free_pictures_bis(p);
}

void	free_map(char **map)
{
	ssize_t	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

static void	load_pictures_bis(t_win *p)
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
	p->pe = mlx_xpm_file_to_image(p->mlx, "xpm/End.xpm", &p->pix, &p->pix);
	p->pe2 = mlx_xpm_file_to_image(p->mlx, "xpm/End2.xpm", &p->pix, &p->pix);
	p->pb = mlx_xpm_file_to_image(p->mlx, "xpm/floor.xpm", &p->pix, &p->pix);
	p->pb2 = mlx_xpm_file_to_image(p->mlx, "xpm/floor2.xpm", &p->pix, &p->pix);
	p->pk = mlx_xpm_file_to_image(p->mlx, "xpm/enemy.xpm", &p->pix, &p->pix);
}

void	load_pictures(t_win *p)
{
	load_pictures_bis(p);
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
	if (!p->pe || !p->pb || !p->pb2 || !p->pp || !p->pp2 || !p->pp3
		|| !p->pp4 || !p->pp5 || !p->pp6 || !p->pp7 || !p->pp8 || !p->pp9
		|| !p->pw || !p->pw2 || !p->pw3 || !p->pw4 || !p->pw5 || !p->pw6
		|| !p->pe2 || !p->pk)
	{
		free_pictures(p);
		exit_window(p);
	}
}
