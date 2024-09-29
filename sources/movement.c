/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:54:12 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/28 18:59:16 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to(t_game *game, int x, int y)
{
	if ((game->map->matrix[y][x] != '1') && (game->map->matrix[y][x] != 'E'))
	{
		if (game->map->matrix[y][x] == 'C')
			game->map->coin_count--;
		is_exitable(game);
		game->map->matrix[game->map->pac_y][game->map->pac_x] = '0';
		game->map->matrix[y][x] = 'P';
		//mlx_clear_window(game->window->mlx, game->window->win);
		render_map(game);
		//ft_printf("Number of steps: %d\n", game->map->pac_steps++);
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == UP || keycode == UP_ARROW)
		move_to(game, game->map->pac_x, game->map->pac_y - 1);
	else if (keycode == DOWN || keycode == DOWN_ARROW)
		move_to(game, game->map->pac_x, game->map->pac_y + 1);
	else if (keycode == LEFT || keycode == LEFT_ARROW)
		move_to(game, game->map->pac_x - 1, game->map->pac_y);
	else if (keycode == RIGHT || keycode == RIGHT_ARROW)
		move_to(game, game->map->pac_x + 1, game->map->pac_y);
	else if (keycode == ESC)
	{
		mlx_clear_window(game->window->mlx, game->window->win);
		mlx_destroy_window(game->window->mlx, game->window->win);
		exit(0);
	}
	return (0);
}
