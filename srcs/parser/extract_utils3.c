/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:34:35 by gyeepach          #+#    #+#             */
/*   Updated: 2025/05/05 21:50:57 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	detect_other_symbol(char *ptr)
{
	if (*ptr == '\0' || *ptr == '|' || *ptr == '<' || *ptr == '>')
		return (true);
	return (false);
}

bool	valid_pipe(char *start, char *line)
{
	char	*prev;
	char	*next;

	prev = start - 1;
	while (prev >= line && ft_isspace(*prev))
		prev--;
	if (detect_other_symbol(prev))
	{
		printf("syntax error near '|'\n");
		return (false);
	}
	next = start + 1;
	while (*next && ft_isspace(*next))
		next++;
	if (detect_other_symbol(next))
	{
		printf("syntax error near '|'\n");
		return (false);
	}
	return (true);
}

bool	valid_rdir(char *start, char *line)
{
	char	*next;

	next = start + 1;
	while (*next && ft_isspace(*next))
		next++;
	if (detect_other_symbol(next))
	{
		printf("syntax error \n");
		return (false);
	}
	return (true);
}

bool	valid_here_app(char *start, char *line)
{
	char	*next;

	next = start + 2;
	while (ft_isspace(*next))
		next++;
	if (detect_other_symbol(next))
	{
		printf("syntax error \n");
		return (false);
	}
	return (true);
}

void	clear_word_list(t_word_struct *word_list)
{
	t_word_struct	*tmp;

	while (word_list)
	{
		tmp = word_list->next_word;
		free(word_list->word);
		free(word_list);
		word_list = tmp;
	}
}
