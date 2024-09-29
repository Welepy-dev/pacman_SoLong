/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:13:31 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/29 10:34:35 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game *game, const char *file)
{
	game->map->pac_x = 0;
	game->map->pac_y = 0;
	game->map->matrix = NULL;
	game->map->pac_steps = 0;
	game->map->is_map_valid = true;
	game->map->is_map_exitable = false;
}

void	init_win(t_game *game, const char *file)
{
	game->window->mlx = mlx_init();
	game->window->title = "so_long";
	game->window->height = count_lines(file) * 32;
	game->window->width = count_columns(file) * 31;
	game->window->win = mlx_new_window(game->window->mlx, \
	game->window->width, game->window->height, game->window->title);
}

void	init_tiles(t_game *game)
{
	game->tiles->tile_size = 32;
	game->tiles->box = "./tiles/box.xpm";
	game->tiles->pac = "./tiles/pac.xpm";
	game->tiles->coin = "./tiles/coin.xpm";
	game->tiles->center = "./tiles/center.xpm";
	game->tiles->exit_open = "./tiles/exit_open.xpm";
	game->tiles->exit_closed = "./tiles/exit_closed.xpm";
}

void	init_images(t_game *game)
{
	int	width;
	int	height;

	game->img->box = mlx_xpm_file_to_image(game->window->mlx, \
	game->tiles->box, &height, &width);
	game->img->pac = mlx_xpm_file_to_image(game->window->mlx, \
	game->tiles->pac, &height, &width);
	game->img->coin = mlx_xpm_file_to_image(game->window->mlx, \
	game->tiles->coin, &height, &width);
	game->img->center = mlx_xpm_file_to_image(game->window->mlx, \
	game->tiles->center, &height, &width);
	game->img->exit_open = mlx_xpm_file_to_image(game->window->mlx, \
	game->tiles->exit_open, &height, &width);
	game->img->exit_closed = mlx_xpm_file_to_image(game->window->mlx, \
	game->tiles->exit_closed, &height, &width);
}

void	init(t_game *game, const char *file)
{
	init_map(game, file);
	init_tiles(game);
	parse(file, game);
	init_win(game, file);
}