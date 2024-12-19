/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:31:42 by agraille          #+#    #+#             */
/*   Updated: 2024/12/19 16:21:47 by agraille         ###   ########.fr       */
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
