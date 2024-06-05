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

int	main(void)
{
	int		testfd;
	//int		invalidfd;
	char	*path1;
	// char	*path2;
	//char	*path3;
	int		i;
	char	*str;
	//char	input[20];

	i = 1;
	path1 = "./testdocs/test1";
	//path2 = "./testdocs/test2";
	//path3 = "./testdocs/test3";
	testfd = open(path1, O_RDONLY);
	//invalidfd = 45;
	printf("fd: %d\n", testfd);
	//read(1, &input, 5);
	//printf("input: %s", input);
	while (i < 11)
	{
		str = get_next_line(testfd);
		printf("line %d: %s\n", i++, str);
		free(str);
	}
	close(testfd);
}
