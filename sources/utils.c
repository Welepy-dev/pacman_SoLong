/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:17:46 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/02 08:41:46 by marcsilv         ###   ########.fr       */
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

char	*copy_column_to_line(char **matrix, int column)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(sizeof(char) * ft_matrix_len(matrix) + 1);
	if (!line)
		print_error("memory allocation failure");
	while (matrix[i])
	{
		line[i] = matrix[i][column];
		i++;
	}
	line[i] = '\0';
	return (line);
}
