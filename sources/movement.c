/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:54:12 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/25 20:41:08 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_so_long *so_long)
{
	if (keycode == UP)
	{
		if ((so_long->map->matrix[so_long->map->player_y - 1][so_long->map->player_x] != '1') \
				&& (so_long->player_x_pos % 32 == 0) && (so_long->player_y_pos % 32 == 0))
		{
			so_long->move_dir = 'U';
			so_long->is_moving = 1;
		}
	}
	else if (keycode == DOWN)
	{
		if ((so_long->map->matrix[so_long->map->player_y + 1][so_long->map->player_x] != '1') \
				&& (so_long->player_x_pos % 32 == 0) && (so_long->player_y_pos % 32 == 0))
		{
			so_long->move_dir = 'D';
			so_long->is_moving = 1;
		}
	}
	else if (keycode == LEFT)
	{
		if ((so_long->map->matrix[so_long->map->player_y][so_long->map->player_x - 1] != '1') \
				&& (so_long->player_x_pos % 32 == 0) && (so_long->player_y_pos % 32 == 0))
		{
			so_long->move_dir = 'L';
			so_long->is_moving = 1;
		}
	}
	else if (keycode == RIGHT)
	{
		if ((so_long->map->matrix[so_long->map->player_y][so_long->map->player_x + 1] != '1') \
				&& (so_long->player_x_pos % 32 == 0) && (so_long->player_y_pos % 32 == 0))
		{
			so_long->move_dir = 'R';
			so_long->is_moving = 1;
		}
	}
	return (0);
}

int	update_player(t_so_long *so_long)
{
	int	speed;

	speed = 2;
	if (so_long->is_moving)
	{
		if (so_long->move_dir == 'U')
		{
			if (so_long->map->matrix[so_long->map->player_y - 1][so_long->map->player_x] != '1')
			{
				so_long->player_y_pos -= speed;
				if (so_long->player_y_pos <= (so_long->map->player_y - 1) * 32)
				{
					so_long->player_y_pos = (so_long->map->player_y - 1) * 32;
					so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = '0';
					so_long->map->player_y -= 1;
					so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = 'P';
					so_long->is_moving = 1;
				}
			}
		}
		else if (so_long->move_dir == 'D')
		{
			if (so_long->map->matrix[so_long->map->player_y + 1][so_long->map->player_x] != '1')
			{
				so_long->player_y_pos += speed;
				if (so_long->player_y_pos >= (so_long->map->player_y + 1) * 32)
				{
					so_long->player_y_pos = (so_long->map->player_y + 1) * 32;
					so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = '0';
					so_long->map->player_y += 1;
					so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = 'P';
					so_long->is_moving = 1;
				}
			}
		}
		else if (so_long->move_dir == 'L')
		{
			if (so_long->map->matrix[so_long->map->player_y][so_long->map->player_x - 1] != '1')
			{
				so_long->player_x_pos -= speed;
				if (so_long->player_x_pos <= (so_long->map->player_x - 1) * 32)
				{
					so_long->player_x_pos = (so_long->map->player_x - 1) * 32;
					so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = '0';
					so_long->map->player_x -= 1;
					so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = 'P';
					so_long->is_moving = 1;
				}
			}
		}
		else if (so_long->move_dir == 'R')
		{
			if (so_long->map->matrix[so_long->map->player_y][so_long->map->player_x + 1] != '1')
			{
				so_long->player_x_pos += speed;
				if (so_long->player_x_pos >= (so_long->map->player_x + 1) * 32)
				{
					so_long->player_x_pos = (so_long->map->player_x + 1) * 32;
					so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = '0';
					so_long->map->player_x += 1;
					so_long->map->matrix[so_long->map->player_y][so_long->map->player_x] = 'P';
					so_long->is_moving = 1;
				}
			}
		}
		if (so_long->is_moving)
		{
			mlx_clear_window(so_long->window->mlx, so_long->window->win);
			render_map(so_long->map, so_long->tiles, so_long->window, so_long->img, so_long);
		}
	}
	return (0);
}
