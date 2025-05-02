/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
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
}
