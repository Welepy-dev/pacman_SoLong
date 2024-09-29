/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:46:50 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/29 11:03:09 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_args(int ac, char *av)
{
	if (ac != 2)
		print_error("Invalid number of arguments");
	if (ft_strncmp(av + ft_strlen(av) - 4, ".ber", 4) != 0)
		print_error("Invalid file extension");
}

void	check_number_of_objects(t_game *game)
{
	if (game->map->coin_count == 0)
		game->map->is_map_valid = false;
	if (game->map->exit_count != 1)
		game->map->is_map_valid = false;
	if (game->map->player_count != 1)
		game->map->is_map_valid = false;
	if (game->map->is_map_valid == false)
		print_error("invalid map");
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
		print_error("map is not a rectangle");
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

void	validate(int ac, char **av, t_game *game)
{	
	//validation(game);
	check_number_of_objects(game);
	check_rectangle(game);
	//check_borders(game);
	if (game->map->is_map_valid == false)
		print_error("invalid map");
}


/*void	validation(t_game *game)
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

void	check_borders(t_game *game)
{
	vertical_check(game, 0, 0);
	ft_printf("7\n");
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
}*/