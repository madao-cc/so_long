#include "so_long.h"

void	ft_init_map_layout(t_game *game);
int	ft_set_map_layout(t_game *game, char *map_file);
void	ft_set_map(t_game *game, char *tmp);
int	ft_check_requirements(t_game *game);
int	ft_check_rectangle(t_game *game);
int	ft_check_walls(t_game *game);
int	first_and_last_walls(t_game *game, int y, int x);
int	middle_walls(t_game *game, int y);

void	ft_init_map_layout(t_game *game)
{
	game->map.map = 0;
	game->map.width = 0;
	game->map.height = 0;
	game->map.player = 0;
	game->map.collectable = 0;
	game->map.exit = 0;
	game->moves = 0;
}

int	ft_set_map_layout(t_game *game, char *map_file)
{
	int	fd;
	int	i;
	char	*tmp;
	char	*line;

	i = 0;
	fd = open(map_file, O_RDONLY);
	tmp = calloc(1, 1);
	while (i < game->map.height)
	{
		line = get_next_line(fd);
		tmp = ft_strjoin_gnl(tmp, line);
		i++;
		free(line);
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
	return (1);
}

void	ft_set_map(t_game *game, char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == 'C')
			game->map.collectable++;
		if (tmp[i] =='E')
			game->map.exit++;
		if (tmp[i] == 'P')
			game->map.player++;
		i++;
	}
}

int	ft_check_requirements(t_game *game)
{
	if (game->map.player < 1)
	{
		printf("ERROR! There must be 1 player\n");
		return (0);
	}
	if (game->map.exit != 1)
	{
		printf("ERROR! There must be 1 exit\n");
		return (0);
	}
	if (game->map.collectable < 1)
	{
		printf("ERROR! There must be at least 1 collectable\n");
		return (0);
	}
	return (1);
}

int	ft_check_rectangle(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		if ((ft_strlen(game->map.map[y]) != (size_t)game->map.width))
		{
			printf("ERROR! Map is not a rectangle.\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	ft_check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(game->map.map[y])
	{
		if (y == 0 || y == (game->map.height - 1))
		{
			if (first_and_last_walls(game, y, x) == 0)
				return (0);
		}
		else
		{
			if (middle_walls(game, y) == 0)
				return (0);
		}
		x = 0;
		y++;
	}
	return (1);
}

int	first_and_last_walls(t_game *game, int y, int x)
{
	while(game->map.map[y][x])
	{
		if (game->map.map[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	middle_walls(t_game *game, int y)
{

	if (game->map.map[y][0] != '1')
		return (0);
	if (game->map.map[y][game->map.width - 1] != '1')
		return (0);
	y++;
	return (1);
}

