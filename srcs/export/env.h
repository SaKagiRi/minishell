/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:45:27 by knakto            #+#    #+#             */
/*   Updated: 2025/04/10 00:40:13 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../../lib/KML/include/kml.h"
# include <stdbool.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	bool			env;
	int				index;
	struct	s_env	*next;
}	t_env;

typedef	enum e_index_error
{
	NOT_INIT = 0,
	NOT_FOUND = -1,
	EMPTY_NODE = -2,
	EMPTY_VALUE = -3,
}	t_index_error;

typedef enum e_env_mode
{
	EXPORT,
	UNSET,
	PRINT,
}	t_env_mode;

t_env	**get_t_env(void); //debug
t_env	*env_new(char *key, char *value);
void	init_clone_env(char **in_env);
void	print_env(void);
void	print_export(void);
void	update_env(t_env *env);
char	***get_env(void);

#endif
