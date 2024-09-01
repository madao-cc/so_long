/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file_pt2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:00:04 by madao-da          #+#    #+#             */
/*   Updated: 2024/09/01 17:01:30 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_rectangle(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		if ((ft_strlen(game->map.map[y]) != game->map.width))
		{
			ft_printf("Error\nMap is not a rectangle.\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	ft_check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.map[y])
	{
		if (y == 0 || y == (game->map.height - 1))
		{
			if (first_and_last_walls(game, y, x) == 0)
				return (0);
		}
		else
		{
			if (middle_walls(game, y) == 0)
				return (0);
		}
		x = 0;
		y++;
	}
	return (1);
}

int	first_and_last_walls(t_game *game, int y, int x)
{
	while (game->map.map[y][x])
	{
		if (game->map.map[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	middle_walls(t_game *game, int y)
{
	if (game->map.map[y][0] != '1')
		return (0);
	if (game->map.map[y][game->map.width - 1] != '1')
		return (0);
	y++;
	return (1);
}

int	ft_init_positions(t_game *game, int y, int x)
{
	while (game->map.map[y])
	{
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
			{
				game->p_pos.y = y;
				game->p_pos.x = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (game->p_pos.y == 0 || game->p_pos.x == 0)
	{
		ft_printf("Error\nInvalid player's position on the map.\n");
		return (0);
	}
	return (1);
}
