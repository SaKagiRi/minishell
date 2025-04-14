/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:22:40 by knakto            #+#    #+#             */
/*   Updated: 2025/04/15 02:06:26 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <unistd.h>
# include "../../lib/KML/include/kml.h"
# include "../export/env.h"

typedef enum e_use_function
{
	CD,
	PWD,
	ECHO,
}	t_use_function;

typedef enum e_redirect_type
{
	READ_FILE,
	HERE_DOC,
	WRITE_FILE,
	APPEND_FILE,
}	t_redirect_type;

typedef struct s_redirect
{
	t_redirect_type		type;
	char				*value;
	struct s_redirect	*next;
}	t_redirect;

typedef struct s_process
{
	char				**cmd;
	t_redirect			*redirect;
	pid_t				pid;
	struct s_process	*next;
}	t_process;

int		builtin(t_process *proc);
int		len_arg(char **arg);
void	ft_chdir(char **arg);
void	ft_echo(char **arg);
void	ft_pwd(char **arg);
void	redirect(t_process *proc);

#endif
