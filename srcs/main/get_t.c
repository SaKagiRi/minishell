/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 06:05:55 by knakto            #+#    #+#             */
/*   Updated: 2025/05/02 14:05:27 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../parser/parser.h"

// t_msh	*get_shell(void)
// {
// 	static	t_msh	shell;

// 	return (&shell);
// }

t_word_type	sing_or_double(char *start)
{
	if (*start == '\'')
		return (SINGLE_QUOTE);
	else
		return (DOUBLE_QUOTE);
}
