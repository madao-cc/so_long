/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:04:40 by madao-da          #+#    #+#             */
/*   Updated: 2024/07/16 16:17:22 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_map_rows(t_game *game, char *map_file)
{
	int	fd;
	int	rows;
	char	*line;

	rows = 0;
	fd = open(map_file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		rows++;
		free(line);
	}
	game->map.y = rows;
	close(fd);
}


void	ft_get_rows_length(t_game *game, char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n') // Go through the first row until it reaches the end (\n)
	{
		game->map.x++; // Store the length of the row. This will be usefull to check if the map is a rectagule
		i++;
	}
}

void	ft_write_map(t_game *game, char *map)
{
	int	start;
	int	i;

	i = 0;
	start = 0;
	game->map.map = malloc(sizeof(char *) * (game->map.y + 1)); // Allocate memmory as a string for all the rows of the map
	if (!game->map.map) // If the alocation failes
		return ;
	game->map.map[game->map.y] = NULL;
	while (i <  game->map.y) // Go through all the rows
	{
		game->map.map[i] = ft_substr(map, start, game->map.x); // Copy from the map_file to what will actually be our map
		i++;
		start += game->map.x + 1; //! Don't understand this... When the program works go though with gdb
	}
}

void	free_map(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.map[y]) // Go through each allocated row
	{
		free(game->map.map[y]); // Free the row
		y++;
	}
	free(game->map.map); // Free the actual map (pointer)
}
