#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

# define PIXEL	48
# define ESC	65307

typedef struct s_map
{
	char	**map;
	int	width;
	int	height;
	int	player;
	int	collectable;
	int	exit;
}		t_map;

typedef struct s_image
{
	void	*player_0;
	void	*player_1;
	void	*collectable;
	void	*background;
	void	*wall;
	void	*exit;
}		t_image;

typedef struct s_player
{
	int	x;
	int	y;
}		t_player;

typedef	struct s_game
{
	void	*mlx;
	void	*win;
	t_player	p_pos;
	t_map		map;
	t_image		image;
	int		moves;
}		t_game;

// so_long.c
int	ft_render(t_game *game);
void	ft_check_winner(t_game *game);
int	ft_key_press(int key, t_game *game);
int	ft_press_x(t_game *game);
int	ft_count_numbers(int n);
char	*ft_itoa(int n);

// picture_handler.c
void	ft_create_images(t_game *game);
void	ft_open_exit(t_game *game, int pixel);
void	ft_draw_map(t_game *game, int x, int y);
void	ft_clear_images(t_game *game);

// moves_handler.c
void	ft_move(int key, t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_right(t_game *game);
void	ft_move_left(t_game *game);

// map_handler.c
void	ft_count_map_rows(t_game *game, char *map_file);
void	ft_get_map_width(t_game *game, char *tmp);
void	ft_write_map(t_game *game, char *tmp);
void	free_map(t_game *game);
int	ft_init_positions(t_game *game, int y, int x);

// map_checker.c
void	ft_init_map_layout(t_game *game);
int	ft_set_map_layout(t_game *game, char *map_file);
void	ft_set_map(t_game *game, char *tmp);
int	ft_check_requirements(t_game *game);
int	ft_check_rectangle(t_game *game);
int	ft_check_walls(t_game *game);
int	first_and_last_walls(t_game *game, int y, int x);
int	middle_walls(t_game *game, int y);

// errors_handler.c
int	is_ber(char *map_file);
int	file_has_content(char *map_file);
int	ft_check_errors(t_game *game, char *map_file);

# endif