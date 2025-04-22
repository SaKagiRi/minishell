/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 06:31:39 by gyeepach          #+#    #+#             */
/*   Updated: 2025/04/21 21:45:26 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


void clear_word_list(t_word_struct *word_list)
{
	t_word_struct *tmp;
	while (word_list)
	{
		tmp = word_list->next_word;
		free(word_list->word);
		free(word_list);
		word_list = tmp;
	}
}
t_word_type	get_word_type(char *start)
{
	if (ft_isoperator(start))
		return (OPERATOR);
	else if (ft_isquote(*start))
		return sing_or_double(start);
	else
		return (CMD);
}
int	get_word_len(char *start, t_word_type type)
{
	if (type == OPERATOR)
		return word_len(start);
	else if (type == SINGLE_QUOTE || type == DOUBLE_QUOTE)
		return word_len_inquote(start, type);
	else
		return word_len(start);
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

static void	process_token(char **start, t_word_struct **head)
{
	t_word_struct	*new_word;
	t_word_type		type;
	int				len;
	char			*word;

	type = get_word_type(*start);
	len = get_word_len(*start, type);
	word = extract_input_word(*start, len, type);
	new_word = create_new_word(word, type);
	append_node(head, new_word);
	free(word);
	*start += len;
}

void	string_extraction(char *line, t_word_struct **head)
{
	char			*start;

	start = line;
	while (*start)
	{
		if (*start && ft_isspace(*start))
			start++;
		else
			process_token(&start, head);
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
