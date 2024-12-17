/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:58:30 by agraille          #+#    #+#             */
/*   Updated: 2024/12/17 10:49:13 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(void)
{
	t_game *ptr;
	
	ptr = malloc(sizeof(t_game));
	if (!ptr)
		exit(EXIT_FAILURE);
	init_window(ptr);
}
