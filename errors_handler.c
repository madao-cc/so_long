#include "so_long.h"

int	is_ber(char *map_file);
int	file_has_content(char *map_file);
int	ft_check_errors(t_game *game, char *map_file);

int	is_ber(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (len == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strncmp(map_file + len - 4, ".ber", strlen(map_file)) != 0)
		return (0);
	return (1);
}

int	file_has_content(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		printf("ERROR! Map file is empty\n");
		return (0);
	}
	close(fd);
	return (1);
}

int	ft_check_errors(t_game *game, char *map_file)
{
	if (file_has_content(map_file) == 0)
		return (0);
	ft_init_map_layout(game);
	ft_count_map_rows(game, map_file);
	if (ft_set_map_layout(game, map_file) == 0)
		return (0);
	if (ft_check_rectangle(game) == 0)
	{
		free_map(game);
		return (0);
	}
	if (ft_check_walls(game) == 0)
	{
		printf("ERROR! The walls around the map are not closed.\n");
		free_map(game);
		return (0);
	}
	if (ft_init_positions(game, 0, 0) == 0)
	{
		free_map(game);
		return (0);
	}
	return (1);
}
