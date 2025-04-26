/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:11:02 by gyeepach          #+#    #+#             */
/*   Updated: 2025/04/26 23:56:37 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	valid_pipe(char *line)
{
	int	valid_pipe;

	valid_pipe = 0;
	// while ()
	//{
		
	//}
	if (valid_pipe == 1)
	{
		printf("syntax error\n");
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
			valid_pipe(*start);
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
