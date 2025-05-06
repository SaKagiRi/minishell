/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_syntax_short2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:01:34 by gyeepach          #+#    #+#             */
/*   Updated: 2025/05/05 22:28:14 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_single_qoute(char *start, int valid_double)
{
	return (*start == '\'' && valid_double == 0);
}

bool	is_double_qoute(char *start, int valid_single)
{
	return (*start == '\"' && valid_single == 0);
}

bool	print_syntax_error(void)
{
	printf("syntax error\n");
	return (false);
}
