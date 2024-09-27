/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:08:01 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/27 16:15:18 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	int			x;
	int			y;

	if (keycode == UP)
	{
		if ((game->map->matrix[game->map->pac_y - 1][game->map->pac_x] != '1') \
		&& (game->map->matrix[game->map->pac_y - 1][game->map->pac_x] != 'E'))
		{
			game->map->matrix[game->map->pac_y][game->map->pac_x] = '0';
			game->map->matrix[game->map->pac_y - 1][game->map->pac_x] = 'P';
			ft_printf("Number of steps: %d\n", game->map->pac_steps++);
		}
	}
	else if (keycode == DOWN)
	{
		if ((game->map->matrix[game->map->pac_y + 1][game->map->pac_x] != '1') \
		&& (game->map->matrix[game->map->pac_y + 1][game->map->pac_x] != 'E'))
		{
			game->map->matrix[game->map->pac_y][game->map->pac_x] = '0';
			game->map->matrix[game->map->pac_y + 1][game->map->pac_x] = 'P';
			ft_printf("Number of steps: %d\n", game->map->pac_steps++);
		}
	}
	else if (keycode == LEFT)
	{
		if ((game->map->matrix[game->map->pac_y][game->map->pac_x - 1] != '1') \
		&& (game->map->matrix[game->map->pac_y][game->map->pac_x - 1] != 'E'))
		{
			game->map->matrix[game->map->pac_y][game->map->pac_x] = '0';
			game->map->matrix[game->map->pac_y][game->map->pac_x - 1] = 'P';
			ft_printf("Number of steps: %d\n", game->map->pac_steps++);
		}
	}
	else if (keycode == RIGHT)
	{
		if ((game->map->matrix[game->map->pac_y][game->map->pac_x + 1] != '1') \
		&& (game->map->matrix[game->map->pac_y][game->map->pac_x + 1] != 'E'))
		{
			game->map->matrix[game->map->pac_y][game->map->pac_x] = '0';
			game->map->matrix[game->map->pac_y][game->map->pac_x + 1] = 'P';
			ft_printf("Number of steps: %d\n", game->map->pac_steps++);
		}
	}
	render_map(game);
	return (0);
}

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
	parse_map(av[1], &game);
	init_win(&game, av[1]);
	render_map(&game);
	mlx_key_hook(window.win, key_hook, &game);
	mlx_loop(window.mlx);
	return (0);
}
