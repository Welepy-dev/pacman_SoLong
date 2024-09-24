/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:13:31 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/20 16:47:18 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map, const char *file)
{
	map->matrix = NULL;
	map->player_x = 0;
	map->player_y = 0;
	map->is_map_valid = true;
	map->is_map_exitable = true;
}

void	init_win(t_win *window, const char *file)
{
	window->mlx = mlx_init();
	window->width = count_columns(file) * 31;
	window->height = count_lines(file) * 32;
	window->title = "so_long";
	window->win = mlx_new_window(window->mlx, window->width, window->height, window->title);
	window->time_minutes = 0; // for now
	window->time_seconds = 0; // for now
}

void	init_tiles(t_tiles *tiles)
{
	tiles->tile_size = 32;
	tiles->center = "./tiles/center.xpm";
	tiles->ghost = "../tiles/ghost.xpm";
	tiles->box = "./tiles/box.xpm";
	tiles->coin = "./tiles/coin.xpm";
	tiles->player = "./tiles/player.xpm";
	tiles->outer_upper_wall = "./tiles/outer_upper_wall.xpm";
	tiles->outer_bottom_wall = "./tiles/outer_bottom_wall.xpm";
	tiles->outer_left_wall = "./tiles/outer_left_wall.xpm";
	tiles->outer_right_wall = "./tiles/outer_right_wall.xpm";
	tiles->outer_upper_left_corner = "./tiles/outer_upper_left_corner.xpm";
	tiles->outer_upper_right_corner = "./tiles/outer_upper_right_corner.xpm";
	tiles->outer_bottom_left_corner = "./tiles/outer_bottom_left_corner.xpm";
	tiles->outer_bottom_right_corner = "./tiles/outer_bottom_right_corner.xpm";
	tiles->inner_horizontal_wall = "./tiles/inner_horizontal_wall.xpm";
	tiles->inner_vertical_wall = "./tiles/inner_vertical_wall.xpm";
}