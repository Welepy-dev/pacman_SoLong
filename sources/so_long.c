/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:08:01 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/20 12:28:44 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	main(int ac, char **av)
{
	t_map	map;
	t_tiles	tiles;
	t_win	window;
	t_data	img;
	char	*relative_path = "../tiles/box.xpm";
	int a, b;

	if (ac == 2)
	{
		write (1, "a", 1);
		init_map(&map, av[1]);
		write (1, "b", 1);
		init_tiles(&tiles);
		write (1, "c", 1);
		parse_map(av[1], &map);
		write (1, "d", 1);
		init_win(&window, av[1]);
		write (1, "e", 1);
		if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
			print_error("Invalid file extension", &map);
		write (1, "f", 1);
		img.img = mlx_xpm_file_to_image(window.mlx, relative_path, &tiles.tile_size, &tiles.tile_size);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		//mlx_xpm_to_image(window.mlx, tiles.box, &tiles.tile_size, &tiles.tile_size);
		write (1, "g", 1);
		mlx_put_image_to_window(window.mlx, window.win, img.img, tiles.tile_size, tiles.tile_size);
		write (1, "h", 1);
		//render_map(&map, &tiles, &window);
		mlx_loop(window.mlx);
	}
	else
		print_error("Invalid number arguments", NULL);
	return (0);
}*/

#include "mlx.h"

int main()
{
    // Step 1: Initialize MLX and create a window
    void *mlx_ptr;
    void *win_ptr;
    mlx_ptr = mlx_init(); // Initialize MLX
    win_ptr = mlx_new_window(mlx_ptr, 100, 100, "Image Window"); // Create a window

    // Step 2: Load the image
    void *img_ptr;
    int img_width, img_height;
    img_width = 32;
    img_height = 32;
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./example.xpm", 100, 100); // Load the XPM image

    // Step 3: Display the image in the window
    if (img_ptr != NULL)
    {
        mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 2, 2); // Place image at (0, 0) in the window
    }

    // Step 4: Enter the event loop
    mlx_loop(mlx_ptr); // Keeps the window open and running

    return 0;
}



/*int	main(int ac, char av)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "../tiles/box.xpm";
	int		img_width = 32;
	int		img_height = 32;

	mlx = 
	mlx = mlx_init();

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
}*/