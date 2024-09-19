/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:08:01 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/19 16:42:25 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_tiles	tiles;
	t_win	window;

	if (argc == 2)
	{
		init_map(&map, argv[1]);
		init_tiles(&tiles);
		parse_map(argv[1], &map);
		init_win(&window, argv[1], window.mlx, window.win);
		if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
			print_error("Invalid file extension", &map);
		render_map(&map, &tiles, &window);
		mlx_loop(window.mlx);
	}
	else
		print_error("Invalid number of arguments", NULL);
	return (0);
}
