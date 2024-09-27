/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:08:01 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/27 21:35:50 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map		map;
	t_tiles		tiles;
	t_win		window;
	t_images	img;
	t_game		game;

	if (ac != 2)
		print_error("Invalid number arguments", NULL);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
		print_error("Invalid file extension", &game);
	game.map = &map;
	game.tiles = &tiles;
	game.window = &window;
	game.img = &img;
	init_map(&game, av[1]);
	init_tiles(&game);
	parse(av[1], &game);
	init_win(&game, av[1]);
	render_map(&game);
	mlx_key_hook(window.win, key_hook, &game);
	mlx_loop(window.mlx);
	return (0);
}
