/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:47:30 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/02 15:03:29 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(const char *file)
{
	char	*str;
	int		fd;
	int		lines;

	lines = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("could not open file");
	str = get_next_line(fd);
	while (str)
	{
		lines++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (lines);
}

int	count_columns(const char *file)
{
	char	*str;
	int		fd;
	int		rows;
	int		i;

	rows = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("could not open file");
	str = get_next_line(fd);
	while (str)
	{
		i = 0;
		while (str[i])
			i++;
		if (i > rows)
			rows = i;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (rows);
}

void	parse_map(const char *file, t_game *game)
{
	char	*str;
	int		fd;
	int		row;
	int		lines;

	row = 0;
	lines = count_lines(file);
	if (lines == -1)
		print_error("could not parse file");
	game->map->matrix = malloc(sizeof(char *) * (lines + 1));
	if (!game->map->matrix)
		print_error("memory allocation failure");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("could not open file");
	str = get_next_line(fd);
	while (str)
	{
		game->map->matrix[row] = str;
		row++;
		str = get_next_line(fd);
	}
	game->map->matrix[row] = NULL;
	free(str);
	close(fd);
}

int	counter(t_game *game, char object_id)
{
	int	x;
	int	y;
	int	counter;

	y = 0;
	counter = 0;
	while (game->map->matrix[y])
	{
		x = 0;
		while (game->map->matrix[y][x])
		{
			if (game->map->matrix[y][x] == object_id)
				counter++;
			x++;
		}
		y++;
	}
	return (counter);
}

void	parse(const char *file, t_game *game)
{
	parse_map(file, game);
	game->map->matrix_len = ft_matrix_len(game->map->matrix);
	game->map->matrix_row_len = ft_strlen(game->map->matrix[0]);
	game->map->exit_count = counter(game, 'E');
	game->map->coin_count = counter(game, 'C');
	game->map->player_count = counter(game, 'P');
}
