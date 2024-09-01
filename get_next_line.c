/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:58:57 by madao-da          #+#    #+#             */
/*   Updated: 2024/09/01 16:40:15 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save_in_temp(char *buffer, char *str)
{
	int			i;
	int			j;
	int			lenght;
	char		*result;

	if (!buffer)
		return (NULL);
	if (!str)
		str = ft_memalloc(1, sizeof(char));
	lenght = ft_strlen(buffer) + ft_strlen(str);
	result = ft_memalloc((lenght + 1), sizeof(char));
	j = 0;
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	while (buffer[j])
	{
		result[i++] = buffer[j++];
	}
	free(str);
	return (result);
}

int	ft_check_newline(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	*ft_clean(char **buffer, char **str)
{
	free(*str);
	free(*buffer);
	*str = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	int			count;
	char		*buffer;
	char		*final;

	count = 1;
	if (fd < 0 || 1 < 0)
		return (NULL);
	buffer = ft_memalloc((count + 1), sizeof(char));
	while (ft_check_newline(str) == 0 && count > 0)
	{
		count = read(fd, buffer, 1);
		if (count < 0)
			return (ft_clean(&buffer, &str));
		buffer[count] = '\0';
		str = ft_save_in_temp(buffer, str);
	}
	final = ft_strdup(str);
	str = ft_broom(str);
	free(buffer);
	return (final);
}
