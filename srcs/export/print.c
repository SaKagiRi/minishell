/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:14:02 by knakto            #+#    #+#             */
/*   Updated: 2025/04/10 00:22:41 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_env(void)
{
	char	**env;

	env = *get_env();
	while (*env)
	{
		pnf("%s\n", *env);
		env++;
	}
}

void	print_export(void)
{
	t_env	*env;

	env = *get_t_env();
	while (env)
	{
		pnf("declare -x %s", env->key);
		if (!env->value)
		{
			pnf("\n");
			env = env->next;
			continue ;
		}
		pnf("=");
		if (*env->value)
			pnf("%s", env->value);
		pnf("\n");
		env = env->next;
	}
}
