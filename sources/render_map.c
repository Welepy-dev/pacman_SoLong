/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:38:55 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/27 14:56:01 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_map *map, t_tiles *tiles, t_win *window, t_images *img)
{
	int	x;
	int	y;
	int height;
	int width;
	y = 0;
	init_images(img, window, tiles);
	while (y < window->height / 32)
	{
		x = 0;
		while (x < window->width / 32)
		{
			if (map->matrix[y][x] == '1')
				mlx_put_image_to_window(window->mlx, window->win, img->box, x * 32, y * 32);
			else if (map->matrix[y][x] == '0')
				mlx_put_image_to_window(window->mlx, window->win, img->center, x * 32, y * 32);
			else if (map->matrix[y][x] == 'C')
				mlx_put_image_to_window(window->mlx, window->win, img->coin, x * 32, y * 32);
			else if (map->matrix[y][x] == 'E' && !map->is_map_exitable)
				mlx_put_image_to_window(window->mlx, window->win, img->exit_closed, x * 32, y * 32);
			else if (map->matrix[y][x] == 'E' && map->is_map_exitable)
				mlx_put_image_to_window(window->mlx, window->win, img->exit_open, x * 32, y * 32);
			else if (map->matrix[y][x] == 'P')
			{
				mlx_put_image_to_window(window->mlx, window->win, img->player, x * 32 , y * 32);
				map->player_x = x;
				map->player_y = y;
			}
			x++;
		}
		y++;
	}
}