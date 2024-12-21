/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:33:31 by agraille          #+#    #+#             */
/*   Updated: 2024/12/21 12:28:55 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static int	check_is_valid(char **map, int line_nbr)
{
	int	i;
	int	k;

	i = 0;
	while (map[0][i] != '\n')
	{
		if (map[0][i] != '1' || map[line_nbr - 1][i] != '1')
			return (0);
		i++;
	}
	k = 0;
	while (++k < line_nbr - 1)
	{
		i = 0;
		while (map[k][i] != '\n')
		{
			if (!check_char(map[k][i]))
				return (0);
			if (map[k][0] != '1' || (map[k][i + 1] == '\n' && map[k][i] != '1'))
				return (0);
			i++;
		}
	}
	return (1);
}

static int	valid_width(char **map, int height)
{
	int	j;
	int	len;
	int	len_ok;

	len_ok = (int)ft_strlen(map[0]);
	if (height >= (int)ft_strlen(map[0]) - 1)
		return (0);
	j = 1;
	while (map[j])
	{
		len = (int)ft_strlen(map[j]);
		if (len != len_ok)
			return (0);
		j++;
	}
	return (1);
}

char	**map_in_tab(char *argv1, int height)
{
	int		fd;
	int		i;
	char	**map;

	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		exit(EXIT_FAILURE);
	fd = open(argv1, O_RDONLY);
	i = 0;
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			while (i > 0)
				free(map[i - 1]);
			free(map);
			close(fd);
			return (NULL);
		}
		i++;
	}
	close (fd);
	map[i] = 0;
	return (map);
}

static void	find_line(char *argv1, int *height)
{
	int		fd;
	int		readed;
	char	buffer[1];

	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	readed = 1;
	*height = 0;
	while (readed > 0)
	{
		readed = read(fd, buffer, 1);
		if (buffer[0] == '\n')
			(*height)++;
	}
	(*height)--;
	close (fd);
}

int	parsing(char *argv1)
{
	char	**map;
	int		height;
	t_ff	value;

	find_line(argv1, &height);
	map = map_in_tab(argv1, height);
	if (!map)
		exit(EXIT_FAILURE);
	if (!valid_width(map, height) || !check_is_valid(map, height))
		error(map, "Error\nInvalid map structure.\n");
	ft_memset(&value, 0, sizeof(t_ff));
	if (!requirements(map, height, value))
		error(map, "Error\nThe map cannot be completed.\n");
	free_map(map);
	return (height);
}
