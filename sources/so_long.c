/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:08:01 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/29 19:56:29 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*player image rotation*/

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
	validate(ac, av, &game);
	render_map(&game);
	mlx_key_hook(window.win, key_hook, &game);
	
	mlx_loop(window.mlx);
	return (0);
}

//check parsing again
//check each error message
//test all errors
//flood fill
//check if there is at least 1 collectible

int	animations(t_game *game)
{
	static int frame_timer = 0;

	frame_timer++;
	if (frame_timer >= game->map->frame_delay)
	{
		game->map->current_frame = (game->map->current_frame + 1) % game->map->frame_count;	// Cycle through frames
		frame_timer = 0;										// Reset the timer
	}
	
}