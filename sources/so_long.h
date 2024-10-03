/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:12:59 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/03 08:58:49 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdbool.h>
# include "./libft/libft.h"
# include "../mlx_linux/mlx.h"

# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100
# define ESC 65307
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

typedef struct s_map
{
	char	**matrix;
	bool	is_map_valid;
	bool	is_map_exitable;
	int		pac_x;
	int		pac_y;
	int		pac_steps;
	int		coin_count;
	int		player_count;
	int		exit_count;
	int		matrix_len;
	int		matrix_row_len;
}	t_map;

typedef struct s_images
{
	void	*box;
	void	*center;
	void	*coin;
	void	*pac;
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
	char	*pac;
	char	*coin;
	char	*box;
	char	*exit_open;
}	t_tiles;

typedef struct s_game
{
	t_map		*map;
	t_tiles		*tiles;
	t_win		*window;
	t_images	*img;
}	t_game;


void	check_chars(t_map *map);
void	render_map(t_game *game);
void	init_tiles(t_game *game);
void	init_images(t_game *game);
void	is_exitable(t_game *game);
void	check_lines(t_game *game);
void	find_player(t_game *game);
void	check_borders(t_game *game);
void	destroy_images(t_game *game);
void	move_to(t_game *game, int x, int y);
void	validate_args(int ac, const char *av);
void	check_number_of_objects(t_game *game);
void	parse(const char *file, t_game *game);
void	init_map(t_game *game, const char *file);
void	init_win(t_game *game, const char *file);
void	parse_map(const char *file, t_game *game);
void	init(t_game *game, const char *file, int ac);
void	put_tile(t_game *game, int x, int y, char id);
void	validate(int ac, t_game *game, const char *av);
void	flood_fill_validate(char **clone_map, t_game *game);
void	flood_fill(t_game *game, char **clone_map, int x, int y);

char	**copy_map(char **map);

int		close_window(t_game *game);
int		count_lines(const char *file);
int		count_columns(const char *file);
int		key_hook(int keycode, t_game *game);
int		counter(t_game *game, char object_id);

#endif