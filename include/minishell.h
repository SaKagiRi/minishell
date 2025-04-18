/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 21:05:40 by knakto            #+#    #+#             */
/*   Updated: 2025/04/08 21:41:48 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../lib/KML/include/kml.h"
# include "../srcs/init_minishell/init_minishell.h"
# include "../srcs/export/env.h"

typedef	struct	s_msh
{
	char	*prompt;
}	t_msh;

t_msh	*get_shell(void);

#endif
