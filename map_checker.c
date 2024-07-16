/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:04:33 by madao-da          #+#    #+#             */
/*   Updated: 2024/07/16 16:16:51 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_requirements(t_game *game)
{
	if (game->map.player != 1)
	{
		printf("Error\nThere must be 1 player in the map(P).\n");
		return (0);
	}
	if (game->map.exit != 1)
	{
		printf("Error\nThere must be 1 exit in the map(E).\n");
		return (0);
	}
	if (game->map.collectable < 1)
	{
		printf("Error\nThere must be at least 1 collectable(C).\n");
		return (0);
	}
	return (1);
}

bool	map_is_rectangle(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.map[y]) // Go through each row
	{
		if ((ft_strlen(game->map.map[y]) != (size_t)game->map.x)) // Check if the lenght of each row is the same
		{
			printf("Error\nMap is not a rectangule.\n");
			return (false);
		}
		y++;
	}
	return (true);
}

int	ft_check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(game->map.map[y])
	{
		if (y == 0 || y == (game->map.y - 1))
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
	while(game->map.map[y][x])
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
	if (game->map.map[y][game->map.x - 1] != '1') // game->map.x = "\n"
		return (0);
	y++;
	return (1);
}

