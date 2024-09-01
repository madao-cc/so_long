/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:34:39 by madao-da          #+#    #+#             */
/*   Updated: 2024/09/01 16:23:52 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memalloc(size_t nitems, size_t size)
{
	char	*ptr;
	int		i;
	int		n;

	i = 0;
	n = nitems * size;
	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	while (n--)
		ptr[i++] = '\0';
	return (ptr);
}

int	ft_strlen(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int			i;
	char		*result;

	if (!str || !*str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	result = ft_memalloc((i + 1), sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = str[i];
	return (result);
}

char	*ft_broom(char *str)
{
	int			i;
	char		*result;
	int			j;
	int			length;

	if (!*str)
	{
		free(str);
		return (NULL);
	}
	length = ft_strlen(str);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	result = ft_memalloc(((length - i) + 1), sizeof(char));
	j = 0;
	while (str[i])
	{
		result[j++] = str[++i];
	}
	result[j] = '\0';
	free(str);
	return (result);
}
