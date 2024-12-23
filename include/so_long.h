/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:32:06 by agraille          #+#    #+#             */
/*   Updated: 2024/12/23 13:37:01 by agraille         ###   ########.fr       */
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
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define UP_ARROW    65362
# define LEFT_ARROW  65361
# define DOWN_ARROW  65364
# define RIGHT_ARROW 65363
# define ITEM_FRAME 8

typedef struct s_game
{
	char	**map;
	void	*mlx;
	int		animation_frame;
	void	*win;
	void	*pe;
	void	*pe2;
	void	*pb;
	void	*pb2;
	void	*pc[8];
	void	*pp;
	void	*pp2;
	void	*pp3;
	void	*pp4;
	void	*pp5;
	void	*pp6;
	void	*pp7;
	void	*pp8;
	void	*pp9;
	void	*pw;
	void	*pw2;
	void	*pw3;
	void	*pw4;
	void	*pw5;
	void	*pw6;
	void	*pk;
	int		item_frame;
	int		item_delay;
	int		wolf_delay2;
	int		frame_counter;
	int		frame_counter2;
	int		last_frame;
	int		coin;
	int		size_x;
	int		size_y;
	int		player_x;
	int		player_y;
	int		wolf_x;
	int		wolf_y;
	int		pix;
	int		moove;
	int		y_size;
	int		x_size;
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

void	start_init(char *argv1, int height);
int		parsing(char *argv1);
void	free_map(char **map);
void	error(char **map, char *str);
int		render_animation(t_win *p);
void	load_pictures(t_win *p);
void	render_map(t_win *p);
void	move_player(t_win *p, int dir_x, int dir_y);
int		exit_window(t_win *ptr);
int		keyboard_touch(int keycode, t_win *p);
int		check_char(char c);
int		requirements(char **map, int height, t_ff value);
void	free_pictures(t_win *p);
int		exit_window(t_win *p);
char	**map_in_tab(char *argv1, int height);
int		printmoove(t_win *p);
int		check_frame(t_win *p);
void	move_wolf(t_win *p);
void	render_map_bis(t_win *p);
void	check_winner(t_win *p);

#endif
