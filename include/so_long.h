/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:32:07 by agraille          #+#    #+#             */
/*   Updated: 2024/12/17 10:51:43 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*ptr_mlx;
	void	*window;
}	t_game;

void	init_window(t_game *ptr);
void	exit_window(t_game *ptr);
#endif
