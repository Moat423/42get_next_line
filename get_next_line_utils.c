/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:30:22 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/27 18:32:21 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
