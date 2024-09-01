/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:04:12 by madao-da          #+#    #+#             */
/*   Updated: 2024/09/01 17:08:10 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(int key, t_game *game)
{
	if (key == 'w')
		ft_move_up(game);
	else if (key == 'a')
		ft_move_left(game);
	else if (key == 's')
		ft_move_down(game);
	else if (key == 'd')
		ft_move_right(game);
}

void	ft_move_up(t_game *game)
{
	if (game->map.map[game->p_pos.y - 1][game->p_pos.x] == 'E')
		ft_check_winner(game);
	else if (game->map.map[game->p_pos.y - 1][game->p_pos.x] != '1')
	{
		game->moves++;
		ft_printf("Moves counter: %d\n", game->moves);
		if (game->map.map[game->p_pos.y - 1][game->p_pos.x] == 'C' \
		|| game->map.map[game->p_pos.y - 1][game->p_pos.x] == '0' )
		{
			if (game->map.map[game->p_pos.y - 1][game->p_pos.x] == 'C' )
				game->map.collectable--;
			game->map.map[game->p_pos.y - 1][game->p_pos.x] = 'P';
			game->map.map[game->p_pos.y][game->p_pos.x] = '0';
			game->p_pos.y--;
			ft_render(game);
		}
	}
}

void	ft_move_down(t_game *game)
{
	if (game->map.map[game->p_pos.y + 1][game->p_pos.x] == 'E')
		ft_check_winner(game);
	else if (game->map.map[game->p_pos.y + 1][game->p_pos.x] != '1')
	{
		game->moves++;
		ft_printf("Moves counter: %d\n", game->moves);
		if (game->map.map[game->p_pos.y + 1][game->p_pos.x] == 'C' \
		|| game->map.map[game->p_pos.y + 1][game->p_pos.x] == '0' )
		{
			if (game->map.map[game->p_pos.y + 1][game->p_pos.x] == 'C' )
				game->map.collectable--;
			game->map.map[game->p_pos.y + 1][game->p_pos.x] = 'P';
			game->map.map[game->p_pos.y][game->p_pos.x] = '0';
			game->p_pos.y++;
			ft_render(game);
		}
	}
}

void	ft_move_right(t_game *game)
{
	if (game->map.map[game->p_pos.y][game->p_pos.x + 1] == 'E')
		ft_check_winner(game);
	else if (game->map.map[game->p_pos.y][game->p_pos.x + 1] != '1')
	{
		game->moves++;
		ft_printf("Moves counter: %d\n", game->moves);
		if (game->map.map[game->p_pos.y][game->p_pos.x + 1] == 'C' \
		|| game->map.map[game->p_pos.y][game->p_pos.x + 1] == '0' )
		{
			if (game->map.map[game->p_pos.y][game->p_pos.x + 1] == 'C' )
				game->map.collectable--;
			game->map.map[game->p_pos.y][game->p_pos.x + 1] = 'P';
			game->map.map[game->p_pos.y][game->p_pos.x] = '0';
			game->p_pos.x++;
			ft_render(game);
		}
	}
}

void	ft_move_left(t_game *game)
{
	if (game->map.map[game->p_pos.y][game->p_pos.x - 1] == 'E')
		ft_check_winner(game);
	else if (game->map.map[game->p_pos.y][game->p_pos.x - 1] != '1')
	{
		game->moves++;
		ft_printf("Moves counter: %d\n", game->moves);
		if (game->map.map[game->p_pos.y][game->p_pos.x - 1] == 'C' \
		|| game->map.map[game->p_pos.y][game->p_pos.x - 1] == '0' )
		{
			if (game->map.map[game->p_pos.y][game->p_pos.x - 1] == 'C' )
				game->map.collectable--;
			game->map.map[game->p_pos.y][game->p_pos.x - 1] = 'P';
			game->map.map[game->p_pos.y][game->p_pos.x] = '0';
			game->p_pos.x--;
			ft_render(game);
		}
	}
}
