/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 06:03:30 by knakto            #+#    #+#             */
/*   Updated: 2025/04/06 17:52:54 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init(int c, char **v, char **env)
{
	t_msh	*m;

	m = get_shell();
	(void)c;
	(void)v;
	(void)env;
	m->prompt = "minishell>";
}
