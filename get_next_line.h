/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:28:08 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/30 11:09:11 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>

char			*get_next_line(int fd);
int				ft_memmove(char *dest, char *src);
char			*free_str(char *str);
unsigned int	ft_strlen(char *str);
long long       ft_realloc(char **str, unsigned int start, unsigned int len);
char			*make_line(char *buffer);
#endif //GET_NEXT_LINE_H
