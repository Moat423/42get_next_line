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
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	ft_memmove(char *dest, char *src)
{
	int	i;

	i = 0;
	if (!dest)
		return (-1);
	while (src[i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*free_str(char *str)
{
	free(str);
	return (NULL);
}

char	*make_rightside(char *buffer)
{
	char	*rest;

	return (rest);
}

char	*make_line(char *buffer)
{
	char			*line;
	unsigned int	len;
	char			*rightside;
	unsigned int	i;

	len = ft_strlen(buffer);
	line = ft_substr(buffer, BUFFER_SIZE);
	if (!line)
		return (free_str(line));
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		ft_memmove(buffer, buffer + i + 1);
		line[i + 1] = '\0';
		free(buffer);
		if (!rightside)
			return (free_str(rightside));
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
	char			*line;
	static char		*buffer;
	char			*rightside;
	unsigned int	i;
	unsigned int	len;

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
