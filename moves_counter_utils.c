/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:04:06 by madao-da          #+#    #+#             */
/*   Updated: 2024/09/01 17:07:18 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
