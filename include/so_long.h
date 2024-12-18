/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:32:07 by agraille          #+#    #+#             */
/*   Updated: 2024/12/18 12:53:31 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../libft/include/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

#define WINDOW_CLOSED 17
#define ESCAPE 65307
typedef struct s_game
{
	void	*ptr_mlx;
	void	*window;
	int		pos_x;
	int		pos_y;
}	t_win;

void	start_init(void);
void	init_window(t_win *ptr);
void	free_map(char **map);
int		exit_window(t_win *ptr);
int		keyboard_touch(int keycode, t_win *p);
int		parsing(char *argv1);

#endif
