/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:04:19 by madao-da          #+#    #+#             */
/*   Updated: 2024/09/01 17:20:15 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	if (is_ber(argv[1]) == 0)
		return (1);
	if (ft_check_errors(&game, argv[1]) == 0)
		return (1);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		ft_printf("Error\nMissing graphical interface.\n");
		free_map(&game);
		return (4);
	}
	game.win = mlx_new_window(game.mlx, game.map.width * \
	PIXEL, game.map.height * PIXEL, "so_tiny");
	mlx_expose_hook(game.win, ft_render, &game);
	mlx_key_hook(game.win, ft_key_press, &game);
	mlx_hook(game.win, 17, 1L << 2, ft_press_x, &game);
	mlx_loop(game.mlx);
	perror("Error\nLoop failed.\n");
	exit(EXIT_FAILURE);
}

int	ft_render(t_game *game)
{
	char	*show;
	int		y;
	int		x;

	y = 0;
	x = 0;
	show = ft_itoa(game->moves);
	if (game->map.collectable == 0)
		ft_open_exit(game, PIXEL);
	while (game->map.map[y] != NULL)
	{
		while (game->map.map[y][x] != '\0')
		{
			ft_draw_map(game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_string_put(game->mlx, game->win, 3, 12, 0x000000, show);
	free(show);
	return (0);
}

void	ft_check_winner(t_game *game)
{
	if (game->map.collectable == 0)
	{
		ft_printf("CONGRATULATIONS! YOU WIN!\n");
		ft_clear_images(game);
		free_map(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_SUCCESS);
	}
}

int	ft_key_press(int key, t_game *game)
{
	if (key == ESC)
	{
		ft_clear_images(game);
		free_map(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		ft_printf("You quitted the game... \
		NOOB! Learn how to play.\n");
		exit(EXIT_FAILURE);
	}
	else
		ft_move(key, game);
	return (0);
}

int	ft_press_x(t_game *game)
{
	ft_key_press(ESC, game);
	return (0);
}
