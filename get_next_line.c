#include <stdlib.h>
#include <unistd.h>
// #include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char *ft_substr(char *src, unsigned int len) {
	char *dest;
	unsigned int i;

	i = 0;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	while (src[i] && i < len)
		dest[i] = src[i];
	dest[i] = '\0';
		return (dest);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	ft_strlcpy(char *dest, char *src, unsigned int len)
{
	int	i;

	i = 0;
	if (!dest)
		return (-1);
	while (src[i] && i < len)
		dest[i] = src[i];
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*make_line(char *buffer)
{
	char			*line;
	unsigned int	len;
	char			*rightside;
	unsigned int	i;

	i = ft_strlen(buffer);
	if (buffer[i] == '\n')
	{
		line = ft_substr(buffer, i + 1);
		rightside = ft_substr(buffer + i + 1, len - i);
		free(buffer);
		if (!line || !rightside)
		{
			free(line);
			free(rightside);
			return (NULL);
		}
	}
	else
	{
		rightside = ft_substr(buffer, len);
		if (!rightside)
			return (NULL);
	}
	if (rightside)
	{
		buffer = ft_substr(rightside, BUFFER_SIZE * 2 + 1);
		if (!buffer)
			return (NULL);
		free(rightside);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char *line;
	static char *buffer;
	char *rightside;
	unsigned int i;
	unsigned int len;

	if (BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	if (read(fd, buffer, BUFFER_SIZE) <= 0)
		return (NULL);
	return (line);
}
