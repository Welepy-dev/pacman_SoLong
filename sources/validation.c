/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:46:50 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/02 16:46:37 by marcsilv         ###   ########.fr       */
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

void	validate(int ac, t_game *game, const char *av)
{	
	char	**map;
	int		height;
	int		width;

	height = ft_matrix_len(game->map->matrix);
	width = ft_strlen(game->map->matrix[0]);
	map = copy_map(game->map->matrix);
	if (height < 3 || width < 3 || width == height)
		game->map->is_map_valid = false;
	check_lines(game);
	check_number_of_objects(game);
	check_borders(game);
	find_player(game);
	flood_fill_validate(map, game);
	if (game->map->is_map_valid == false)
	{
		ft_matrix_free(game->map->matrix);
		print_error("Invalid map");
	}
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
			&& map->matrix[y][x] != 'P')
			{
				map->is_map_valid = false;
				return ;
			}
			x++;
		}
		y++;
	}
}

/*
void	validation(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (game->map->matrix[y])
	{
		while (game->map->matrix[y][x])
		{
			// if (game->map->matrix[y][x] == '\n')
			// {
			// 	x++;
			// 	continue;
			// }
			if (game->map->matrix[y][x] != '1' \
			&& game->map->matrix[y][x] != '0' \
			&& game->map->matrix[y][x] != 'C' \
			&& game->map->matrix[y][x] != 'E' \
			&& game->map->matrix[y][x] != 'P')
			{
				ft_printf("1\n");
				game->map->is_map_valid = false;
				ft_printf("x: %d, y: %d\n", x, y);
				print_error("map has unknown object");
			}
			if (game->map->is_map_valid == false)
				print_error("map has unknown object");
			x++;
		}
		x = 0;
		y++;
	}
}

void validation(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (game->map->matrix[y])  // Check that each row exists
    {
        x = 0;
        while (game->map->matrix[y][x])  // Check that each character in the row exists
        {
            // Print debug information to track progress
            ft_printf("Checking character at x: %d, y: %d: %c\n", x, y, game->map->matrix[y][x]);

            // Skip newline characters if found
            if (game->map->matrix[y][x] == '\n')
            {
                x++;
                continue;
            }

            // Check for invalid map characters
            if (game->map->matrix[y][x] != '1' &&
                game->map->matrix[y][x] != '0' &&
                game->map->matrix[y][x] != 'C' &&
                game->map->matrix[y][x] != 'E' &&
                game->map->matrix[y][x] != 'P')
            {
                ft_printf("1\n");  // Debug print to track progress
                game->map->is_map_valid = false;
                ft_printf("Invalid character found at x: %d, y: %d: %c\n", x, y, game->map->matrix[y][x]);
                print_error("map has unknown object");
                return;  // Exit function on error to prevent further issues
            }

            x++;
        }

        y++;
    }
}
*/