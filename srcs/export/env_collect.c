/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_collect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:15:53 by knakto            #+#    #+#             */
/*   Updated: 2025/04/10 00:13:49 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

bool	set_last_null(char **key)
{
	char	*str;
	int		i;

	str = *key;
	i = 0;
	while (str[i + 1])
		i++;
	if (str[i] == '=')
	{
		str[i] = '\0';
		return (true);
	}
	return (false);
}

t_env	*env_new(char *key, char *value)
{
	t_env	*env;
	bool	status;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	status = 1;
	if (!value)
		status = set_last_null(&key);
	env->env = true;
	if (!status)
		env->env = false;
	env->key = key;
	env->value = value;
	env->next = NULL;
	return (env);
}

int	count_env(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		if (env->env)
			i++;
		env = env->next;
	}
	return (i);
}

void	update_env(t_env *in_env)
{
	char	**env;
	char	*temp;
	int		i;

	env = *get_env();
	if (env)
		free_split(env);
	i = count_env(in_env);
	env = malloc(sizeof(char *) * (i + 1));
	if (!env)
		return ;
	i = 0;
	while (in_env)
	{
		while (!in_env->env)
			in_env = in_env->next;
		temp = ft_strjoin(in_env->key, "=");
		if (in_env->value)
			temp = fjoin(temp, in_env->value);
		else
			temp = fjoin(temp, "");
		env[i++] = temp;
		in_env = in_env->next;
	}
	env[i] = NULL;
	*get_env() = env;
}

void	ft_clear_env(void)
{
}
