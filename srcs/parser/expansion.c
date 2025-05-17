/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:55:08 by gyeepach          #+#    #+#             */
/*   Updated: 2025/05/17 17:32:37 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	list_word_expansion(t_word_struct **head)
{
	t_word_struct	*current;
	char *expand_word;

	current = *head;
	while (current)
	{
		if (current->word_type == SINGLE_QUOTE)
		{
			current = current->next_word;
			continue ;
		}
		if (ft_strchr(current->word, '$'))
		{
			expand_word = find_env_value(current->word);
			if (expand_word)
			{
				free(current->word);
				current->word = expand_word;
			}
		}
		current = current->next_word;
	}
}

char *find_env_value(char *key)
{
	t_env	*env;
	char	*env_key;
	int		key_len;
	
	env = *get_t_env();
	env_key = key + 1;
	key_len = ft_strlen(env_key);
	if (!key || key[0] != '$')
		return (ft_strdup(key));
	while (env)
	{
		if(ft_strncmp(env->key, env_key, key_len) == 0)
		 	return(env->value);
		env = env->next;
	}
	return (NULL);
}
