/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:47:30 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/19 12:22:49 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(const char *file)
{
	char	*str;
	int		fd;
	int		lines;

	lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file1\n");
		return (-1);
	}
	str = get_next_line(fd);
	while (str)
	{
		lines++;
		free(str);
		str = get_next_line(fd);
	}
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
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file3\n");
		return (-1);
	}
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
	return (rows);
}

int	parse_map(const char *file, t_map *map)
{
	char	*str;
	int		fd;
	int		row;
	int		lines;
	int		columns;

	row = 0;
	lines = count_lines(filename);
	columns = count_columns(filename);
	if (lines == -1)
		return (-1);
	map->height = lines;
	map->matrix = malloc(sizeof(char *) * lines);
	map->matrix[lines] = NULL;
	if (!map->matrix)
	{
		ft_printf("Memory allocation error\n");
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file2\n");
		free(map->matrix);
		return (-1);
	}
	str = get_next_line(fd);
	while (str)
	{
		map->matrix[row] = str;
		row++;
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
