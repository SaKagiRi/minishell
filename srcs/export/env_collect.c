/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_collect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:15:53 by knakto            #+#    #+#             */
/*   Updated: 2025/04/09 04:52:05 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

bool	set_last_null(char **key)
{
	char	*str;

	str = *key;
	while (*(str + 1))
		str++;
	if (*str == '=')
	{
		*str = '\0';
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

void	print_env(void)
{
	t_env	*env;

	env = *get_t_env();
	while (env)
	{
		if (!env->value)
			pnf("%s=\n", env->key);
		else
			pnf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}
