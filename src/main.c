/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:58:30 by agraille          #+#    #+#             */
/*   Updated: 2024/12/18 13:34:15 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		exit(EXIT_FAILURE);
	if (!parsing(argv[1]))
		exit(EXIT_FAILURE);
	// start_init();
	return (0);
}
