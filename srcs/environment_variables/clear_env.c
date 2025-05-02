/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:srcs/builtin/ft_pwd.c
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 01:55:23 by knakto            #+#    #+#             */
/*   Updated: 2025/04/15 04:18:31 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_pwd(char **arg)
{
	char	thispath[1024];

	if (len_arg(arg) != 1)
	{
		pnf_fd(2, "bash: pwd: too many arguments\n");
		return ;
	}
	if (!getcwd(thispath, sizeof(thispath)))
		return ;
	pnf("%s\n", thispath);
========
/*   clear_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:23:17 by knakto            #+#    #+#             */
/*   Updated: 2025/04/29 19:27:37 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	clear_env(void)
{
	t_env	*envp;
	t_env	*temp;
	
	envp = *get_t_env();
	while (envp)
	{
		temp = envp;
		envp = envp->next;
		del(temp);
	}
	free_split(env()[0]);
>>>>>>>> origin:srcs/environment_variables/clear_env.c
}
