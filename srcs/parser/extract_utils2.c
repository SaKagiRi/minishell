/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:11:02 by gyeepach          #+#    #+#             */
/*   Updated: 2025/04/30 20:44:50 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	valid_pipe(char *start, char *line)
{
	char	*prev;
	char	*next;

	prev = start - 1;
	while (prev >= line && ft_isspace(*prev))
		prev--;
	if (prev < line || *prev == '|')
	{
		printf("syntax error near '|'\n");
		exit(1);
	}
	next = start + 1;
	while (*next && ft_isspace(*next))
		next++;
	if (*next == '\0' || *next == '|')
	{
		printf("syntax error near '|'\n");
		exit(1);
	}
}

void	syntax_check(char *line)
{
	int		valid_single;
	int		valid_double;
	char	*start;

	valid_double = 0;
	valid_single = 0;
	start = line;
	while (*start)
	{
		if (*start == '|'
			&& valid_double == 0
			&& valid_single == 0)
			valid_pipe(start, line);
		if (*start == '\''
			&& valid_double == 0)
			valid_single = !valid_single;
		else if (*start == '\"'
			&& valid_single == 0)
			valid_double = !valid_double;
		start++;
	}
	if (valid_double == 1
		|| valid_single == 1)
	{
		printf("syntax error\n");
		exit(1);
	}
}
