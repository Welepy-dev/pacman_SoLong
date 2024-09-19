/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:17:46 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/19 16:14:39 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *error, t_map *map)
{
	if (error)
		ft_printf("Error: %s\n", error);
	free (map->matrix);
	exit(0);
}