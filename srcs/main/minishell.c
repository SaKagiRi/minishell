/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 06:01:47 by knakto            #+#    #+#             */
/*   Updated: 2025/04/17 02:11:00 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <fcntl.h>
#include <stdlib.h>
#include <strings.h>

t_redirect	*ft_new_re(char *eof, int type)
{
	t_redirect	*re;

	re = malloc(sizeof(t_redirect)); re->value = NULL;
	if (eof)
		re->value = ft_strdup(eof);
	re->next = NULL;
	re->type = type;
	return (re);
}

t_process	*ft_new_proc(char **cmd, t_redirect *re)
{
	t_process	*proc;

	proc = malloc(sizeof(t_process));
	// proc->redirect = ft_new_re("a", WRITE_FILE);
	proc->redirect = re;
	proc->cmd = cmd;
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

void	ft_add_proc(t_process **proc, t_process *new)
{
	t_process	*node;

	if (!*proc)
	{
		*proc = new;
		return ;
	}
	node = *proc;
	while (node->next)
		node = node->next;
	node->next = new;
}

void	get_cmd(char *line)
{
	t_process	*proc;
	int			i;
	char		**all_block_cmd;

	if (!ft_strchr(line, '|'))
	{
		proc = ft_new_proc(ft_split(line, ' '), NULL);
		*get_t_process() = proc;
		return ;
	}
	all_block_cmd = ft_split(line, '|');
	i = 0;
	while (all_block_cmd[i])
		ft_add_proc(get_t_process(), ft_new_proc(ft_split(all_block_cmd[i++], ' '), NULL));
}

int	check_cd(void)
{
	t_process	*proc;
	char		*nextpath;
	char		thispath[1024];

	proc = *get_t_process();
	if (!ft_strncmp(proc->cmd[0], "cd", 3) && proc->cmd[1] && !proc->cmd[2] && !proc->next)
	{
		getcwd(thispath, sizeof(thispath));
		nextpath = ft_strjoin(thispath, "/");
		nextpath = fjoin(nextpath, proc->cmd[1]);
		if (chdir(nextpath) != 0)
			pnf_fd(2, "bash: cd: %s: No such file or directory\n", proc->cmd[1]);
		free(nextpath);
		return (1);
	}
	return (0);
}

void	get_line(void)
{
	char	*line;
	char	get_path[1024];
	char	*path;

	while (is_exit(0))
	{
		if (!getcwd(get_path, sizeof(get_path)))
			return ;
		path = ft_strjoin(ft_strrchr(get_path, '/'), "> ");
		line = readline(path);
		if (!line)
			return ;
		get_cmd(line);
		process();
		clear_t_process();
		free(path);
	}
}

// NOTE: 
// -sort export, export unset in other case
// -error case
// -exit code
// -memory leak
// NOTE: day 15/4 5:44 Updated
// -finish ft_echo, ft_env, ft_export, ft_pwd, ft_unset and add redirect to it
// -finish all of env, it can read add change and delete
// -finish some leak and big error of memory
// -finish shell level in almost all case (dont have grep case and I dont do it lol)
// -check norm and push update this day
// NOTE: 
int	main(int c, char **v, char **envp)
{
	t_redirect	*re;
	t_process	*proc;
	int			fd;
	char		*line;
	char		*hah;

	// *env() = envp;
	init_env(envp);
	// print_env();
	// get_cmd("cd ..");
	get_line();
	// process();
	// clear_t_process();
}
