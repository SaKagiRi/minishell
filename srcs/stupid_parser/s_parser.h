/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_parser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:34:32 by knakto            #+#    #+#             */
/*   Updated: 2025/05/06 00:02:18 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PARSER_H
# define S_PARSER_H

# include <stdbool.h>
# include "syntax/syntax.h"
# include "expand/expand.h"

typedef enum e_pars_type
{
	PIPE,
	S_QUOTE,
	D_QUOTE,
	IN_S_QUOTE,
	IN_D_QUOTE,
	REDIRECT,
	START_EXPAND,
	EXPAND,
	WORD,
	CUT,
}	t_pars_type;

typedef struct s_block
{
	char			*content;
	t_pars_type		type;
	struct s_block	*next;
}	t_block;

t_block	**get_t_block(void);
bool	s_parser(char **line);

#endif
