/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:31:00 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/02 16:46:51 by marcsilv         ###   ########.fr       */
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
	char	**map;
	int		i;
	int		len;
	
	i = 0;
	while (game->map->matrix[i])
	{
		map[i] = ft_strdup(game->map->matrix[i]);
		i++;
	}
	i = 0;
	while (map[i])
	{
		map[i] = fix_next_line(map[i]);
		i++;
	}
	i = 1;
	len = ft_strlen(map[0]);
	ft_printf("len: %d\n", len);
	while (i < ft_matrix_len(game->map->matrix))
	{
		if (ft_strlen(map[i]) != len)
			game->map->is_map_valid = false;
		ft_printf("len: %d, newlen: %d\n", len, ft_strlen(map[i]));
		i++;
	}
	ft_matrix_free(map);
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