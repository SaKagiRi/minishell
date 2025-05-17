/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:11:02 by gyeepach          #+#    #+#             */
/*   Updated: 2025/05/12 21:58:21 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_word_type	sing_or_double(char *start)
{
	if (*start == '\'')
		return (SINGLE_QUOTE);
	else
		return (DOUBLE_QUOTE);
}

t_word_type	get_word_type(char *start)
{
	if (*start == '<' && *(start + 1) == '<')
		return (HEREDOC);
	if (*start == '>' && *(start + 1) == '>')
		return (APPEND);
	if (*start == '|' )
		return (PIPE);
	if (*start == '>')
		return (WRITE);
	if (*start == '<')
		return (READ);
	if (ft_isquote(*start))
		return (sing_or_double(start));
	return (CMD);
}

bool	syntax_check(char *line)
{
	int		valid_single;
	int		valid_double;
	char	*start;

	valid_double = 0;
	valid_single = 0;
	start = line;
	while (*start)
	{
		if (is_pipe(start, valid_single, valid_double))
			return (valid_pipe(start, line));
		if (is_here_or_append(start, valid_single, valid_double))
			return (valid_here_app(start, line));
		if (is_redirect(start, valid_single, valid_double))
			return (valid_rdir(start, line));
		if (is_single_qoute(start, valid_double))
			valid_single = !valid_single;
		if (is_double_qoute(start, valid_single))
			valid_double = !valid_double;
		start++;
	}
	if (quote_not_close(valid_single, valid_double))
		return (print_syntax_error());
	return (true);
}

int	word_len(char *start)
{
	char	*end;

	end = start;
	while (*end && !ft_isspace(*end)
		&& !ft_isoperator(end))
		end++;
	return (end - start);
}

int	word_len_inquote(char *start, t_word_type type)
{
	char	*end;
	int		word_len;

	word_len = 0;
	end = start + 1;
	if (type == SINGLE_QUOTE)
	{
		while (*end && *end != '\'')
			end++;
	}
	else if (type == DOUBLE_QUOTE)
	{
		while (*end && *end != '\"')
			end++;
	}
	word_len = end - start + 1;
	return (word_len);
}
