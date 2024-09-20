/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:38:55 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/20 10:32:09 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
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
			if (map->matrix[y][x] == '1')
				mlx_xpm_to_image(window->mlx, tiles->box, x * 32, y * 32);
			else if (map->matrix[y][x] == '0')
				mlx_xpm_to_image(window->mlx, tiles->center, x * 32, y * 32);
			else if (map->matrix[y][x] == 'C')
				mlx_xpm_to_image(window->mlx, tiles->pellet, x * 32, y * 32);
			else if (map->matrix[y / 32][x / 32] == 'P')
				mlx_xpm_to_image(window->mlx, window->win, tiles->center, x * 32, y * 32);
			else if (map->matrix[y / 32][x / 32] == 'E')
				mlx_xpm_to_image(window->mlx, window->win, tiles->center, x * 32, y * 32);
			x++;
		}
		y++;
	}
}*/
//need to add fuctions that convert from mlx to image??
