/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:08:01 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/15 21:25:23 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image_data;*/


int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		void	*mlx;
		void	*mlx_win;
		void	*img;
		t_map	map;
		t_tiles	tiles;
		int	x, y;
		int	window_width = 1280; // keep this for now
		int	window_height = 960; // keep this for now
		int	img_width;
		int	img_height;
		char	*path;

		init_map(&map);
		init_tiles(&tiles);
		parse_map(argv[1], &map);
		if (ft_strncmp(path + ft_strlen(path) - 4, ".xpm", 4) != 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		x = 0;

		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, window_width, window_height, "so_long");
		img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
		while (x < 600)
		{
			mlx_put_image_to_window(mlx, mlx_win, img, x, 0);
			x++;
			usleep(10000);
		}
		mlx_loop(mlx);
	}
	else
		ft_printf("Error\n");
	return (0);
}