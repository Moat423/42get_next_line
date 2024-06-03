/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:30:22 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/30 11:15:21 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlcpy(char *dest, char *src, unsigned int len)
{
	unsigned int	i;

	i = 0;
	if (!dest)
		return (-1);
	if (len == 0)
	{
		dest[0] = '\0';
		return (ft_strlen(src));
	}
	while (src[i] && (i + 1) < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(dest));
}

char	*free_str(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

unsigned long	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
