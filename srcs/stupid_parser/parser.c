/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:34:05 by knakto            #+#    #+#             */
/*   Updated: 2025/05/06 00:02:52 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand/expand.h"
#include "s_parser.h"

bool	s_parser(char **line)
{
	if (!syntax(*line))
	{
		pnf_fd(2, "bash: error: syntax error\n");
		return (0);
	}
	*get_t_block() = NULL;
	expand(line);
	return (1);
}
