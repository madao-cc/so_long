/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:04:01 by madao-da          #+#    #+#             */
/*   Updated: 2024/09/01 17:06:56 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*result;
	int		size;

	if ((int)start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!s)
		return (NULL);
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int		i;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	if (!(n > 0))
		return (0);
	if (!str1 && !str2)
		return (0);
	while (i < (n - 1) && str1[i] && str1[i] == str2[i])
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

void	*ft_calloc(int nitems, int size)
{
	void	*result;

	result = malloc(nitems * size);
	if (!result)
		return (NULL);
	ft_bzero(result, (size * nitems));
	return (result);
}

void	ft_bzero(void *str, int n)
{
	unsigned char	*ptr;
	int				i;

	ptr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
