/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:04:22 by madao-da          #+#    #+#             */
/*   Updated: 2024/07/16 16:21:05 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_map_ber(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (len == 0)
		return (false);
	if (len <= 4) // ".ber"
		return (false);
	if (ft_strncmp(map_file + len - 4, ".ber", strlen(map_file)) != 0) //! Don't know if the size of compare should be this or just 5 (the 4 of .ber + 1 to compare the \0 that confirms the end of the .ber)
		return (false);
	return (true);
}

bool	file_has_content(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nMap file is empty.\n");
		return (false);
	}
	close(fd);
	return (true);
}

int	ft_check_errors(t_game *game, char *map_file)
{
	if (file_has_content(map_file) == false) // Check if there is anything inside the <map_file>.ber
		return (0);
	ft_init_map_struct(game); // Initialize all parameters in the map struct
	ft_count_map_rows(game, map_file); // Count the rows
	if (ft_set_map_layout(game, map_file) == 0) // Add all the rows. Count the rows. Check some conditions. Copy everything to our actual map
		return (0);
	if (map_is_rectangle(game) == 0) // Check if all the rows are the same
	{
		free_map(game);
		return (0);
	}
	if (ft_check_walls(game) == 0) // Check if the map is surrounded by walls
	{
		printf("Error\nThe walls around the map are not closed.\n");
		free_map(game);
		return (0);
	}
	if (ft_init_positions(game, 0, 0) == 0) // Find where P is in the map and initialize the players struct
	{
		free_map(game);
		return (0);
	}
	return (1);
}
