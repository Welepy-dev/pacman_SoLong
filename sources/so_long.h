/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:12:59 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/25 20:35:30 by marcsilv         ###   ########.fr       */
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
	char	player_move_dir;
	bool	is_map_valid;
	bool	is_map_exitable;
	bool	is_player_moving;
	int		player_x;
	int		player_y;
	int		player_moves;
	int		player_pos_x;
	int		player_pos_y;
}	t_map;

typedef struct s_tiles
{
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
	char	*inner_horizontal_wall;
	char	*inner_vertical_wall;
	char	*inner_upper_left_corner;
	char	*inner_upper_right_corner;
	char	*inner_bottom_left_corner;
	char	*inner_bottom_right_corner;
	int		tile_size;
}	t_tiles;

typedef struct s_win
{
	char	*title;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		time_seconds;
	int		time_minutes;
}	t_win;

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
	void	*inner_horizontal_wall;
	void	*inner_vertical_wall;
	void	*inner_upper_left_corner;
	void	*inner_upper_right_corner;
	void	*inner_bottom_left_corner;
	void	*inner_bottom_right_corner;
}	t_images;

typedef struct s_so_long
{
	t_map		*map;
	t_tiles		*tiles;
	t_win		*window;
	t_images	*img;
    
	char move_dir;
	int	player_x_pos;
	int	player_y_pos;
	int	is_moving;
}	t_so_long;

void	find_player(t_map *map);
void	init_tiles(t_tiles *tiles);
void	print_error(char *error, t_map *map);
void	init_map(t_map *map, const char *file);
void	init_win(t_win *window, const char *file);
void	init_images(t_images *img, t_win *window, t_tiles *tiles);
void 	render_map(t_map *map, t_tiles *tiles, t_win *window, t_images *img, t_so_long *so_long);

int		count_lines(const char *file);
int		count_columns(const char *file);
int		update_player(t_so_long *so_long);
int		parse_map(const char *file, t_map *map);
int		key_hook(int keycode, t_so_long *so_long);

#endif
