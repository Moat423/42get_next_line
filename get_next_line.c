/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:03:24 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/06/11 14:03:26 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_into(int fd, char *buffer, long long *readlen)
{
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	*readlen = read(fd, buffer, BUFFER_SIZE);
	if (*readlen < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[*readlen] = '\0';
	return (buffer);
}

char	*append_line(char *line, char *buffer)
{
	unsigned int	line_len;
	unsigned int	buf_len;

	line_len = ft_strlen(line);
	buf_len = ft_strlen(buffer);
	if (!buffer)
		return (line);
	line = ft_realloc(line, line_len + buf_len);
	ft_strlcpy(line + line_len, buffer, buf_len);
	return (line);
}

char	*ft_realloc(char *str, unsigned int len)
{
	char			*save;

	save = NULL;
	if (str)
		save = ft_substr(str, len);
	free(str);
	if (!save)
		return (NULL);
	str = ft_calloc(len, 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, save, len);
	free(save);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer = NULL;
	long long	readlen;
	char		*start_tail;

	readlen = 1;
	line = NULL;
	start_tail = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024)
	{
		free(line);
		return (NULL);
	}
	while (!ft_strchr(line, '\n') && readlen > 0)
	{
		line = append_line(line, buffer);
		buffer = read_into(fd, buffer, &readlen);
		if (readlen <= 0)
			break ;
		line = append_line(line, buffer);
		start_tail = ft_strchr(buffer, '\n');
		buffer = ft_realloc(start_tail, BUFFER_SIZE);
	}
	return (line);
}
