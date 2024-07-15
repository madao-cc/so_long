#include "so_long.h"

int	ft_render(t_game *game);
void	ft_check_winner(t_game *game);
int	ft_key_press(int key, t_game *game);
int	ft_press_x(t_game *game);
int	ft_count_numbers(int n);
char	*ft_itoa(int n);

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2) // Must be ./so_long map_file.ber
	{
		printf("ERROR! Must only have the program name and the map file,\n");
		return (1);
	}
	if (is_ber(argv[1]) == 0) // Check if the map_file is of type ".ber"
	{
		printf("ERROR! The map file is not of type .ber\n");
		return (2);
	}
	if (ft_check_errors(&game, argv[1]) == 0)
		return (3);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		printf("ERROR! Missing graphical interface.\n");
		free_map(&game);
		return (4);
	}
	game.win = mlx_new_window(game.mlx, game.map.width * PIXEL, game.map.height * PIXEL, "so_tiny");
	mlx_expose_hook(game.win, ft_render, &game);
	mlx_key_hook(game.win, ft_key_press, &game);
	mlx_hook(game.win, 17, 1L << 2, ft_press_x, &game);
	mlx_loop(game.mlx);
	perror("ERROR! Loop failed.\n");
	exit(EXIT_FAILURE);
}

int	ft_render(t_game *game)
{
	int	y;
	int	x;
	char	*show;

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
		printf("CONGRATULATIONS! YOU WIN!\n");
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
		printf("You quitted the game... NOOB! Learn how to play this easy game.\n");
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

int	ft_count_numbers(int n)
{
	int	count;

	count = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	if (n >= 0 && n <= 9)
		return (count);
	while (n / 10 > 0 || n % 10 == 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*res;
	long int		n_value;
	unsigned int	char_n;
	size_t			size;

	size = ft_count_numbers(n);
	res = malloc(size + 1);
	if (!res)
		return (0);
	res[size] = '\0';
	n_value = n;
	if (n_value < 0)
		n_value *= -1;
	while (size)
	{
		char_n = n_value;
		while (char_n > 9)
			char_n = char_n % 10;
		res[--size] = char_n + 48;
		n_value = n_value / 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
