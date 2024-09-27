/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:46:50 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/27 21:44:19 by marcsilv         ###   ########.fr       */
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

/*void	find_objects(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map->matrix[y])
	{
		while (game->map->matrix[y][x])
		{
			if (game->map->matrix[y][x] == NULL)
				print_error("Error: Empty map", game);
			if (game->map->matrix[y][x] )
			
		}
		
	}
	
}*/

void	check_number_of_objects(t_game *game)
{
	if (game->map->coin_count == 0)
		game->map->is_map_valid = false;
	if (game->map->exit_count != 1)
		game->map->is_map_valid = false;
	if (game->map->player_count != 1)
		game->map->is_map_valid = false;
}

//verify line count and compare with the rest of others
//verify the length of lines compare it with length of chars and vice versa
//need to verify if is rectangle and if is a closed rectangle