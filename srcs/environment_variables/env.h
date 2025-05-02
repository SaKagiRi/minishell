/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 02:22:59 by knakto            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/04/16 01:16:54 by knakto           ###   ########.fr       */
=======
/*   Updated: 2025/05/01 23:38:47 by knakto           ###   ########.fr       */
>>>>>>> origin
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <unistd.h>
# include <stdlib.h>
# include "../../lib/KML/include/kml.h"
# include "../exit/exit.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

char	***env(void);
t_env	**get_t_env(void);
t_env	*new_env(char *key, char *value);
void	init_env(char **env);
void	print_env(void);
void	print_env_list(void);
void	set_env(void);
void	add_env(char *key, char *value);
int		search(char *key);
void	del_env(char *key);
void	set_value_env(char *key, char *value);
<<<<<<< HEAD
=======
void	del(t_env *d);
void	clear_env(void);
char	*get_value(char *key);
>>>>>>> origin

#endif
