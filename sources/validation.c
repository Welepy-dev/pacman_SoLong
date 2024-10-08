/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:46:50 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/08 10:03:13 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_args(int ac, const char *av)
{
	if (ac != 2)
		print_error("Invalid number of arguments");
	if (ft_strncmp(av + ft_strlen(av) - 4, ".ber", 4) != 0)
		print_error("Invalid file extension");
}

void	validate(t_game *game)
{	
	int		height;
	int		width;

	height = ft_matrix_len(game->map->matrix);
	width = ft_strlen(game->map->matrix[0]);
	if (height < 3 || width < 3 || width == height)
		game->map->is_map_valid = false;
	check_lines(game);
	find_player(game);
	check_borders(game);
	check_chars(game->map);
	check_number_of_objects(game);
	if (game->map->is_map_valid == false)
	{
		ft_matrix_free(game->map->matrix);
		print_error("Invalid map");
	}
	flood_fill_validate(game);
}

void	check_chars(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x])
		{
			if (map->matrix[y][x] != '1' \
			&& map->matrix[y][x] != '0' \
			&& map->matrix[y][x] != 'C' \
			&& map->matrix[y][x] != 'E' \
			&& map->matrix[y][x] != 'P' \
			&& map->matrix[y][x] != '\n')
			{
				map->is_map_valid = false;
				return ;
			}
			x++;
		}
		y++;
	}
}
