/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:13:31 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/27 15:26:28 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map, const char *file)
{
	map->matrix = NULL;
	map->player_x = 0; // maybe not needed
	map->player_y = 0; // maybe not needed
	map->is_map_valid = true;
	map->is_map_exitable = false;
}

void	init_win(t_win *window, const char *file)
{
	window->mlx = mlx_init();
	window->width = count_columns(file) * 31;
	window->height = count_lines(file) * 32;
	window->title = "so_long";
	window->win = mlx_new_window(window->mlx, window->width, window->height, window->title);
}

void	init_tiles(t_tiles *tiles)
{
	tiles->tile_size = 32;
	tiles->center = "./tiles/center.xpm";
	tiles->box = "./tiles/box.xpm";
	tiles->coin = "./tiles/coin.xpm";
	tiles->player = "./tiles/player.xpm";
	tiles->exit_closed = "./tiles/exit_closed.xpm";
	tiles->exit_open = "./tiles/exit_open.xpm";
}

void	init_images(t_images *img, t_win *window, t_tiles *tiles)
{
	int height;
	int width;
	img->box = mlx_xpm_file_to_image(window->mlx, tiles->box, &height, &width);
	img->center = mlx_xpm_file_to_image(window->mlx, tiles->center, &height, &width);
	img->coin = mlx_xpm_file_to_image(window->mlx, tiles->coin, &height, &width);
	img->player = mlx_xpm_file_to_image(window->mlx, tiles->player, &height, &width);
	img->exit_closed = mlx_xpm_file_to_image(window->mlx, tiles->exit_closed, &height, &width);
	img->exit_open = mlx_xpm_file_to_image(window->mlx, tiles->exit_open, &height, &width);
}