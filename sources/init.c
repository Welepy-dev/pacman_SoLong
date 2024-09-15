/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:13:31 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/15 20:18:41 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_map(t_map *map)
{
    map->matrix = NULL;
    map->width = 0;
    map->height = 0;
    map->player_x = 0;
    map->player_y = 0;
    map->is_map_valid = true;   //create a function that checks if the map is valid before initializing
    map->is_map_exitable = true; //create a function that checks if the map is exitable before initializing
}

void    init_tiles(t_tiles *tiles)
{
    tiles->inner_bottom_left_corner = "../tiles/corners/inner/inner_bottom_left_corner.xpm";
    tiles->inner_bottom_right_corner = "../tiles/corners/inner/inner_bottom_right_corner.xpm";
    tiles->inner_upper_left_corner = "../tiles/corners/inner/inner_upper_left_corner.xpm";
    tiles->inner_upper_right_corner = "../tiles/corners/inner/inner_upper_right_corner.xpm";
    tiles->outer_bottom_left_corner = "../tiles/corners/outer/outer_bottom_left_corner.xpm";
    tiles->outer_bottom_right_corner = "../tiles/corners/outer/outer_bottom_right_corner.xpm";
    tiles->outer_upper_left_corner = "../tiles/corners/outer/outer_upper_left_corner.xpm";
    tiles->outer_upper_right_corner = "../tiles/corners/outer/outer_upper_right_corner.xpm";
    tiles->vex_outer_bottom_left_corner = "../tiles/corners/vex/vex_outer_bottom_left_corner.xpm";
    tiles->vex_outer_bottom_right_corner = "../tiles/corners/vex/vex_outer_bottom_right_corner.xpm";
    tiles->vex_outer_upper_left_corner = "../tiles/corners/vex/vex_outer_upper_left_corner.xpm";
    tiles->vex_outer_upper_right_corner = "../tiles/corners/vex/vex_outer_upper_right_corner.xpm";
    tiles->inner_bottom_wall = "../tiles/walls/inner/inner_bottom_wall.xpm";
    tiles->inner_left_wall = "../tiles/walls/inner/inner_left_wall.xpm";
    tiles->inner_right_wall = "../tiles/walls/inner/inner_right_wall.xpm";
    tiles->inner_upper_wall = "../tiles/walls/inner/inner_upper_wall.xpm";
    tiles->outer_bottom_wall = "../tiles/walls/outer/outer_bottom_wall.xpm";
    tiles->outer_left_wall = "../tiles/walls/outer/outer_left_wall.xpm";
    tiles->outer_right_wall = "../tiles/walls/outer/outer_right_wall.xpm";
    tiles->outer_upper_wall = "../tiles/walls/outer/outer_upper_wall.xpm";
    tiles->center = "../tiles/center.xpm";
    tiles->enemy = "../tiles/enemy.xpm";
    tiles->pellet = "../tiles/pellet.xpm";
}