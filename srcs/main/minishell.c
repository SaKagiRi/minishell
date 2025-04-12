/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 06:01:47 by knakto            #+#    #+#             */
/*   Updated: 2025/04/13 00:22:23 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <fcntl.h>
#include <stdlib.h>

t_redirect	*ft_new(char *eof, int type)
{
	t_redirect	*re;

	re = malloc(sizeof(t_redirect));
	re->value = NULL;
	if (eof)
		re->value = ft_strdup(eof);
	re->next = NULL;
	re->type = type;
	return (re);
}

void	while_ft(t_redirect *re)
{
	int	fd;

	while (re)
	{
		if (re->type == HERE_DOC)
		{
			ft_heredoc(re);
			// fd = open(re->value, O_RDONLY);
			// if (fd < 0)
			// {
			// 	pnf("Error: fd\n");
			// 	return 1;
			// }
			// line = get_next_line(fd);
			// while (line)
			// {
			// 	pnf("%s", line);
			// 	free(line);
			// 	line = get_next_line(fd);
			// }
			// unlink(re->value);
			// free(re->value);
			// free(re);
		}
		re = re->next;
	}
}

int	main(int c, char **v, char **envp)
{
	t_redirect	*re;
	t_process	*proc;
	int			fd;
	char		*line;

	// NOTE: test-cmd
	// char	**cmd;
	*env() = envp;
	// cmd = ft_split("ls -la -R", ' ');
	// exec(cmd, *env());
	
	// NOTE: test-heredoc
	re = ft_new("eof", HERE_DOC);
	re->next = ft_new("end", HERE_DOC);
	re->next->next = ft_new("out1", WRITE_FILE);
	re->next->next->next = ft_new("in", READ_FILE);
	proc = malloc(sizeof(t_process));
	proc->redirect = re;
	proc->cmd = ft_split("cat -e", ' ');
	proc->next = NULL;
	*get_t_process() = proc;
	while_ft(re);
	redirect(proc);
	exec(proc->cmd, *env());
	clear_t_process();
	// check_access_file(re);
}
