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

//BONUS main
int	main(void)
{
	int		testfd;
	int		testfd2;
	int		testfd3;
	int		invalidfd;
	char	*path1;
	char	*path2;
	char	*path3;
	int		i;
	char	*str;
	//char	input[20];
	i = 1;
	path1 = "./testdocs/multiple_nl.txt";
	path2 = "./testdocs/only_nl.txt";
	path3 = "./testdocs/test3";
	testfd = open(path1, O_RDONLY);
	testfd2 = open(path2, O_RDONLY);
	testfd3 = open(path3, O_RDONLY);
	invalidfd = 45;
	//read(1, &input, 5);
	//printf("input: %s", input)
	while (i < 6)
	{
		printf("fd: %d, test1\n", testfd);
		str = get_next_line(testfd);
		printf("line %d: %s\n", i, str);
		free(str);
		// printf("fd: %d, test2\n", testfd2);
		// str = get_next_line(testfd2);
		// printf("line %d: %s\n", i, str);
		// free(str);
		// printf("fd: %d,test3\n", testfd3);
		// str = get_next_line(testfd3);
		// printf("line %d: %s\n", i, str);
		// free(str);
		i++;
	}
	// printf("fd : NULL\n", NULL);
	// str = get_next_line(9);
	// printf("line 1: %s\n", str);
	close(testfd);
//	close(testfd2);
//	close(testfd3);
}

// non Bonus
// int	main(void)
// {
// 	int		testfd;
// 	int		invalidfd;
// 	char	*path1;
// 	char	*path2;
// 	//char	*path3;
// 	int		i;
// 	char	*str;
// 	//char	input[20];
//
// 	i = 1;
// 	path1 = "./testdocs/test1";
// 	path2 = "./testdocs/test2";
// 	//path3 = "./testdocs/test3";
// 	testfd = open(path1, O_RDONLY);
// 	invalidfd = 45;
// 	printf("fd: %d\n", testfd);
// 	//read(1, &input, 5);
// 	//printf("input: %s", input);
// 	while (i < 11)
// 	{
// 		str = get_next_line(testfd);
// 		printf("line %d: %s\n", i++, str);
// 		free(str);
// 		str = get_next_line(testfd);
// 		printf("line %d: %s\n", i++, str);
// 		free(str);
// 	}
// 	close(testfd);
// }
