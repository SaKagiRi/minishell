/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 06:31:39 by gyeepach          #+#    #+#             */
/*   Updated: 2025/04/19 20:18:13 by gyeepach         ###   ########.fr       */
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

void	append_node(t_word_struct **head, t_word_struct *new_node)
{
	t_word_struct	*current;

	if (!new_node)
		return ;

	if (!*head)
	{
		*head = new_node;
		new_node->next_word = NULL;
		return ;
	}

	current = *head;
	while (current->next_word)
		current = current->next_word;
	current->next_word = new_node;
	new_node->next_word = NULL;
}

t_word_struct *create_new_word(char *word, t_word_type type)
{
	t_word_struct	*new_node;

	new_node = malloc(sizeof(t_word_struct));
	if (!new_node)
		return (NULL);
	new_node->word = ft_strdup(word);
	if (!new_node->word)
	{
		free(new_node);
		return (NULL);
	}
	new_node->word_type = type;
	new_node->next_word = NULL;
	return (new_node);
}

void	string_extraction(char *line, t_word_struct **head)
{
	t_word_struct	*new_word;
	t_word_type		type;
	int				count_word_len;
	char			*word;
	char			*start;
	char			*end;

	*head = NULL;
	start = line;
	while (*start)
	{
		if (*start && ft_isspace(*start))
		{
			start++;
			continue ;
		}
		else if (*start && ft_isoperator(start))
		{
			type = OPERATOR;
			count_word_len = word_len(start);		
		}
		else if (*start && ft_isquote(*start))
		{
			type = sing_or_double(start);
			count_word_len = word_len_inquote(start, type);
		}
		else
		{
			type = CMD;
			count_word_len = word_len(start);
		}
		word = extract_input_word(start, count_word_len, type);
		new_word = create_new_word(word, type);
		append_node(head, new_word); // TO DO
		// printf("word : %s\n", new_word->word); // Debug before append_node
		// printf("word type : %d\n", new_word->word_type);
		free(word);
		end = start + count_word_len;
		start = end;
	}
}

// test เพื่อให้ เข้าใจ
// void	string_extraction(char *line)
// {
// 	t_word_struct	word_struct;
// 	int	i;

// 	i = 0;
// 	word_struct.word = malloc(strlen(line) + 1);
// 	while(line[i])
// 	{
// 		word_struct.word[i] = line[i];
// 		printf("char of input by user: %c\n", word_struct.word[i]);
// 		i++;
// 	}
// 	word_struct.word[i] = '\0';
// 	printf("string fof input by user %s\n", word_struct.word);
// }
