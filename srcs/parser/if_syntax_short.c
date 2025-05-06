/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_syntax_short.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:01:34 by gyeepach          #+#    #+#             */
/*   Updated: 2025/05/05 22:28:30 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_pipe(char *start, int valid_single, int valid_double)
{
	return (*start == '|' && valid_single == 0 && valid_double == 0);
}

bool	is_here_or_append(char *start, int valid_single, int valid_double)
{
	return (
		((*start == '>' && *(start + 1) == '>')
			|| (*start == '<' && *(start + 1) == '<'))
		&& valid_single == 0 && valid_double == 0
	);
}

bool	is_redirect(char *start, int valid_single, int valid_double)
{
	return (
		(*start == '>' || *start == '<')
		&& valid_single == 0 && valid_double == 0
	);
}

bool	quote_not_close(int valid_single, int valid_double)
{
	return (valid_single == 1 || valid_double == 1);
}
