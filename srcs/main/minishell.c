/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 06:01:47 by knakto            #+#    #+#             */
/*   Updated: 2025/04/13 01:19:20 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <fcntl.h>
#include <stdlib.h>

t_redirect	*ft_new_re(char *eof, int type)
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

t_process	*ft_new_proc(char *cmd, t_redirect *re)
{
	t_process	*proc;

	proc = malloc(sizeof(t_process));
	proc->redirect = re;
	proc->cmd = ft_split(cmd, ' ');
	proc->next = NULL;
	return (proc);
}

// void	while_ft(t_redirect *re)
// {
// 	int	fd;
//
// 	while (re)
// 	{
// 		if (re->type == HERE_DOC)
// 		{
// 			ft_heredoc(re);
// 			// fd = open(re->value, O_RDONLY);
// 			// if (fd < 0)
// 			// {
// 			// 	pnf("Error: fd\n");
// 			// 	return 1;
// 			// }
// 			// line = get_next_line(fd);
// 			// while (line)
// 			// {
// 			// 	pnf("%s", line);
// 			// 	free(line);
// 			// 	line = get_next_line(fd);
// 			// }
// 			// unlink(re->value);
// 			// free(re->value);
// 			// free(re);
// 		}
// 		re = re->next;
// 	}
// }

void	set_env(void)
{
	char	**eenv;

	eenv = *env();
	eenv[0] = "hello";
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
	// re = ft_new_re("eof", HERE_DOC);
	// re->next = ft_new_re("end", HERE_DOC);
	// re->next->next = ft_new_re("out1", WRITE_FILE);
	re->next = ft_new_re("Makefile", READ_FILE);
	proc = ft_new_proc("cat", re);
	proc->next = ft_new_proc("cat", NULL);
	*get_t_process() = proc;
	process();
	// redirect(proc);
	// exec(proc->cmd, *env());
	// clear_t_process();
	// check_access_file(re);
}
