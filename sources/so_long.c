/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:08:01 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/03 11:55:45 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map		map;
	t_images	img;
	t_game		game;
	t_tiles		tiles;
	t_win		window;

	validate_args(ac, av[1]);
	game.map = &map;
	game.tiles = &tiles;
	game.window = &window;
	game.img = &img;
	init(&game, av[1]);
	render_map(&game);
	mlx_hook(window.win, 17, 0, close_window, &game);
	mlx_key_hook(window.win, key_hook, &game);
	mlx_loop(window.mlx);
	return (0);
}
//makefile