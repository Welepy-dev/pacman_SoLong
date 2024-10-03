/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:54:12 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/03 09:03:18 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to(t_game *game, int x, int y)
{
	if ((game->map->matrix[y][x] != '1') && ((game->map->matrix[y][x] != 'E') \
	|| game->map->is_map_exitable))
	{
		if (game->map->matrix[y][x] == 'C')
			game->map->coin_count--;
		if (game->map->matrix[y][x] == 'E')
		{
			destroy_images(game);
			mlx_destroy_window(game->window->mlx, game->window->win);
			mlx_destroy_display(game->window->mlx);
			ft_matrix_free(game->map->matrix);
			free(game->window->mlx);
			exit(0);
		}
		is_exitable(game);
		game->map->matrix[game->map->pac_y][game->map->pac_x] = '0';
		game->map->matrix[y][x] = 'P';
		destroy_images(game);
		mlx_clear_window(game->window->mlx, game->window->win);
		render_map(game);
		ft_printf("Number of steps: %d\n", ++game->map->pac_steps);
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
		close_window(game);
	return (0);
}
