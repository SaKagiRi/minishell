/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 08:32:02 by gyeepach          #+#    #+#             */
/*   Updated: 2025/04/18 22:42:42 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


char *extract_input_word(char *start, int len, t_word_type type)
{
	char *word;
	
	if (type == SINGLE_QUOTE || type == DOUBLE_QUOTE)
	{
		word = malloc(len - 1);
		if (!word)
			return (NULL);
		ft_memcpy(word, start + 1, len - 2);
		word[len - 2] = '\0';
	}
	else
	{
		word = malloc(len + 1);
		if (!word)
			return (NULL);
		ft_memcpy(word, start, len);
		word[len] = '\0';
	}
	return (word);
}

int	ft_isoperator(char *str)
{
	if (*str == '<' && *(str + 1) == '<')
		return (1);
	else if (*str == '<')
		return (1);
	else if (*str == '>' && *(str + 1) == '>')
		return (1);
	else if (*str == '>')
		return (1);
	else if (*str == '|')
		return (1);
	else
		return (0);
}
int	ft_isquote(int c)
{
	if (c == '\"' || c == '\'')
		return (1);
	else
		return (0);
}

int	word_len(char *start)
{
	char	*end;
	int		word_len;	

	word_len = 0;
	end = start;
	while (*end && !ft_isspace(*end))
		end++;
	return (word_len = end - start);
}
int	word_len_inquote(char *start, t_word_type type)
{
	char 	*end;
	int		word_len;

	word_len = 0;
	end = start + 1;
	if (type == SINGLE_MATCH)
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