/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:31:00 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/03 09:03:14 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_number_of_objects(t_game *game)
{
	if (game->map->coin_count < 0)
		game->map->is_map_valid = false;
	if (game->map->exit_count != 1)
		game->map->is_map_valid = false;
	if (game->map->player_count != 1)
		game->map->is_map_valid = false;
}

void	check_lines(t_game *game)
{
	int		i;
	int		len;
	
	i = 0;
	len = ft_strlen(game->map->matrix[0]) - 1;
	while (i < (ft_matrix_len(game->map->matrix) - 1))
	{
		if ((ft_strlen(game->map->matrix[i]) - 1) != len)
			game->map->is_map_valid = false;
		i++;
	}
}

void	find_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->matrix[y])
	{
		x = 0;
		while (game->map->matrix[y][x])
		{
			if (game->map->matrix[y][x] == 'P')
			{
				game->map->pac_x = x;
				game->map->pac_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	check_borders(t_game *game)
{
	int	altura;
	int	comprimento;
	int	j;

	altura = ft_matrix_len(game->map->matrix);
	comprimento = ft_strlen(game->map->matrix[0]);
	j = 0;
	while (j < altura)
	{
		if (game->map->matrix[j][0] != '1')
			game->map->is_map_valid = false;
		if (game->map->matrix[j][comprimento - 2] != '1')
			game->map->is_map_valid = false;
		j++;
	}
	j = 0;
	while (j < comprimento - 1)
	{
		if (game->map->matrix[0][j] != '1')
			game->map->is_map_valid = false;
		if (game->map->matrix[altura - 1][j] != '1')
			game->map->is_map_valid = false;
		j++;
	}
}

int	close_window(t_game *game)
{
	destroy_images(game);
	mlx_destroy_window(game->window->mlx, game->window->win);
	mlx_destroy_display(game->window->mlx);
	ft_matrix_free(game->map->matrix);
	free(game->window->mlx);
	exit(0);
	return (0);
}