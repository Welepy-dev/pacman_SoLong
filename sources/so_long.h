/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:12:59 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/19 16:43:02 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdbool.h>
# include "./libft/libft.h"
# include "../mlx_linux/mlx.h"

typedef struct s_map
{
	char	**matrix;
	bool	is_map_valid;
	bool	is_map_exitable;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
}	t_map;

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
	char	*inner_bottom_left_corner;
	char	*inner_bottom_right_corner;
	char	*inner_upper_left_corner;
	char	*inner_upper_right_corner;
	char	*outer_bottom_left_corner;
	char	*outer_bottom_right_corner;
	char	*outer_upper_left_corner;
	char	*outer_upper_right_corner;
	char	*vex_outer_bottom_left_corner;
	char	*vex_outer_bottom_right_corner;
	char	*vex_outer_upper_left_corner;
	char	*vex_outer_upper_right_corner;
	char	*inner_bottom_wall;
	char	*inner_left_wall;
	char	*inner_right_wall;
	char	*inner_upper_wall;
	char	*outer_bottom_wall;
	char	*outer_left_wall;
	char	*outer_right_wall;
	char	*outer_upper_wall;
	char	*center;
	char	*exit;
	char	*player;
	char	*enemy;
	char	*coin;
	char	*pellet;
	char	*box;
}	t_tiles;

typedef struct player
{
	int		x;
	int		y;
	int		moves;
	int		pos_x;
	int		pos_y;
}	t_player;

typedef struct s_enemy
{
	int	pos_x;
	int	pos_y;
}	t_enemy;

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
void	init_win(t_win *window, const char *file, void *mlx, void *mlx_win);

int		count_lines(const char *file);
int		count_columns(const char *file);
int		parse_map(const char *file, t_map *map);
void	render_map(t_map *map, t_tiles *tiles, t_win *window);

#endif
