/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:13:31 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/25 20:32:08 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map, const char *file)
{
	map->matrix = NULL;
	map->is_map_valid = true;
	map->is_map_exitable = true;
	map->is_player_moving = false;
	map->player_moves = 0;
	map->player_pos_x = 0;
	map->player_pos_y = 0;
	map->player_y = 0;
	map->player_x = 0;
	//find_player(map);
}

void	find_player(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x])
		{
			if (map->matrix[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
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
	tiles->coin = "./tiles/coin2.xpm";
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
	tiles->inner_upper_left_corner = "./tiles/inner_upper_left_corner.xpm";
	tiles->inner_upper_right_corner = "./tiles/inner_upper_right_corner.xpm";
	tiles->inner_bottom_left_corner = "./tiles/inner_bottom_left_corner.xpm";
	tiles->inner_bottom_right_corner = "./tiles/inner_bottom_right_corner.xpm";
}

void	init_images(t_images *img, t_win *window, t_tiles *tiles)
{
	int	height;
	int	width;

	img->box = mlx_xpm_file_to_image(window->mlx, tiles->box, &height, &width);
	img->center = mlx_xpm_file_to_image(window->mlx, tiles->center, &height, &width);
	img->coin = mlx_xpm_file_to_image(window->mlx, tiles->coin, &height, &width);
	img->player = mlx_xpm_file_to_image(window->mlx, tiles->player, &height, &width);
	img->outer_upper_wall = mlx_xpm_file_to_image(window->mlx, tiles->outer_upper_wall, &height, &width);
	img->outer_bottom_wall = mlx_xpm_file_to_image(window->mlx, tiles->outer_bottom_wall, &height, &width);
	img->outer_left_wall = mlx_xpm_file_to_image(window->mlx, tiles->outer_left_wall, &height, &width);
	img->outer_right_wall = mlx_xpm_file_to_image(window->mlx, tiles->outer_right_wall, &height, &width);
	img->outer_upper_left_corner = mlx_xpm_file_to_image(window->mlx, tiles->outer_upper_left_corner, &height, &width);
	img->outer_upper_right_corner = mlx_xpm_file_to_image(window->mlx, tiles->outer_upper_right_corner, &height, &width);
	img->outer_bottom_left_corner = mlx_xpm_file_to_image(window->mlx, tiles->outer_bottom_left_corner, &height, &width);
	img->outer_bottom_right_corner = mlx_xpm_file_to_image(window->mlx, tiles->outer_bottom_right_corner, &height, &width);
	img->inner_horizontal_wall = mlx_xpm_file_to_image(window->mlx, tiles->inner_horizontal_wall, &height, &width);
	img->inner_vertical_wall = mlx_xpm_file_to_image(window->mlx, tiles->inner_vertical_wall, &height, &width);
	img->inner_upper_left_corner = mlx_xpm_file_to_image(window->mlx, tiles->inner_upper_left_corner, &height, &width);
	img->inner_upper_right_corner = mlx_xpm_file_to_image(window->mlx, tiles->inner_upper_right_corner, &height, &width);
	img->inner_bottom_left_corner = mlx_xpm_file_to_image(window->mlx, tiles->inner_bottom_left_corner, &height, &width);
	img->inner_bottom_right_corner = mlx_xpm_file_to_image(window->mlx, tiles->inner_bottom_right_corner, &height, &width);
}