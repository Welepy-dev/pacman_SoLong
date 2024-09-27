/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:38:55 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/27 16:53:18 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	int	x;
	int	y;
	int height;
	int width;
	y = 0;
	init_images(game);
	while (y < game->window->height / 32)
	{
		x = 0;
		while (x < game->window->width / 32)
		{
			if (game->map->matrix[y][x] == '1')
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->img->box, x * 32, y * 32);
			else if (game->map->matrix[y][x] == '0')
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->img->center, x * 32, y * 32);
			else if (game->map->matrix[y][x] == 'C')
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->img->coin, x * 32, y * 32);
			else if (game->map->matrix[y][x] == 'E' && !game->map->is_map_exitable)
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->img->exit_closed, x * 32, y * 32);
			else if (game->map->matrix[y][x] == 'E' && game->map->is_map_exitable)
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->img->exit_open, x * 32, y * 32);
			else if (game->map->matrix[y][x] == 'P')
			{
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->img->pac, x * 32 , y * 32);
				game->map->pac_x = x;
				game->map->pac_y = y;
			}
			x++;
		}
		y++;
	}
}