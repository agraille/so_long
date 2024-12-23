/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:31:42 by agraille          #+#    #+#             */
/*   Updated: 2024/12/23 01:33:27 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	free_map(char **map)
{
	ssize_t	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

int	check_char(char c)
{
	const char	*tab;

	tab = "01CEPK";
	while (*tab)
	{
		if (c == *tab)
			return (1);
		tab++;
	}
	return (0);
}

void	error(char **map, char *str)
{
	write(2, str, ft_strlen(str));
	free_map(map);
	exit(EXIT_FAILURE);
}

int printmoove(t_win *p)
{
	char *j;
	
	j = ft_itoa(p->moove);
	mlx_string_put(p->mlx, p->win, 0, 14, 0xFF0000, j);
	free(j);
	return (0);
}

int	check_frame(t_win *p)
{
	if (p->frame_counter >= p->frame_delay)
    {
        p->item_frame++;
        if (p->item_frame >= ITEM_FRAME)
            p->item_frame = 0;
        p->frame_counter = 0;
		return (1);
    }
	p->frame_counter++;
	return (0);
}
