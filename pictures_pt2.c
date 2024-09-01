/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pictures_pt2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:16:23 by madao-da          #+#    #+#             */
/*   Updated: 2024/09/01 17:16:53 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map_zero(t_game *game, int x, int y, int pixel)
{
	if (game->image.background)
		mlx_destroy_image(game->mlx, game->image.background);
	game->image.background = mlx_xpm_file_to_image(game->mlx, \
	"./images/background.xpm", &pixel, &pixel);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.background, x * PIXEL, y * PIXEL);
}

void	ft_draw_map_player(t_game *game, int x, int y, int pixel)
{
	if (game->image.player_0)
		mlx_destroy_image(game->mlx, game->image.player_0);
	game->image.player_0 = mlx_xpm_file_to_image(game->mlx, \
	"./images/hero.xpm", &pixel, &pixel);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.player_0, x * PIXEL, y * PIXEL);
}

void	ft_draw_map_collect(t_game *game, int x, int y, int pixel)
{
	if (game->image.collectable)
		mlx_destroy_image(game->mlx, game->image.collectable);
	game->image.collectable = mlx_xpm_file_to_image(game->mlx, \
	"./images/coin.xpm", &pixel, &pixel);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.collectable, x * PIXEL, y * PIXEL);
}

void	ft_draw_map_exit(t_game *game, int x, int y, int pixel)
{
	if (game->image.exit)
		mlx_destroy_image(game->mlx, game->image.exit);
	game->image.exit = mlx_xpm_file_to_image(game->mlx, \
	"./images/exit-close.xpm", &pixel, &pixel);
	if (game->map.collectable == 0)
		ft_open_exit(game, pixel);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->image.exit, x * PIXEL, y * PIXEL);
}
