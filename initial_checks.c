/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:03:56 by madao-da          #+#    #+#             */
/*   Updated: 2024/09/01 17:06:04 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_check_errors(t_game *game, char *map_file)
{
	if (ft_count_map_rows(game, map_file) == 0)
		return (0);
	if (check_min_height(game) == 0)
		return (0);
	ft_init_map_layout(game);
	if (copy_map_content(game, map_file) == 0)
		return (0);
	if (ft_check_rectangle(game) == 0)
	{
		free_map(game);
		return (0);
	}
	if (ft_check_walls(game) == 0)
	{
		ft_printf("Error\nThe walls around the map are not closed.\n");
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

int	check_min_height(t_game *game)
{
	if (game->map.height < 3)
	{
		ft_printf("Error\nPut at least 3 rows.\n");
		return (0);
	}
	return (1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	printf("|%s|\n", s1);
	printf("|%s|\n", s2);
	if (s1[0] == '\0')
		str = malloc(ft_strlen(s2) + 1);
	else
		str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
