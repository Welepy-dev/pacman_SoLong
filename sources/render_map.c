/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:38:55 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/25 20:43:50 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	render_map(t_map *map, t_tiles *tiles, t_win *window, t_images *img)
// {
// 	int	x;
// 	int	y;
// 	int height;
// 	int width;
// 	y = 0;
// 	init_images(img, window, tiles);
// 	while (y < window->height / 32)
// 	{
// 		x = 0;
// 		while (x < window->width / 32)
// 		{
// 			if (map->matrix[y][x] == '1')
// 			{
// 				if ((map->matrix[y][x]) && x == 0 && y == 0)
// 					mlx_put_image_to_window(window->mlx, window->win, img->outer_upper_left_corner, x * 32, y * 32);
// 				else if ((map->matrix[y][x]) && x == window->width / 32 - 1 && y == 0)
// 					mlx_put_image_to_window(window->mlx, window->win, img->outer_upper_right_corner, x * 32, y * 32);
// 				else if ((map->matrix[y][x]) && x == 0 && y == window->height / 31 - 1)
// 					mlx_put_image_to_window(window->mlx, window->win, img->outer_bottom_left_corner, x * 32, y * 32);
// 				else if ((map->matrix[y][x]) && x == window->width / 32 - 1 && y == window->height / 32 - 1)
// 				 	mlx_put_image_to_window(window->mlx, window->win, img->outer_bottom_right_corner, x * 32, y * 32);
// 				else if ((map->matrix[y][x]) && y == 0)
// 					mlx_put_image_to_window(window->mlx, window->win, img->outer_upper_wall, x * 32, y * 32);
// 				else if ((map->matrix[y][x]) && y == window->height / 32 - 1)
// 					mlx_put_image_to_window(window->mlx, window->win, img->outer_bottom_wall, x * 32, y * 32);
// 				else if ((map->matrix[y][x]) && x == 0)
// 					mlx_put_image_to_window(window->mlx, window->win, img->outer_left_wall, x * 32, y * 32);
// 				else if ((map->matrix[y][x]) && x == window->width / 32 - 1)
// 					mlx_put_image_to_window(window->mlx, window->win, img->outer_right_wall, x * 32, y * 32);
// 				// else
// 				// {
// 				// 	mlx_put_image_to_window(window->mlx, window->win, img->box, x * 32, y * 32);
// 				// }
// 				else if ((map->matrix[y][x]) && map->matrix[y][x - 1] == '1' && map->matrix[y][x + 1] == '1')
// 				{
// 					// Horizontal inner wall
// 					mlx_put_image_to_window(window->mlx, window->win, img->inner_horizontal_wall, x * 32, y * 32);
// 				}
// 				else if ((map->matrix[y][x]) && map->matrix[y - 1][x] == '1' && map->matrix[y + 1][x] == '1')
// 				{
// 					// Vertical inner wall
// 					mlx_put_image_to_window(window->mlx, window->win, img->inner_vertical_wall, x * 32, y * 32);
// 				}
// 				/*else if ((map->matrix[y][x]) && map->matrix[y - 1][x] == '1' && map->matrix[y][x - 1] == '1')
// 				{
// 					// Top-left inner corner wall
// 					mlx_put_image_to_window(window->mlx, window->win, img->inner_top_left_corner, x * 32, y * 32);
// 				}
// 				else if ((map->matrix[y][x]) && map->matrix[y - 1][x] == '1' && map->matrix[y][x + 1] == '1')
// 				{
// 					// Top-right inner corner wall
// 					mlx_put_image_to_window(window->mlx, window->win, img->inner_top_right_corner, x * 32, y * 32);
// 				}
// 				else if ((map->matrix[y][x]) && map->matrix[y + 1][x] == '1' && map->matrix[y][x - 1] == '1')
// 				{
// 					// Bottom-left inner corner wall
// 					mlx_put_image_to_window(window->mlx, window->win, img->inner_bottom_left_corner, x * 32, y * 32);
// 				}
// 				else if ((map->matrix[y][x]) && map->matrix[y + 1][x] == '1' && map->matrix[y][x + 1] == '1')
// 				{
// 					// Bottom-right inner corner wall
// 					mlx_put_image_to_window(window->mlx, window->win, img->inner_bottom_right_corner, x * 32, y * 32);
// 				}*/

// 			}
// 			else if (map->matrix[y][x] == '0')
// 				mlx_put_image_to_window(window->mlx, window->win, img->center, x * 32, y * 32);
// 			else if (map->matrix[y][x] == 'C')
// 				mlx_put_image_to_window(window->mlx, window->win, img->coin, x * 32, y * 32);
// 			else if (map->matrix[y][x] == 'P')
// 			{
// 				mlx_put_image_to_window(window->mlx, window->win, img->player, x * 32 , y * 32);
// 				map->player_x = x;
// 				map->player_y = y;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

/*void	render_map(t_map *map, t_tiles *tiles, t_win *window, t_images *img)
{
	int	x;
	int	y;

	y = 0;
	init_images(img, window, tiles);
	while (y < window->height / 32)
	{
		x = 0;
		while (x < window->width / 32)
		{
			if (map->matrix[y][x] == '1')
			{

				mlx_put_image_to_window(window->mlx, window->win, img->box, x * 32, y * 32);
				// Outer walls
				// if (x == 0 && y == 0)
				// 	mlx_put_image_to_window(window->mlx, window->win, img->outer_upper_left_corner, x * 32, y * 32);
				// else if (x == window->width / 32 - 1 && y == 0)
				// 	mlx_put_image_to_window(window->mlx, window->win, img->outer_upper_right_corner, x * 32, y * 32);
				// else if (x == 0 && y == window->height / 32 - 1)
				// 	mlx_put_image_to_window(window->mlx, window->win, img->outer_bottom_left_corner, x * 32, y * 32);
				// else if (x == window->width / 32 - 1 && y == window->height / 32 - 1)
				//  	mlx_put_image_to_window(window->mlx, window->win, img->outer_bottom_right_corner, x * 32, y * 32);
				// else if (y == 0)
				// 	mlx_put_image_to_window(window->mlx, window->win, img->outer_upper_wall, x * 32, y * 32);
				// else if (y == window->height / 32 - 1)
				// 	mlx_put_image_to_window(window->mlx, window->win, img->outer_bottom_wall, x * 32, y * 32);
				// else if (x == 0)
				// 	mlx_put_image_to_window(window->mlx, window->win, img->outer_left_wall, x * 32, y * 32);
				// else if (x == window->width / 32 - 1)
				// 	mlx_put_image_to_window(window->mlx, window->win, img->outer_right_wall, x * 32, y * 32);

				// // Inner walls
				// else if (map->matrix[y][x - 1] == '1' && map->matrix[y][x + 1] == '1')
				// 	mlx_put_image_to_window(window->mlx, window->win, img->inner_horizontal_wall, x * 32, y * 32);
				// else if (map->matrix[y - 1][x] == '1' && map->matrix[y + 1][x] == '1')
				// 	mlx_put_image_to_window(window->mlx, window->win, img->inner_vertical_wall, x * 32, y * 32);
				// else if (map->matrix[y - 1][x] == '1' && map->matrix[y][x - 1] == '1')
				// 	mlx_put_image_to_window(window->mlx, window->win, img->inner_bottom_right_corner, x * 32, y * 32);
				// else if (map->matrix[y - 1][x] == '1' && map->matrix[y][x + 1] == '1')
				// 	mlx_put_image_to_window(window->mlx, window->win, img->inner_bottom_left_corner, x * 32, y * 32);
				// else if (map->matrix[y + 1][x] == '1' && map->matrix[y][x - 1] == '1')
				// 	mlx_put_image_to_window(window->mlx, window->win, img->inner_upper_right_corner, x * 32, y * 32);
				// else if (map->matrix[y + 1][x] == '1' && map->matrix[y][x + 1] == '1')
				// 	mlx_put_image_to_window(window->mlx, window->win, img->inner_upper_left_corner, x * 32, y * 32);
				// else if ((map->matrix[y][x]) && map->matrix[y][x + 1] == '1' && map->matrix[y + 1][x] == '1')
				// 	mlx_put_image_to_window(window->mlx, window->win, img->box, x * 32, y * 32);
				// else if ((map->matrix[y][x]) && map->matrix[y][x - 1] == '1' && map->matrix[y + 1][x] == '1')
				// 	mlx_put_image_to_window(window->mlx, window->win, img->box, x * 32, y * 32);
				// else if ((map->matrix[y][x]) && map->matrix[y][x + 1] == '1' && map->matrix[y - 1][x] == '1')
				// 	mlx_put_image_to_window(window->mlx, window->win, img->box, x * 32, y * 32);
				// else if ((map->matrix[y][x]) && map->matrix[y][x - 1] == '1' && map->matrix[y - 1][x] == '1')
				// 	mlx_put_image_to_window(window->mlx, window->win, img->box, x * 32, y * 32);

				// // Default inner wall
				// else
				// 	mlx_put_image_to_window(window->mlx, window->win, img->box, x * 32, y * 32);
			}
			// Floor
			else if (map->matrix[y][x] == '0')
				mlx_put_image_to_window(window->mlx, window->win, img->center, x * 32, y * 32);

			// Collectible
			else if (map->matrix[y][x] == 'C')
				mlx_put_image_to_window(window->mlx, window->win, img->coin, x * 32, y * 32);

			// Player
			else if (map->matrix[y][x] == 'P')
			{
				mlx_put_image_to_window(window->mlx, window->win, img->player, x * 32, y * 32);
				map->player_x = x;
				map->player_y = y;
			}
			x++;
		}
		y++;
	}
}*/

void	render_map(t_map *map, t_tiles *tiles, t_win *window, t_images *img, t_so_long *so_long)
{
	int	x;
	int	y;

	y = 0;
	init_images(img, window, tiles);
	while (y < window->height / 32)
	{
		x = 0;
		while (x < window->width / 32)
		{
			if (map->matrix[y][x] == '1')
			{
				if (x == 0 && y == 0)
					mlx_put_image_to_window(window->mlx, window->win, img->outer_upper_left_corner, x * 32, y * 32);
				else if (x == window->width / 32 - 1 && y == 0)
					mlx_put_image_to_window(window->mlx, window->win, img->outer_upper_right_corner, x * 32, y * 32);
				else if (x == 0 && y == window->height / 32 - 1)
					mlx_put_image_to_window(window->mlx, window->win, img->outer_bottom_left_corner, x * 32, y * 32);
				else if (x == window->width / 32 - 1 && y == window->height / 32 - 1)
				 	mlx_put_image_to_window(window->mlx, window->win, img->outer_bottom_right_corner, x * 32, y * 32);
				else if (y == 0)
					mlx_put_image_to_window(window->mlx, window->win, img->outer_upper_wall, x * 32, y * 32);
				else if (y == window->height / 32 - 1)
					mlx_put_image_to_window(window->mlx, window->win, img->outer_bottom_wall, x * 32, y * 32);
				else if (x == 0)
					mlx_put_image_to_window(window->mlx, window->win, img->outer_left_wall, x * 32, y * 32);
				else if (x == window->width / 32 - 1)
					mlx_put_image_to_window(window->mlx, window->win, img->outer_right_wall, x * 32, y * 32);

				// Inner walls
				else if (map->matrix[y][x - 1] == '1' && map->matrix[y][x + 1] == '1')
					mlx_put_image_to_window(window->mlx, window->win, img->inner_horizontal_wall, x * 32, y * 32);
				else if (map->matrix[y - 1][x] == '1' && map->matrix[y + 1][x] == '1')
					mlx_put_image_to_window(window->mlx, window->win, img->inner_vertical_wall, x * 32, y * 32);
				else if (map->matrix[y - 1][x] == '1' && map->matrix[y][x - 1] == '1')
					mlx_put_image_to_window(window->mlx, window->win, img->inner_bottom_right_corner, x * 32, y * 32);
				else if (map->matrix[y - 1][x] == '1' && map->matrix[y][x + 1] == '1')
					mlx_put_image_to_window(window->mlx, window->win, img->inner_bottom_left_corner, x * 32, y * 32);
				else if (map->matrix[y + 1][x] == '1' && map->matrix[y][x - 1] == '1')
					mlx_put_image_to_window(window->mlx, window->win, img->inner_upper_right_corner, x * 32, y * 32);
				else if (map->matrix[y + 1][x] == '1' && map->matrix[y][x + 1] == '1')
					mlx_put_image_to_window(window->mlx, window->win, img->inner_upper_left_corner, x * 32, y * 32);
				else if ((map->matrix[y][x]) && map->matrix[y][x + 1] == '1' && map->matrix[y + 1][x] == '1')
					mlx_put_image_to_window(window->mlx, window->win, img->box, x * 32, y * 32);
				else if ((map->matrix[y][x]) && map->matrix[y][x - 1] == '1' && map->matrix[y + 1][x] == '1')
					mlx_put_image_to_window(window->mlx, window->win, img->box, x * 32, y * 32);
				else if ((map->matrix[y][x]) && map->matrix[y][x + 1] == '1' && map->matrix[y - 1][x] == '1')
					mlx_put_image_to_window(window->mlx, window->win, img->box, x * 32, y * 32);
				else if ((map->matrix[y][x]) && map->matrix[y][x - 1] == '1' && map->matrix[y - 1][x] == '1')
					mlx_put_image_to_window(window->mlx, window->win, img->box, x * 32, y * 32);

				// Default inner wall
				else
					mlx_put_image_to_window(window->mlx, window->win, img->box, x * 32, y * 32);
			}
			else if (map->matrix[y][x] == '0')
				mlx_put_image_to_window(window->mlx, window->win, img->center, x * 32, y * 32);
			else if (map->matrix[y][x] == 'C')
				mlx_put_image_to_window(window->mlx, window->win, img->coin, x * 32, y * 32);
			else if (map->matrix[y][x] == '9')
				mlx_put_image_to_window(window->mlx, window->win, img->coin, x * 32, y * 32);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(window->mlx, window->win, img->player, so_long->player_x_pos, so_long->player_y_pos);
}
