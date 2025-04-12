/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 21:05:40 by knakto            #+#    #+#             */
/*   Updated: 2025/04/11 01:30:16 by knakto           ###   ########.fr       */
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
# include "../srcs/execution/exec.h"

typedef	struct	s_msh
{
	char	*prompt;
}	t_msh;

t_msh	*get_shell(void);

#endif
