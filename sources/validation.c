/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:46:50 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/28 18:47:16 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_exitable(t_game *game)
{
	if (game->map->coin_count == 0)
		game->map->is_map_exitable = true;
}

void	validation(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map->matrix[y])
	{
		while (game->map->matrix[y][x])
		{
			if (game->map->matrix[y][x] != '1' \
			|| game->map->matrix[y][x] != '0' \
			|| game->map->matrix[y][x] != 'C' \
			|| game->map->matrix[y][x] != 'E' \
			|| game->map->matrix[y][x] != 'P')
			{
				game->map->is_map_valid = false;
				print_error("Error, map has unknown object", game);
			}
			if (game->map->is_map_valid == false)
				print_error("Error, map has unknown object", game);
		}
	}
}

void	check_number_of_objects(t_game *game)
{
	if (game->map->coin_count == 0)
		game->map->is_map_valid = false;
	if (game->map->exit_count != 1)
		game->map->is_map_valid = false;
	if (game->map->player_count != 1)
		game->map->is_map_valid = false;
}


void	check_rectangle(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	width = ft_strlen(game->map->matrix[0]);
	while (game->map->matrix[height])
		height++;
	if (height == width)
		print_error("Error: Map is not a rectangle", game);
}

void	check_lines(t_game *game)
{
	int	i;
	int	len;
	int	next_len;

	i = 0;
	len = ft_strlen(game->map->matrix[0]);
	while (game->map->matrix[i])
	{
		if (ft_strlen(game->map->matrix[i]) != len)
			game->map->is_map_valid = false;
		i++;
	}
}

void	check_borders(t_game *game)
{
	vertical_check(game, 0, 0);
	horizontal_check(game, 0, 0);
	vertical_check(game, 0, game->window->width);
	horizontal_check(game, game->window->height, 0);
}

void	horizontal_check(t_game *game, int y, int x)
{
	while (game->map->matrix[y][x])
	{
		if (game->map->matrix[y][x] != '1')
			game->map->is_map_valid = false;
		x++;
	}
}

void	vertical_check(t_game *game, int y, int x)
{
	while (game->map->matrix[y][x])
	{
		if (game->map->matrix[y][x] != '1')
			game->map->is_map_valid = false;
		y++;
	}
}

void	validate(int ac, char **av)
{
	if (ac != 2)
		print_error("Invalid number arguments", NULL);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
		print_error("Invalid file extension", NULL);
}