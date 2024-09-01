/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:04:28 by madao-da          #+#    #+#             */
/*   Updated: 2024/09/01 17:23:02 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line.h"

# define PIXEL	48
# define ESC	65307

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		player;
	int		collectable;
	int		exit;
	int		garbage;
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

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	p_pos;
	t_map		map;
	t_image		image;
	int			moves;
}		t_game;

/*	so_long.c	*/
void	ft_check_winner(t_game *game);
int		main(int argc, char **argv);
int		ft_render(t_game *game);
int		ft_key_press(int key, t_game *game);
int		ft_press_x(t_game *game);

/*	check_map_file_pt2.c	*/
char	*ft_strjoin_gnl(char *tmp, char *line);
int		ft_check_rectangle(t_game *game);
int		ft_check_walls(t_game *game);
int		first_and_last_walls(t_game *game, int y, int x);
int		middle_walls(t_game *game, int y);
int		ft_init_positions(t_game *game, int y, int x);
int		ft_strlen_gnl(char *str);

/*	check_map_file.c	*/
void	ft_get_map_width(t_game *game, char *tmp);
int		ft_count_map_rows(t_game *game, char *map_file);
int		copy_map_content(t_game *game, char *map_file);
int		ft_check_requirements(t_game *game);

/*	handle_map.c	*/
void	ft_init_map_layout(t_game *game);
void	ft_set_map(t_game *game, char *tmp);
void	ft_write_map(t_game *game, char *tmp);
void	free_map(t_game *game);
int		ft_check_garbage(char c);

/*	initial_checks.c	*/
int		is_ber(char *map_file);
int		ft_check_errors(t_game *game, char *map_file);
int		check_min_height(t_game *game);

/*	moves_counter_utils.c	*/
char	*ft_itoa(int n);
int		ft_count_numbers(int n);

/*	moves.c		*/
void	ft_move(int key, t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_right(t_game *game);
void	ft_move_left(t_game *game);

/*	pictures.c	*/
void	ft_create_images(t_game *game);
void	ft_open_exit(t_game *game, int pixel);
void	ft_draw_map(t_game *game, int x, int y);
void	ft_draw_map_pt2(t_game *game, int x, int y, int pixel);
void	ft_clear_images(t_game *game);
void	check_duplicates(t_game *game);

/*	libft_resources	*/
void	ft_bzero(void *str, int n);
void	*ft_calloc(int nitems, int size);
char	*ft_substr(char *s, int start, int len);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strlcpy(char *dest, char *src, int size);

/*	pictures_pt2	*/
void	ft_draw_map_zero(t_game *game, int x, int y, int pixel);
void	ft_draw_map_player(t_game *game, int x, int y, int pixel);
void	ft_draw_map_collect(t_game *game, int x, int y, int pixel);
void	ft_draw_map_exit(t_game *game, int x, int y, int pixel);

#endif