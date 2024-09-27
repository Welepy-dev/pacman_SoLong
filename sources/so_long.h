/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:12:59 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/27 14:56:55 by marcsilv         ###   ########.fr       */
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
	int		player_x; //maybe not needed
	int		player_y; //maybe not needed
}	t_map;

typedef struct s_images
{
	void	*box;
	void	*center;
	void	*coin;
	void	*player;
	void	*exit_open;
	void	*exit_closed;
}	t_images;

typedef struct s_window
{
	char	*title;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}	t_win;

typedef struct s_tiles
{
	int		tile_size;
	char	*center;
	char	*exit_closed;
	char	*player;
	char	*coin;
	char	*box;
	char	*exit_open;
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
}	t_player;		// maybe not needed


typedef struct s_coin
{
	int	pos_x;
	int	pos_y;
}	t_coin;			// maybe not needed

void	init_tiles(t_tiles *tiles);
void	print_error(char *error, t_map *map);
void	init_map(t_map *map, const char *file);
void	init_win(t_win *window, const char *file);
void	init_images(t_images *img, t_win *window, t_tiles *tiles);
void	render_map(t_map *map, t_tiles *tiles, t_win *window, t_images *img);

int		count_lines(const char *file);
int		count_columns(const char *file);
int		parse_map(const char *file, t_map *map);

#endif
