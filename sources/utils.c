/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:17:46 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/29 11:00:40 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->window->mlx, game->img->box);
	mlx_destroy_image(game->window->mlx, game->img->center);
	mlx_destroy_image(game->window->mlx, game->img->coin);
	mlx_destroy_image(game->window->mlx, game->img->pac);
	mlx_destroy_image(game->window->mlx, game->img->exit_open);
	mlx_destroy_image(game->window->mlx, game->img->exit_closed);
}

void	is_exitable(t_game *game)
{
	if (game->map->coin_count == 0)
		game->map->is_map_exitable = true;
}