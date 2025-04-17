/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:21:47 by knakto            #+#    #+#             */
/*   Updated: 2025/04/17 02:27:53 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	*get_command_path(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			break ;
		i++;
	}
	if (!env[i])
		return (NULL);
	return (env[i] + 5);
}

static bool	access_relative(char *cmd)
{
	if (!access(cmd, X_OK | F_OK))
		return (true);
	return (false);
}

static char	*access_absolute(char *cmd, char *path)
{
	char	**all_path;
	char	*temp;
	int		i;
	bool	status;

	if (ft_strrchr(cmd, '/') != NULL)
		cmd = ft_strrchr(cmd, '/');
	all_path = ft_split(path, ':');
	i = 0;
	status = false;
	while (all_path[i] && !status)
	{
		temp = ft_strjoin(all_path[i], "/");
		temp = fjoin(temp, cmd);
		if (!access(temp, X_OK | F_OK))
			status = true;
		i++;
		if (!status)
			free(temp);
	}
	free_split(all_path);
	if (status)
		return (temp);
	return (NULL);
}

static bool	chech_eccess(char ***cmd, char *path)
{
	char	*cmd_path;
	char	*temp;
	bool	relative_status;

	cmd_path = NULL;
	relative_status = access_relative(cmd[0][0]);
	if (!path && !relative_status)
		return (false);
	if (path)
		cmd_path = access_absolute(cmd[0][0], path);
	if (!cmd_path)
	{
		if (relative_status)
			return (true);
		return (false);
	}
	temp = **cmd;
	**cmd = cmd_path;
	free(temp);
	return (true);
}

void	exec(char **cmd, char **env)
{
	char	*path;
	bool	status;

	path = get_command_path(env);
	status = chech_eccess(&cmd, path);
	if (!status)
	{
		pnf_fd(2, "bash: %s: No such file or directory\n", cmd[0]);
		clear_t_process();
		set_exit(127);
	}
	execve(cmd[0], cmd, env);
	pnf_fd(2, "bash: %s: No such file or directory\n", cmd[0]);
	clear_t_process();
	exit(127);
}
