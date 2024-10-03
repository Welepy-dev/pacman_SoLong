/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:17:46 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/03 12:09:23 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

char	**copy_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)malloc(sizeof(char *) * (ft_matrix_len(map) + 1));
	if (!copy)
		print_error("could not allocate memory");
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			print_error("could not allocate memory");
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(t_game *game, char **clone_map, int x, int y)
{
	if (x < 0 || y < 0 || y > game->map->matrix_len \
	|| x > game->map->matrix_row_len)
		return ;
	if (clone_map[y][x] == 'E')
		clone_map[y][x] = '1';
	if (clone_map[y][x] == 'C' || \
			clone_map[y][x] == 'E' || clone_map[y][x] == '0'
		|| clone_map[y][x] == 'P')
	{
		clone_map[y][x] = '.';
		flood_fill(game, clone_map, x + 1, y);
		flood_fill(game, clone_map, x - 1, y);
		flood_fill(game, clone_map, x, y + 1);
		flood_fill(game, clone_map, x, y - 1);
	}
}

void	flood_fill_validate(char **clone_map, t_game *game)
{
	int	x;

	x = 0;
	flood_fill(game, clone_map, game->map->pac_x, game->map->pac_y);
	while (clone_map[x] != NULL)
	{
		if (ft_strchr(clone_map[x], 'E') != NULL || \
			ft_strchr(clone_map[x], 'C') != NULL)
		{
			game->map->is_map_valid = false;
			close_window(game);
		}
		x++;
	}
	ft_matrix_free(clone_map);
}
