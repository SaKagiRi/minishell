/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:29:04 by knakto            #+#    #+#             */
/*   Updated: 2025/04/15 02:04:10 by knakto           ###   ########.fr       */
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

void	use_function(t_process *proc, t_use_function func)
{
	redirect(proc);
	if (func == CD)
		ft_chdir(proc->cmd);
	else if (func == ECHO)
		ft_echo(proc->cmd);
	else if (func == PWD)
		ft_pwd(proc->cmd);
}

int	builtin(t_process *proc)
{
	if (!ft_strncmp(proc->cmd[0], "cd", 3) \
		|| !ft_strncmp(proc->cmd[0], "cd ", 3))
		use_function(proc, CD);
	else if (!ft_strncmp(proc->cmd[0], "echo", 5) \
		|| !ft_strncmp(proc->cmd[0], "echo ", 5))
		use_function(proc, ECHO);
	else if (!ft_strncmp(proc->cmd[0], "pwd", 4) \
		|| !ft_strncmp(proc->cmd[0], "pwd ", 4))
		use_function(proc, PWD);
	else
		return (0);
	return (1);
}
