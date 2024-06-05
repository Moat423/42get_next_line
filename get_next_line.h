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
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

char			*get_next_line(int fd);
char			*ft_strchr(char *str, int c);
int				ft_strlcpy(char *dest, char *src, unsigned int len);
char			*free_str(char *str);
unsigned long	ft_strlen(char *str);
char			*make_line(char *buffer, unsigned int *i);
char			*ft_substr(char *src, unsigned int len);
char			*ft_realloc(char *buffer, unsigned int start);
char			*read_into( int fd, char *buffer);
#endif //GET_NEXT_LINE_H
