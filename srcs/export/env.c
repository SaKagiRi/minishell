/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:45:21 by knakto            #+#    #+#             */
/*   Updated: 2025/04/10 00:10:44 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env	**get_t_env(void)
{
	static t_env	*env = NULL;

	return (&env);
}

char	***get_env(void)
{
	static char	**env = NULL;

	return (&env);
}

void	init_clone_env(char **in_env)
{
	t_env	**env;
	t_env	*node;
	char	**temp;
	int	i;

	if (!in_env)
		return ;
	env = get_t_env();
	if (*env)
		return ;
	i = 0;
	temp = ft_split(in_env[i++], '=');
	*env = env_new(temp[0], temp[1]);
	node = *env;
	while (in_env[i])
	{
		temp = ft_split(in_env[i], '=');
		node->next = env_new(temp[0], temp[1]);
		node = node->next;
		i++;
	}
	update_env(*env);
}

void	ft_export()
{
}

void	ft_unset()
{
}

void	env_destroy(void)
{
}
