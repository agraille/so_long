/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:19:36 by agraille          #+#    #+#             */
/*   Updated: 2024/12/22 21:29:05 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static	int	requirements_bis2(char **map, t_ff v)
{
	v.k = 0;
	while (map[v.k])
	{
		v.i = 0;
		while (map[v.k][v.i])
		{
			if (map[v.k][v.i] == 'E' || map[v.k][v.i] == 'C')
				return (0);
			v.i++;
		}
		v.k++;
	}
	return (1);
}

static	int	requirements_bis(t_ff value)
{
	if (value.p != 1 || value.c < 1 || value.e != 1)
		return (0);
	return (1);
}

static void	flood_fill(char **map, int p_y, int p_x)
{
	if (map[p_y][p_x] == '1' || map[p_y][p_x] == 'K')
		return ;
	map[p_y][p_x] = '1';
	flood_fill(map, p_y - 1, p_x);
	flood_fill(map, p_y + 1, p_x);
	flood_fill(map, p_y, p_x - 1);
	flood_fill(map, p_y, p_x + 1);
}

int	requirements(char **map, int height, t_ff value)
{
	while (value.k < height - 1)
	{
		value.i = -1;
		while (map[value.k][++value.i] != '\n')
		{
			if (map[value.k][value.i] == 'P')
			{
				value.p += 1;
				value.p_y = value.k;
				value.p_x = value.i;
			}
			if (map[value.k][value.i] == 'C')
				value.c += 1;
			if (map[value.k][value.i] == 'E')
				value.e += 1;
		}
		value.k++;
	}
	if (!requirements_bis(value))
		return (0);
	flood_fill(map, value.p_y, value.p_x);
	if (!requirements_bis2(map, value))
		return (0);
	return (1);
}
