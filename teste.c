#include <stdio.h>
#include <stdlib.h>

char *ft_get_line(int fd);
{
	static char *str = NULL;

	char *buffer;
	char *result;

	int size;
	int i = 0;
	int ponteiro;
	
	char rows;
	ponteiro = 1; //! Nao sei se é 1 ou 0
	buffer = calloc(2, sizeof(char));
	if (!buffer)
		return (0);
	while (rows--)
	{
		ponteiro = read(fd, buffer, 1);
		if (ponteiro == -1) // limpar
		{
			free(buffer);
			if (str)
				free(str);
			str = NULL;
			return (1);
		}
		buffer[ponteiro] = '\0';
		str = ft_copy(str, buffer);
	}
	result = strdup(buffer);
	free(buffer);
	return (result);
}

char *ft_copy(char *str, char *buffer)
{
	char *result;

	int size = 0;
	int i = 0;

	if (!str)
	{
		str = calloc(1, sizeof(char));
	}
	size = strlen(str) + 1;
	result = calloc(size + 1, sizeof(char));
	while (str[i])
	{
		result[i] = str[i];
		i++;
	
	while (buffer[i])
	{
		result[i] = buffer[i];
		i++;
	}
	result[i] = '\0';
	free(str);
	return (result);
}