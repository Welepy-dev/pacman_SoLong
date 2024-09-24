/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:12:59 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/20 16:41:08 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdbool.h>
# include "./libft/libft.h"
# include "../mlx_linux/mlx.h"

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

typedef struct s_map
{
	char	**matrix;
	bool	is_map_valid;
	bool	is_map_exitable;
	int		player_x;
	int		player_y;
}	t_map;



typedef struct s_images
{
	void	*box;
	void	*center;
	void	*ghost;
	void	*coin;
	void	*player;
	void	*exit;
	void	*outer_upper_wall;
	void	*outer_bottom_wall;
	void	*outer_left_wall;
	void	*outer_right_wall;
	void	*outer_upper_left_corner;
	void	*outer_upper_right_corner;
	void	*outer_bottom_left_corner;
	void	*outer_bottom_right_corner;
	void	*inner_
}	t_images;

typedef struct s_window
{
	char	*title;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		time_seconds;
	int		time_minutes;
}	t_win;

typedef struct s_tiles
{
	int		tile_size;
	char	*center;
	char	*exit;
	char	*player;
	char	*ghost;
	char	*coin;
	char	*box;
	char	*outer_upper_wall;
	char	*outer_bottom_wall;
	char	*outer_left_wall;
	char	*outer_right_wall;
	char	*outer_upper_left_corner;
	char	*outer_upper_right_corner;
	char	*outer_bottom_left_corner;
	char	*outer_bottom_right_corner;
}	t_tiles;

typedef struct so_long
{
	t_map		*map;
	t_tiles		*tiles;
	t_win		*window;
	t_images	*img;
}	t_so_long;


typedef struct player
{
	int		x;
	int		y;
	int		moves;
	int		pos_x;
	int		pos_y;
}	t_player;

typedef struct s_ghost
{
	int	pos_x;
	int	pos_y;
}	t_ghost;

typedef struct s_coin
{
	int	pos_x;
	int	pos_y;
}	t_coin;

typedef struct s_pellet
{
	int	pos_x;
	int	pos_y;
}	t_pellet;

void	init_tiles(t_tiles *tiles);
void	print_error(char *error, t_map *map);
void	init_map(t_map *map, const char *file);
void	render_map(t_map *map, t_tiles *tiles, t_win *window, t_images *img);
void	init_win(t_win *window, const char *file);

int		count_lines(const char *file);
int		count_columns(const char *file);
int		parse_map(const char *file, t_map *map);

#endif
