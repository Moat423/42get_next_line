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
	while (src[i] && i++ < len)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
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
	while (src[i++])
		dest[i] = src[i];
	dest[i] = '\0';
	free(src);
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

char	*make_line(char *buffer, unsigned int len)
{
	char			*line;
	char			*rightside;
	unsigned int	i;

	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		line = ft_substr(buffer, i + 1);
		if (!line)
			return (free_str(line));
		ft_memmove(buffer, buffer + i + 1);
		while (i < len)
			buffer[i++] = '\0';
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
	unsigned int	len;

	if (BUFFER_SIZE <= 0)
		return (0);
	len = ft_strlen(buffer);
	if (!buffer)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (NULL);
		buffer[BUFFER_SIZE] = '\0';
	}
	else
	{
		buffer = ft_substr(buffer, len * 2);
		if (!buffer)
			return (NULL);
	}
	line = make_line(buffer, len);
	return (line);
}
