/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:38:55 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/20 10:11:24 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_map *map, t_tiles *tiles, t_win *window)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->matrix[y / 32][x / 32] == '1')
				mlx_put_image_to_window(window->mlx, window->win, tiles->center, x * 32, y * 32);
			else if (map->matrix[y / 32][x / 32] == '0')
				mlx_put_image_to_window(window->mlx, window->win, tiles->center, x * 32, y * 32);
			else if (map->matrix[y / 32][x / 32] == 'P')
				mlx_put_image_to_window(window->mlx, window->win, tiles->center, x * 32, y * 32);
			else if (map->matrix[y / 32][x / 32] == 'E')
				mlx_put_image_to_window(window->mlx, window->win, tiles->center, x * 32, y * 32);
			x += 32;
		}
		y += 32;
	}
}

//need to add fuctions that convert from mlx to image??
