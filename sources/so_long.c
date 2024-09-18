/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:08:01 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/18 16:35:38 by marcsilv         ###   ########.fr       */
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
		t_window	window;
		int	x, y;
		int	img_width;
		int	img_height;
		char	*path;
		int i = 0;

		init_map(&map, argv[1]);
		init_tiles(&tiles);
		parse_map(argv[1], &map);
		init_window(&window, argv[1], mlx, mlx_win);
		if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		/*while (map.matrix[i])
		{
			ft_printf("%s", map.matrix[i]);
			i++;
		}*/
		
		/*x = 0;

		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, window_width, window_height, "so_long");
		img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
		while (x < 600)
		{
			mlx_put_image_to_window(mlx, mlx_win, img, x, 0);
			x++;
			usleep(10000);
		}
		mlx_loop(mlx);*/
	}
	else
		ft_printf("Error\n");
	return (0);
}