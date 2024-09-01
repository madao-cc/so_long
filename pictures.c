/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pictures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:04:15 by madao-da          #+#    #+#             */
/*   Updated: 2024/09/01 17:17:35 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_images(t_game *game)
{
	int	pixel;

	pixel = PIXEL;
	game->image.background = mlx_xpm_file_to_image(game->mlx, \
	"./images/background.xpm", &pixel, &pixel);
	game->image.wall = mlx_xpm_file_to_image(game->mlx, \
	"./images/sea.xpm", &pixel, &pixel);
	game->image.collectable = mlx_xpm_file_to_image(game->mlx, \
	"./images/coin.xpm", &pixel, &pixel);
	game->image.exit = mlx_xpm_file_to_image(game->mlx, \
	"./images/exit-close.xpm", &pixel, &pixel);
	game->image.player_0 = mlx_xpm_file_to_image(game->mlx, \
	"./images/hero.xpm", &pixel, &pixel);
}

void	ft_open_exit(t_game *game, int pixel)
{
	mlx_destroy_image(game->mlx, game->image.exit);
	game->image.exit = mlx_xpm_file_to_image(game->mlx, \
	"./images/exit-open.xpm", &pixel, &pixel);
}

void	check_duplicates(t_game *game)
{
	if (game->image.player_0)
		mlx_destroy_image(game->mlx, game->image.player_0);
	if (game->image.background)
		mlx_destroy_image(game->mlx, game->image.background);
	if (game->image.collectable)
		mlx_destroy_image(game->mlx, game->image.collectable);
	if (game->image.wall)
		mlx_destroy_image(game->mlx, game->image.wall);
	if (game->image.exit)
		mlx_destroy_image(game->mlx, game->image.exit);
}

void	ft_draw_map(t_game *game, int x, int y)
{
	int	pixel;

	pixel = PIXEL;
	if (game->map.map[y][x] == '1')
	{
		if (game->image.wall)
			mlx_destroy_image(game->mlx, game->image.wall);
		game->image.wall = mlx_xpm_file_to_image(game->mlx, \
		"./images/sea.xpm", &pixel, &pixel);
		mlx_put_image_to_window(game->mlx, game->win, \
		game->image.wall, x * PIXEL, y * PIXEL);
	}
	else if (game->map.map[y][x] == '0')
		ft_draw_map_zero(game, x, y, pixel);
	else if (game->map.map[y][x] == 'P')
		ft_draw_map_player(game, x, y, pixel);
	else if (game->map.map[y][x] == 'C')
		ft_draw_map_collect(game, x, y, pixel);
	else if (game->map.map[y][x] == 'E')
		ft_draw_map_exit(game, x, y, pixel);
}

void	ft_clear_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->image.player_0);
	mlx_destroy_image(game->mlx, game->image.background);
	mlx_destroy_image(game->mlx, game->image.collectable);
	mlx_destroy_image(game->mlx, game->image.wall);
	mlx_destroy_image(game->mlx, game->image.exit);
}
