/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:12:59 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/29 19:59:55 by marcsilv         ###   ########.fr       */
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
	char	move_dir;
	bool	is_map_valid;
	bool	is_map_exitable;
	int		pac_x;
	int		pac_y;
	int		pac_steps;
	int		coin_count;
	int		player_count;
	int		exit_count;
	int		current_frame;
	int		frame_count;
	int		frame_delay;
}	t_map;

typedef struct s_images
{
	void	*box;
	void	*center;
	void	*coin;
	void	*pac;
	void	*exit_open;
	void	*exit_closed;
	void	*pac_up[2];
	void	*pac_down[2];
	void	*pac_left[2];
	void	*pac_right[2];
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
	char	*pac_up_path[2];
	char	*pac_down_path[2];
	char	*pac_left_path[2];
	char	*pac_right_path[2];
}	t_tiles;

typedef struct s_game
{
	t_map		*map;
	t_tiles		*tiles;
	t_win		*window;
	t_images	*img;
}	t_game;

//void	validation(t_game *game);
void	render_map(t_game *game);
void	init_tiles(t_game *game);
void	init_images(t_game *game);
void	is_exitable(t_game *game);
void	check_lines(t_game *game);
//void	check_borders(t_game *game);
void	destroy_images(t_game *game);
void	check_rectangle(t_game *game);
void	validate_args(int ac, char *av);
void	init(t_game *game, const char *file);
void	check_number_of_objects(t_game *game);
void	parse(const char *file, t_game *game);
void	init_map(t_game *game, const char *file);
void	init_win(t_game *game, const char *file);
void	parse_map(const char *file, t_game *game);
void	validate(int ac, char **av, t_game *game);
//void	vertical_check(t_game *game, int y, int x);
//void	horizontal_check(t_game *game, int y, int x);
void	put_tile(t_game *game, int x, int y, char id);
void	move_to(t_game *game, int x, int y, char move_dir);

int		count_lines(const char *file);
int		count_columns(const char *file);
int		key_hook(int keycode, t_game *game);
int		counter(t_game *game, char object_id);

#endif