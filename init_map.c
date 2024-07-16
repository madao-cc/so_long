/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:15:54 by madao-da          #+#    #+#             */
/*   Updated: 2024/07/16 16:20:20 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_set_map_layout(t_game *game, char *map_file)
{
	int	fd;
	int	i;
	char	*map;
	char	*line;

	i = 0;
	fd = open(map_file, O_RDONLY);
	map = calloc(1, 1);
	while (i < game->map.y) // While there are still rows to fill
	{
		line = get_next_line(fd); // Go get the line
		map = ft_strjoin_gnl(map, line); // And add it to the map
		i++;
		free(line);
	}
	ft_set_map(game, map); // When map has stored all that's inside the map.ber file. Update the necessaries structs
	if (ft_check_requirements(game) == 0)
	{
		free(map);
		return (0);
	}
	ft_get_rows_length(game, map); // Go get the length of each row
	ft_write_map(game, map); // Allocate memmory and copy the map_file to our actual map
	free(map);
	return (1);
}

void	ft_init_map_struct(t_game *game)
{
	game->map.map = 0;
	game->map.x = 0;
	game->map.y = 0;
	game->map.player = 0;
	game->map.collectable = 0;
	game->map.exit = 0;
	game->moves = 0;
}

void	ft_set_map(t_game *game, char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'C')
			game->map.collectable++;
		if (map[i] =='E')
			game->map.exit++;
		if (map[i] == 'P')
			game->map.player++;
		i++;
	}
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
	if (game->p_pos.y == 0 || game->p_pos.x == 0) //! I initialize y = 0 and x = 0. But in some cases the players position can be (0,0). NO! BECAUSE (0,0)=WALL
	{
		printf("Error\nInvalid player's position on the map.\n");
		return (0);
	}
	return (1);
}
