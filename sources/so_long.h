/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:12:59 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/27 20:21:50 by marcsilv         ###   ########.fr       */
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

void	render_map(t_game *game);
void	init_tiles(t_game *game);
void	init_images(t_game *game);
void	move_to(t_game *game, int x, int y);
void	print_error(char *error, t_game *game);
void	init_map(t_game *game, const char *file);
void	init_win(t_game *game, const char *file);
void	put_tile(t_game *game, int x, int y, char id);

int		count_lines(const char *file);
int		count_columns(const char *file);
int		key_hook(int keycode, t_game *game);
int		parse_map(const char *file, t_game *game);

#endif