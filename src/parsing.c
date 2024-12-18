/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:33:31 by agraille          #+#    #+#             */
/*   Updated: 2024/12/18 13:45:08 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static char **map_in_tab(char *argv1, int count_line)
{
	int		fd;
	int		i;
	char	**map;
	
	map = malloc(sizeof(char *) * (count_line + 1));
	if (!map)
		exit(EXIT_FAILURE);
	fd = open(argv1, O_RDONLY);
	i = 0;
	while (i < count_line)
		map[i++] = get_next_line(fd);
	get_next_line(fd);
	close (fd);
	map[i] = 0;
	return (map);
}

static void	find_line(char *argv1, int *count_line)
{
	int 	fd;
	int 	readed;
	char	buffer[1];

	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	readed = 1;
	*count_line = 0;
	while (readed > 0)
	{
		readed = read(fd, buffer, 1);
		if (buffer[0] == '\n')
			(*count_line)++;
	}
	(*count_line)--;
	close (fd);
}

int	parsing(char *argv1)
{
	char	**map;
	int		count_line;
	
	find_line(argv1, &count_line);
	map = map_in_tab(argv1, count_line);
	for (int i = 0; map[i]; i++)
		printf("%s",map[i]);
	free_map(map);
	return (1);
}
