/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:38:55 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/20 16:50:01 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_map *map, t_tiles *tiles, t_win *window, t_images *img)
{
	int	x;
	int	y;
	int height;
	int width;
	y = 0;
	img->box = mlx_xpm_file_to_image(window->mlx, tiles->box, &height, &width);
	img->center = mlx_xpm_file_to_image(window->mlx, tiles->center, &height, &width);
	img->coin = mlx_xpm_file_to_image(window->mlx, tiles->coin, &height, &width);
	img->pellet = mlx_xpm_file_to_image(window->mlx, tiles->pellet, &height, &width);
	img->outer_upper_wall = mlx_xpm_file_to_image(window->mlx, tiles->outer_upper_wall, &height, &width);
	
	ft_printf("height: %d\n", window->height / 32);
	ft_printf("width: %d\n", window->width / 32);
	while (y < window->height / 32)
	{
		ft_printf("1\n");
		x = 0;
		while (x < window->width / 32)
		{
			/*if (map->matrix[0][x] == '1')
			{
				mlx_put_image_to_window(window->mlx, window->win, img->outer_upper_wall, x * 32, y * 32);
				//ft_printf("2\n");
			}*/
			if (map->matrix[y][x] == '1')
				mlx_put_image_to_window(window->mlx, window->win, img->box, x * 32, y * 32);
			else if (map->matrix[y][x] == '0')
				mlx_put_image_to_window(window->mlx, window->win, img->center, x * 32, y * 32);
			else if (map->matrix[y][x] == 'C')
				mlx_put_image_to_window(window->mlx, window->win, img->coin, x * 32, y * 32);
			else if (map->matrix[y][x] == '9')
				mlx_put_image_to_window(window->mlx, window->win, img->pellet, x * 32, y * 32);
			x++;
		}
		y++;
	}
}