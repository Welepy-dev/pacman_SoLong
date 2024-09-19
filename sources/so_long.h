/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:12:59 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/19 12:04:01 by marcsilv         ###   ########.fr       */
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
        int		width;
        int		height;
        int		player_x;
        int		player_y;
        bool        is_map_valid;
        bool        is_map_exitable;
        //variables for mlx
        //variables for player collision
        //variables for time elapsed
}	t_map;

typedef struct s_window
{
        void	*mlx;
        void	*win;
        int		width;
        int		height;
        char	*title;

}	t_window;


typedef struct s_tiles
{
        char   *inner_bottom_left_corner;
        char   *inner_bottom_right_corner;
        char   *inner_upper_left_corner;
        char   *inner_upper_right_corner;
        char   *outer_bottom_left_corner;
        char   *outer_bottom_right_corner;
        char   *outer_upper_left_corner;
        char   *outer_upper_right_corner;
        char   *vex_outer_bottom_left_corner;
        char   *vex_outer_bottom_right_corner;
        char   *vex_outer_upper_left_corner;
        char   *vex_outer_upper_right_corner;
        char   *inner_bottom_wall;
        char   *inner_left_wall;
        char   *inner_right_wall;
        char   *inner_upper_wall;
        char   *outer_bottom_wall;
        char   *outer_left_wall;
        char   *outer_right_wall;
        char   *outer_upper_wall;
        char   *center;
        char   *exit;
        char   *player;
        char   *enemy;
        char   *coin;
        char   *pellet;
}        t_tiles;

typedef struct player
{
        int		x;
        int		y;
        int		moves;
        int             pos_x;
        int             pos_y;
        //variables for player sprite and animation
        //variables for player collision
}	t_player;

typedef struct s_enemy
{
        int		pos_x;
        int		pos_y;
        //variables for enemy sprite and animation
        //variables for enemy collision
}	t_enemy;

typedef struct s_coin
{
        int		pos_x;
        int		pos_y;
        //variables for coin sprite and animation
        //variables for coin collision
}	t_coin;

typedef struct s_pellet
{
        int		pos_x;
        int		pos_y;
        //variables for pellet sprite and animation
        //variables for pellet collision
}	t_pellet;

void    init_tiles(t_tiles *tiles);
void    init_map(t_map *map, const char *file);
void    init_window(t_window *window, const char *file, void *mlx, void *mlx_win);

int    count_lines(const char *file);
int    count_columns(const char *file);
int    parse_map(const char *file, t_map *map);

#endif