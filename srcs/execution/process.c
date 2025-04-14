/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:37:28 by knakto            #+#    #+#             */
/*   Updated: 2025/04/15 04:25:47 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	run_process(t_process *proc)
{
	int	pipe_fd[2];

	if (pipe(pipe_fd) < 0)
	{
		pnf_fd(2, "bash: error: broken pipe\n");
		clear_t_process();
		exit(EXIT_FAILURE);
	}
	proc->pid = fork();
	if (proc->pid < 0)
	{
		pnf_fd(2, "bash: error: broken fork\n");
		clear_t_process();
		exit(EXIT_FAILURE);
	}
	if (proc->pid == 0)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		redirect(proc);
		exec(proc->cmd, *env());
	}
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
}

static int	process_out(t_process *proc)
{
	int	exit_status;

	proc->pid = fork();
	if (proc->pid < 0)
	{
		pnf_fd(2, "bash: error: broken fork\n");
		clear_t_process();
		exit(EXIT_FAILURE);
	}
	if (proc->pid == 0)
	{
		redirect(proc);
		exec(proc->cmd, *env());
	}
	wait(&exit_status);
	return (exit_status);
}

void	process(void)
{
	t_process	*proc;
	int			num_proc;
	int			exit_status;

	proc = *get_t_process();
	read_all_heredoc(proc);
	if (!proc->next && builtin(proc))
		return ;
	while (proc->next)
	{
		run_process(proc);
		if (proc->pid != 0)
			wait(&exit_status);
		proc = proc->next;
	}
	exit_status = process_out(proc);
}
