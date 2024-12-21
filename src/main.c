/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:58:30 by agraille          #+#    #+#             */
/*   Updated: 2024/12/21 13:16:08 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	int	height;

	if (argc != 2)
		exit(EXIT_FAILURE);
	height = parsing(argv[1]);
	start_init(argv[1], height);
	return (0);
}
