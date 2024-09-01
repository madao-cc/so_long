/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:03:50 by madao-da          #+#    #+#             */
/*   Updated: 2024/09/01 17:05:07 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map_layout(t_game *game)
{
	game->map.map = 0;
	game->map.width = 0;
	game->map.player = 0;
	game->map.collectable = 0;
	game->map.exit = 0;
	game->map.garbage = 0;
	game->moves = 0;
	game->image.background = NULL;
	game->image.wall = NULL;
	game->image.collectable = NULL;
	game->image.exit = NULL;
	game->image.player_0 = NULL;
}

void	ft_set_map(t_game *game, char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == 'C')
			game->map.collectable++;
		if (tmp[i] == 'E')
			game->map.exit++;
		if (tmp[i] == 'P')
			game->map.player++;
		if (tmp[i] != '\n')
		{
			if (ft_check_garbage(tmp[i]) == 0)
				game->map.garbage++;
		}
		i++;
	}
}

int	ft_check_garbage(char c)
{
	if (c == 'C')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'P')
		return (1);
	if (c == 48)
		return (1);
	if (c == 49)
		return (1);
	return (0);
}

void	ft_write_map(t_game *game, char *tmp)
{
	int	start;
	int	i;

	i = 0;
	start = 0;
	game->map.map = malloc(sizeof(char *) * (game->map.height + 1));
	game->map.map[game->map.height] = NULL;
	if (!game->map.map)
		return ;
	while (i < game->map.height)
	{
		game->map.map[i] = ft_substr(tmp, start, game->map.width);
		i++;
		start += game->map.width + 1;
	}
}

void	free_map(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		free(game->map.map[y]);
		y++;
	}
	free(game->map.map);
}
