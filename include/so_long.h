/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:32:06 by agraille          #+#    #+#             */
/*   Updated: 2024/12/20 12:05:14 by agraille         ###   ########.fr       */
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

# define WINDOW_CLOSED 17
# define ESCAPE 65307

typedef struct s_game
{
	void	*mlx;
	void	*window;
	void	*pe;
	void	*pb;
	void	*pc;
	void	*pp;
	void	*pw;
	int		pos_x;
	int		pos_y;
	int		pix;
}	t_win;

typedef struct s_flood_fill
{
	int	i;
	int	k;
	int	p;
	int	c;
	int	e;
	int	p_y;
	int	p_x;
}	t_ff;

void	start_init(void);
void	init_window(t_win *ptr);
void	parsing(char *argv1);
void	free_map(char **map);
void	error(char **map, char *str);
int		exit_window(t_win *ptr);
int		keyboard_touch(int keycode, t_win *p);
int		check_char(char c);
int		requirements(char **map, int height, t_ff value);
void	free_images(t_win *p);
int		exit_window(t_win *p);

#endif
