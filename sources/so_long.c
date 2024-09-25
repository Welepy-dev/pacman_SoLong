/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:08:01 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/25 20:42:42 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	key_hook(int keycode, t_so_long *so_long)
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
			ft_printf("Number of steps: %d\n", so_long->map->player_moves++);
		}
	}
	else if (keycode == DOWN)
	{
		if (so_long->map->matrix[so_long->map->player_y + 1][so_long->map->player_x] != '1')
		{
			so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = '0';
			so_long->map->matrix[so_long->map->player_y + 1][so_long->map->player_x] = 'P';
			ft_printf("Number of steps: %d\n", so_long->map->player_moves++);
		}
	}
	else if (keycode == LEFT)
	{
		if (so_long->map->matrix[so_long->map->player_y][so_long->map->player_x - 1] != '1')
		{
			so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = '0';
			so_long->map->matrix[so_long->map->player_y][so_long->map->player_x - 1] = 'P';
			ft_printf("Number of steps: %d\n", so_long->map->player_moves++);
		}
	}
	else if (keycode == RIGHT)
	{
		if (so_long->map->matrix[so_long->map->player_y][so_long->map->player_x + 1] != '1')
		{
			so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = '0';
			so_long->map->matrix[so_long->map->player_y][so_long->map->player_x + 1] = 'P';
			ft_printf("Number of steps: %d\n", so_long->map->player_moves++);
		}
	}
	render_map(so_long->map, so_long->tiles, so_long->window, so_long->img);
	return (0);
}*/

// movement.c or appropriate file

/*int update_player(t_so_long *so_long)
{
    int speed = 2;  // Number of pixels to move each frame

    if (so_long->map->is_player_moving)
				{
        if (so_long->map->player_move_dir == 'U')
								{
            so_long->map->player_pos_y -= speed;
            if (so_long->map->player_pos_y <= (so_long->map->player_y - 1) * 32) {
                so_long->map->player_pos_y = (so_long->map->player_y - 1) * 32;
                so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = '0';
                so_long->map->player_y -= 1;
                so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = 'P';
                so_long->map->is_player_moving = 0;
            }
        }
        else if (so_long->map->player_move_dir == 'D') {
            so_long->map->player_pos_y += speed;
            if (so_long->map->player_pos_y >= (so_long->map->player_y + 1) * 32) {
                so_long->map->player_pos_y = (so_long->map->player_y + 1) * 32;
                so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = '0';
                so_long->map->player_y += 1;
                so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = 'P';
                so_long->map->is_player_moving = 0;
            }
        }
        else if (so_long->map->player_move_dir == 'L') {
            so_long->map->player_pos_x -= speed;
            if (so_long->map->player_pos_x <= (so_long->map->player_x - 1) * 32) {
                so_long->map->player_pos_x = (so_long->map->player_x - 1) * 32;
                so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = '0';
                so_long->map->player_x -= 1;
                so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = 'P';
                so_long->map->is_player_moving = 0;
            }
        }
        else if (so_long->map->player_move_dir == 'R') {
            so_long->map->player_pos_x += speed;
            if (so_long->map->player_pos_x >= (so_long->map->player_x + 1) * 32) {
                so_long->map->player_pos_x = (so_long->map->player_x + 1) * 32;
                so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = '0';
                so_long->map->player_x += 1;
                so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = 'P';
                so_long->map->is_player_moving = 0;
            }
        }

        // Redraw the map with the updated positions
        render_map(so_long);
    }

    return (0);
}


int key_hook(int keycode, t_so_long *so_long)
{

    if (keycode == UP && !so_long->map->is_player_moving)
    {
        if (so_long->map->matrix[so_long->map->player_y - 1][so_long->map->player_x] != '1')
	{
            so_long->map->player_move_dir = 'U';
            so_long->map->is_player_moving = true;
        }
    }
    else if (keycode == DOWN && !so_long->map->is_player_moving)
    {
        if (so_long->map->matrix[so_long->map->player_y + 1][so_long->map->player_x] != '1')
	{
            so_long->map->player_move_dir = 'D';
            so_long->map->is_player_moving = true;
        }
    }
    else if (keycode == LEFT && !so_long->map->is_player_moving)
    {
        if (so_long->map->matrix[so_long->map->player_y][so_long->map->player_x - 1] != '1')
	{
            so_long->map->player_move_dir = 'L';
            so_long->map->is_player_moving = true;
        }
    }
    else if (keycode == RIGHT && !so_long->map->is_player_moving)
    {
        if (so_long->map->matrix[so_long->map->player_y][so_long->map->player_x + 1] != '1')
	{
            so_long->map->player_move_dir = 'R';
            so_long->map->is_player_moving = true;
        }
    }
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
	render_map(&so_long);
	so_long.map = &map;
	so_long.tiles = &tiles;
	so_long.window = &window;
	so_long.img = &img;
	so_long.map->is_player_moving = false;
	so_long.map->player_pos_x = so_long.map->player_x * 32;
	so_long.map->player_pos_y = so_long.map->player_y * 32;
	so_long.map->player_move_dir = '\0';
	mlx_key_hook(window.win, key_hook, &so_long);
	mlx_loop_hook(window.mlx, update_player, &so_long);
	mlx_loop(window.mlx);
	return (0);
}*/

int	main(int ac, char **av)
{
	t_map		map;
	t_tiles		tiles;
	t_win		window;
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
	so_long.map = &map;
	so_long.tiles = &tiles;
	so_long.window = &window;
	so_long.img = &img;
	find_player(&map);
	so_long.player_x_pos = map.player_x * 32;
	so_long.player_y_pos = map.player_y * 32;
	so_long.move_dir = '\0';
	so_long.is_moving = 0;
	render_map(&map, &tiles, &window, &img, &so_long);
	mlx_key_hook(window.win, key_hook, &so_long);
	mlx_loop_hook(window.mlx, update_player, &so_long);
	mlx_loop(window.mlx);
	return (0);
}
