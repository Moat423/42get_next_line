/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:45:47 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/30 11:39:49 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *src, unsigned int len)
{
	char			*dest;
	unsigned int	i;

	if (!src)
		return (NULL);
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

char	*make_line(char *buffer)
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
	return (NULL);
}

//reallocates memory exponentially bigger than str, 
//return: where copied string terminated
char	*ft_realloc(char *buffer, unsigned int start, unsigned int len)
{
	char			*save;
	unsigned int	bufferlen;
	unsigned int	init_len;

	if (!buffer)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		return (buffer);
	}		
	bufferlen = start; 
	if (bufferlen < len)
		init_len = len * 2;
	else
		init_len = bufferlen * 2;
	save = ft_substr(buffer + start, init_len - start);
	if (!save)
		return (NULL);
	free(buffer);
	buffer = malloc(init_len + 1);
	if (!buffer)
		return (NULL);
	ft_memmove(buffer, save);
	free(save);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer;
	int				readlen;
	unsigned long	len;

	line = NULL;
	readlen = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buffer = ft_realloc(buffer, ft_strlen(buffer), BUFFER_SIZE);
	len = ft_strlen(buffer);
	if (len < 0)
		return (NULL);
	printf("buffer: %s\n", buffer);
	printf("&buffer: %p\n", &buffer);
	printf("buffer pointer: %p\n", buffer);
	readlen = read(fd, buffer, BUFFER_SIZE);
	printf("buffer: %s\n", buffer);
	printf("readlen: %d\n", readlen);
	while ((readlen > 0))
	{
		buffer[len + readlen] = '\0';
		line = make_line(buffer);
		if (line)
			return (line);
	}
	return (free_str(buffer));
}
