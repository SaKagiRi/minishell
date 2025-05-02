/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:29:04 by knakto            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/04/17 01:44:14 by knakto           ###   ########.fr       */
=======
/*   Updated: 2025/04/29 19:11:58 by knakto           ###   ########.fr       */
>>>>>>> origin
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	len_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

<<<<<<< HEAD
static int	process(t_process *proc, void (*f)(char **))
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
		f(proc->cmd);
		exit(EXIT_SUCCESS);
	}
	wait(&exit_status);
	return (exit_status);
}

=======
>>>>>>> origin
void	use_function(t_process *proc, t_use_function func)
{
	if (func == FT_CD)
		ft_chdir(proc->cmd);
	else if (func == FT_ECHO)
<<<<<<< HEAD
		process(proc, ft_echo);
	else if (func == FT_PWD)
		process(proc, ft_pwd);
	else if (func == FT_ENV)
		process(proc, ft_env);
=======
		ft_echo(proc->cmd);
	else if (func == FT_PWD)
		ft_pwd(proc->cmd);
	else if (func == FT_ENV)
		ft_env(proc->cmd);
>>>>>>> origin
	else if (func == FT_EXPORT)
		ft_export(proc->cmd);
	else if (func == FT_UNSET)
		ft_unset(proc->cmd);
	else if (func == FT_EXIT)
		ft_exit(proc);
}

int	builtin(t_process *proc)
{
<<<<<<< HEAD
	if (!ft_strncmp(proc->cmd[0], "cd", 3) \
		|| !ft_strncmp(proc->cmd[0], "cd ", 3))
		use_function(proc, FT_CD);
	else if (!ft_strncmp(proc->cmd[0], "echo", 5) \
		|| !ft_strncmp(proc->cmd[0], "echo ", 5))
		use_function(proc, FT_ECHO);
	else if (!ft_strncmp(proc->cmd[0], "pwd", 4) \
		|| !ft_strncmp(proc->cmd[0], "pwd ", 4))
		use_function(proc, FT_PWD);
	else if (!ft_strncmp(proc->cmd[0], "env", 4) \
		|| !ft_strncmp(proc->cmd[0], "env ", 4))
		use_function(proc, FT_ENV);
	else if (!ft_strncmp(proc->cmd[0], "export", 7) \
		|| !ft_strncmp(proc->cmd[0], "export ", 7))
		use_function(proc, FT_EXPORT);
	else if (!ft_strncmp(proc->cmd[0], "unset", 7) \
		|| !ft_strncmp(proc->cmd[0], "unset ", 7))
		use_function(proc, FT_UNSET);
	else if (!ft_strncmp(proc->cmd[0], "exit", 5) \
		|| !ft_strncmp(proc->cmd[0], "exit ", 5))
=======
	if (!ft_strncmp(proc->cmd[0], "cd", 3))
		use_function(proc, FT_CD);
	else if (!ft_strncmp(proc->cmd[0], "echo", 5))
		use_function(proc, FT_ECHO);
	else if (!ft_strncmp(proc->cmd[0], "pwd", 4))
		use_function(proc, FT_PWD);
	else if (!ft_strncmp(proc->cmd[0], "env", 4))
		use_function(proc, FT_ENV);
	else if (!ft_strncmp(proc->cmd[0], "export", 7))
		use_function(proc, FT_EXPORT);
	else if (!ft_strncmp(proc->cmd[0], "unset", 7))
		use_function(proc, FT_UNSET);
	else if (!ft_strncmp(proc->cmd[0], "exit", 5))
>>>>>>> origin
		use_function(proc, FT_EXIT);
	else
		return (0);
	return (1);
}
