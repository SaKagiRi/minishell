/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 04:56:17 by knakto            #+#    #+#             */
/*   Updated: 2025/04/15 05:50:26 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	del(t_env *d)
{
	free(d->key);
	if (d->value)
		free(d->value);
	free(d);
}

void	del_env(char *key)
{
	t_env	*env;
	t_env	*temp;

	env = *get_t_env();
	if (!search(key))
		return ;
	temp = NULL;
	while (env)
	{
		if (!ft_strncmp(env->key, key, ft_strlen(key) + 1))
		{
			if (!temp)
			{
				*get_t_env() = env->next;
				del(env);
			}
			else
			{
				temp->next = env->next;
				del(env);
			}
		}
		temp = env;
		env = env->next;
	}
}
