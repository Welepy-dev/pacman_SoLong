/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:08:01 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/29 04:21:40 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*player image rotation*/


int	main(int ac, char **av)
{
	t_map		map;
	t_tiles		tiles;
	t_win		window;
	t_images	img;
	t_game		game;

	validate_args(ac, av[1]);
	game.map = &map;
	game.tiles = &tiles;
	game.window = &window;
	game.img = &img;
	init_map(&game, av[1]);
	init_tiles(&game);
	parse(av[1], &game);
	init_win(&game, av[1]);
	while (game.map->is_map_valid)
		validate(ac, av, &game);
	render_map(&game);
	mlx_key_hook(window.win, key_hook, &game);
	mlx_loop(window.mlx);
	return (0);
}

//check parsing again
//check each error message
//flood fill
//check if there is at least 1 collectible