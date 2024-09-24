/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:08:01 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/20 16:02:42 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_so_long *so_long)
{
	int	x;
	int	y;
	static int i = 0;
	if (keycode == UP)
	{
		if (so_long->map->matrix[so_long->map->player_y - 1][so_long->map->player_x] != '1')
		{ 
			so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = '0';
			so_long->map->matrix[so_long->map->player_y - 1][so_long->map->player_x] = 'P';
		}
	}
	else if (keycode == DOWN)
	{
		if (so_long->map->matrix[so_long->map->player_y + 1][so_long->map->player_x] != '1')
		{
			so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = '0';
			so_long->map->matrix[so_long->map->player_y + 1][so_long->map->player_x] = 'P';
		}
	}
	else if (keycode == LEFT)
	{
		if (so_long->map->matrix[so_long->map->player_y][so_long->map->player_x - 1] != '1')
		{
			so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = '0';
			so_long->map->matrix[so_long->map->player_y][so_long->map->player_x - 1] = 'P';
		}
	}
	else if (keycode == RIGHT)
	{
		if (so_long->map->matrix[so_long->map->player_y][so_long->map->player_x + 1] != '1')
		{
			so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = '0';
			so_long->map->matrix[so_long->map->player_y][so_long->map->player_x + 1] = 'P';
		}
	}
	ft_printf("Number of steps: %d\n", i++);
	render_map(so_long->map, so_long->tiles, so_long->window, so_long->img);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_tiles	tiles;
	t_win	window;
	t_images	img;
	t_so_long	so_long;

	if (ac != 2)
		print_error("Invalid number arguments", NULL);
	init_map(&map, av[1]);
	init_tiles(&tiles);
	parse_map(av[1], &map);
	init_win(&window, av[1]);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
		print_error("Invalid file extension", &map);
	render_map(&map, &tiles, &window, &img);
	so_long.map = &map;
	so_long.tiles = &tiles;
	so_long.window = &window;
	so_long.img = &img;
	mlx_key_hook(window.win, key_hook, &so_long);
	mlx_loop(window.mlx);
	return (0);
}