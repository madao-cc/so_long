#include "so_long.h"

void	ft_get_map_width(t_game *game, char *tmp);
void	ft_write_map(t_game *game, char *tmp);
void	free_map(t_game *game);
int	ft_init_positions(t_game *game, int y, int x);
void	ft_count_map_rows(t_game *game, char *map_file);

void	ft_count_map_rows(t_game *game, char *map_file)
{
	int	fd;
	int	rows;
	char	*line;

	rows = 0;
	fd = open(map_file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		rows++;
		free(line);
	}
	game->map.height = rows;
	close(fd);
}

void	ft_get_map_width(t_game *game, char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] != '\n')
	{
		game->map.width++;
		i++;
	}
}

void	ft_write_map(t_game *game, char *tmp) // Preciso de perceber muito melhor!!!
{
	int	start;
	int	i;

	i = 0;
	start = 0;
	game->map.map = malloc(sizeof(char *) * (game->map.height + 1));
	game->map.map[game->map.height] = NULL;
	if (!game->map.map)
		return ;
	while (i <  game->map.height)
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

int	ft_init_positions(t_game *game, int y, int x)
{
	while (game->map.map[y])
	{
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
			{
				game->p_pos.y = y;
				game->p_pos.x = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (game->p_pos.y == 0 || game->p_pos.x == 0)
	{
		printf("ERROR! Invalid player's position on the map.\n");
		return (0);
	}
	return (1);
}