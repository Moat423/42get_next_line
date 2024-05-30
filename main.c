/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:25:59 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/05/30 11:12:04 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

#define BUFFER_SIZE 10

int	main(void)
{
	int		test1fd;
	//int		invalidfd;
	char	*path1;
	//char	*path2;
	//char	*path3;
	int		i;
	char	*str;

	i = 1;
	path1 = "./testdocs/test1";
	//path2 = "./testdocs/test2";
	//path3 = "./testdocs/test3";
	test1fd = open(path1, O_RDONLY);
	//invalidfd = 45;
	while (i < 11)
	{
		str = get_next_line(test1fd);
		printf("line %d: %s", i++, str);
		free(str);
	}
	close(test1fd);
}
