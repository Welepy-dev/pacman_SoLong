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

int	main(int ac, char **av)
{
	t_map	map;
	t_tiles	tiles;
	t_win	window;
	t_images	img;
	int a, b;

	if (ac == 2)
	{
		init_map(&map, av[1]);
		init_tiles(&tiles);
		parse_map(av[1], &map);
		init_win(&window, av[1]);
		if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
			print_error("Invalid file extension", &map);
		render_map(&map, &tiles, &window, &img);
		img.box = mlx_xpm_file_to_image(window.mlx, tiles.box, &tiles.tile_size, &tiles.tile_size);
		//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		//mlx_xpm_to_image(window.mlx, tiles.box, &tiles.tile_size, &tiles.tile_size);
		//mlx_put_image_to_window(window.mlx, window.win, img.box, 0, 0);
		mlx_loop(window.mlx);
	}
	else
		print_error("Invalid number arguments", NULL);
	return (0);
}