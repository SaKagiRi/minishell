/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:56:41 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 19:17:05 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line	*ft_gnl_lstnew(char *content)
{
	t_line	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->length = 0;
	new_node->next = NULL;
	return (new_node);
}

t_line	*ft_gnl_lstlast(t_line *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_gnl_lstadd_back(t_line **lst, t_line *new)
{
	t_line	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_gnl_lstlast(*lst);
	temp->next = new;
}

void	ft_gnl_lstclear(t_line **lst, void (*del)(void *))
{
	t_line	*temp_lst;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		temp_lst = *lst;
		*lst = (*lst)->next;
		free(temp_lst->content);
		free(temp_lst);
	}
	*lst = NULL;
}

void	*ft_gnl_calloc(size_t nmemb, size_t size)
{
	void			*arr;
	size_t			alloc_size;
	size_t			i;
	unsigned char	*cast_s;

	alloc_size = nmemb * size;
	if (!alloc_size || alloc_size / nmemb != size)
		return (NULL);
	arr = malloc(alloc_size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	cast_s = arr;
	while (i < alloc_size)
	{
		cast_s[i] = '\0';
		i++;
	}
	return (cast_s);
}
