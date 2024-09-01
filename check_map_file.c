/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:02:04 by madao-da          #+#    #+#             */
/*   Updated: 2024/09/01 17:03:03 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_map_rows(t_game *game, char *map_file)
{
	int		fd;
	int		rows;
	char	*line;

	rows = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFailed to open the map file\n");
		exit(EXIT_FAILURE);
	}
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
	game->map.height = rows;
	close(fd);
	return (1);
}

void	ft_get_map_width(t_game *game, char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] != '\n')
	{
		game->map.width++;
		i++;
	}
}

int	copy_map_content(t_game *game, char *map_file)
{
	int		fd;
	int		i;
	char	*tmp;
	char	*line;

	i = 0;
	fd = open(map_file, O_RDONLY);
	tmp = malloc(sizeof(char) * 1);
	if (!tmp)
		return (0);
	tmp[0] = '\0';
	while (i < game->map.height)
	{
		printf("%d\n", i);
		line = get_next_line(fd);
		tmp = ft_strjoin_gnl(tmp, line);
		free(line);
		i++;
	}
	ft_set_map(game, tmp);
	if (ft_check_requirements(game) == 0)
	{
		free(tmp);
		return (0);
	}
	ft_get_map_width(game, tmp);
	ft_write_map(game, tmp);
	free(tmp);
	close(fd);
	return (1);
}

int	ft_check_requirements(t_game *game)
{
	if (game->map.player != 1)
	{
		ft_printf("Error\nThere must be 1 player position.\n");
		return (0);
	}
	if (game->map.exit != 1)
	{
		ft_printf("Error\nThere must be 1 exit.\n");
		return (0);
	}
	if (game->map.collectable < 1)
	{
		ft_printf("Error\nThere must be at least 1 collectable.\n");
		return (0);
	}
	if (game->map.garbage > 0)
	{
		ft_printf("Error\nThere is an invalid character.\n");
		return (0);
	}
	return (1);
}
