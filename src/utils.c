/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:31:42 by agraille          #+#    #+#             */
/*   Updated: 2024/12/23 15:16:54 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	print_moove(t_win *p)
{
	write (1, "Numbers of moove = ", 19);
	p->moove++;
	ft_putnbr_fd(p->moove, STDOUT_FILENO);
	write(1, "\n", 1);
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

int	printmoove(t_win *p)
{
	char	*j;

	j = ft_itoa(p->moove);
	mlx_string_put(p->mlx, p->win, 1, 14, 0x00FF00, j);
	free(j);
	return (0);
}

int	check_frame(t_win *p)
{
	if (p->frame_counter >= p->item_delay)
	{
		p->i_frame++;
		if (p->i_frame >= ITEM_FRAME)
			p->i_frame = 0;
		p->frame_counter = 0;
		return (1);
	}
	if (p->frame_counter2 > p->wolf_delay2 && p->wy != 0)
	{
		move_wolf(p);
		p->frame_counter2 = 0;
	}
	p->frame_counter++;
	p->frame_counter2++;
	return (0);
}
