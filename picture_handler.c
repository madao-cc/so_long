#include "so_long.h"

void	ft_create_images(t_game *game);
void	ft_open_exit(t_game *game, int pixel);
void	ft_draw_map(t_game *game, int x, int y);
void	ft_clear_images(t_game *game);

void	ft_create_images(t_game *game)
{
	int	pixel;

	pixel = PIXEL;
	game->image.background = mlx_xpm_file_to_image(game->mlx, "./Map_final/background.xpm", &pixel, &pixel);
	game->image.wall = mlx_xpm_file_to_image(game->mlx, "./Map_final/sea.xpm", &pixel, &pixel);
	game->image.collectable = mlx_xpm_file_to_image(game->mlx, "./Map_final/coin.xpm", &pixel, &pixel);
	game->image.exit = mlx_xpm_file_to_image(game->mlx, "./Map_final/exit-close.xpm", &pixel, &pixel);
	game->image.player_0 = mlx_xpm_file_to_image(game->mlx, "./Map_final/hero.xpm", &pixel, &pixel);
}

void	ft_open_exit(t_game *game, int pixel)
{
	mlx_destroy_image(game->mlx, game->image.exit);
	game->image.exit = mlx_xpm_file_to_image(game->mlx, "./Map_final/exit-open.xpm", &pixel, &pixel);
}

void	ft_draw_map(t_game *game, int x, int y)
{
	int	pixel;
	
	pixel = PIXEL;
	
	if (game->map.map[y][x] == '1')
	{
		game->image.wall = mlx_xpm_file_to_image(game->mlx, "./Map_final/sea.xpm", &pixel, &pixel);
		mlx_put_image_to_window(game->mlx, game->win, game->image.wall, x * PIXEL, y * PIXEL);
	}
	else if (game->map.map[y][x] == '0')
	{
		game->image.background = mlx_xpm_file_to_image(game->mlx, "./Map_final/background.xpm", &pixel, &pixel);
		mlx_put_image_to_window(game->mlx, game->win, game->image.background, x * PIXEL, y * PIXEL);
	}
	else if (game->map.map[y][x] == 'P')
	{
		game->image.player_0 = mlx_xpm_file_to_image(game->mlx, "./Map_final/hero.xpm", &pixel, &pixel);
		mlx_put_image_to_window(game->mlx, game->win, game->image.player_0, x * PIXEL, y * PIXEL);
	}
	else if (game->map.map[y][x] == 'C')
	{
		game->image.collectable = mlx_xpm_file_to_image(game->mlx, "./Map_final/coin.xpm", &pixel, &pixel);
		mlx_put_image_to_window(game->mlx, game->win, game->image.collectable, x * PIXEL, y * PIXEL);
	}
	else if (game->map.map[y][x] == 'E')
	{
		game->image.exit = mlx_xpm_file_to_image(game->mlx, "./Map_final/exit-close.xpm", &pixel, &pixel);
		if (game->map.collectable == 0)
			ft_open_exit(game, pixel);
		mlx_put_image_to_window(game->mlx, game->win, game->image.exit, x * PIXEL, y * PIXEL);
	}
}

void	ft_clear_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->image.player_0);
	mlx_destroy_image(game->mlx, game->image.background);
	mlx_destroy_image(game->mlx, game->image.collectable);
	mlx_destroy_image(game->mlx, game->image.wall);
	mlx_destroy_image(game->mlx, game->image.exit);
}