/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_prompt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:57:32 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/12/16 14:52:33 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "get_next_line.h"

static void	suppress_cntl_chars(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	restore_cntl_chars(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

char	*ft_gnl(int fd, const char *prompt)
{
	char	*line;

	if (isatty(STDIN_FILENO))
		write(STDIN_FILENO, prompt, ft_strlen(prompt));
	suppress_cntl_chars();
	line = get_next_line(fd);
	restore_cntl_chars();
	return (line);
}
