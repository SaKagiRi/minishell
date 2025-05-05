/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_t_pars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 03:12:18 by knakto            #+#    #+#             */
/*   Updated: 2025/05/05 05:19:23 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_parser.h"

void	del_block(t_block *b)
{
	free(b->content);
}

void	clear_t_block(void)
{
	t_block	*block;
	t_block	*temp;

	block = *get_t_block();
	while (block)
	{
		temp = block;
		block = block->next;
		del_block(temp);
		free(temp);
	}
	*get_t_block() = NULL;
}
