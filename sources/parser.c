/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:47:30 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/15 21:37:10 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     count_lines(const char *filename)
{
        int             fd;
        char    *str;
        int lines;

        lines = 0;
        fd = open(filename, O_RDONLY);
        if (fd == -1)
        {
                ft_printf("Error opening file\n");
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

int     parse_map(const char* filename, t_map *map)
{
        char    *str;
        int             fd;
        int             row;
        int             line_count;

        row = 0;
        line_count = count_lines(filename);
        map->height = line_count;
        if (line_count == -1)
                return (-1);
        map->matrix = malloc(sizeof(char*) * line_count);
        if (!map->matrix)
        {
                ft_printf("Memory allocation error\n");
                return -1;
        }
        fd = open(filename, O_RDONLY);
        if (fd == -1)
        {
                ft_printf("Error opening file\n");
                free(map->matrix);
                return -1;
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
