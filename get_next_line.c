/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:45:47 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/27 12:56:59 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *src, unsigned int len)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
char	*make_rightside(char *buffer, unsigned int len)
{
	char	*rightside;

	{
		rightside = ft_substr(buffer, len);
		if (!rightside)
			return (NULL);
		buffer = ft_substr(rightside, BUFFER_SIZE * 2 + 1);
		if (!buffer)
			return (NULL);
		free(rightside);
	}
	return (rightside);
}
*/

char	*make_line(char *buffer, int fd)
{
	char			*line;
	unsigned int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		line = ft_substr(buffer, i + 1);
		if (!line)
			return (free_str(line));
		ft_memmove(buffer, buffer + i + 1);
		//while (i < len)
		//	buffer[i++] = '\0';
		return (line);
	}
	else
		get_next_line(fd);
	return (NULL);
}

//reallocates memory exponentially bigger than str, 
//return: where copied string terminated
unsigned int	ft_realloc(char *buffer, unsigned int start, unsigned int len)
{
	char			*save;
	unsigned int	bufferlen;
	unsigned int	init_len;

	bufferlen = ft_strlen(buffer);
	save = NULL;
	if (bufferlen < len)
		init_len = len * 2;
	else
		init_len = bufferlen * 2;
	save = ft_substr(buffer + start, init_len);
	if (!save)
		return (0);
	free(buffer);
	*buffer = *save;
	return (bufferlen);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer;
	unsigned int	len;

	buffer = NULL;
	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	if (buffer)
	{
		len = ft_realloc(buffer, 0, BUFFER_SIZE);
		if (!len || read(fd, buffer + len, BUFFER_SIZE) <= 0)
			return (NULL);
		//buffer[len + BUFFER_SIZE] = '\0';
	}
	else
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		len = read(fd, buffer, BUFFER_SIZE);
		//buffer[BUFFER_SIZE] = '\0';
		if (len <= 0)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
	}
	line = make_line(buffer, fd);
	return (line);
}
