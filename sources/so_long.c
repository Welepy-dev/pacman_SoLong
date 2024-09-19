/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:08:01 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/19 12:45:19 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		init_win(&window, argv[1], mlx, mlx_win);
		if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		{
			ft_printf("Error, wrong file extension\n");
			return (0);
		}
		mlx_loop(mlx);
	}
	else
		ft_printf("Error\n");
	return (0);
}
