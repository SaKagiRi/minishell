/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
<<<<<<<< HEAD:srcs/exit/exit.h
=======
>>>>>>> origin
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:15:16 by knakto            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/04/17 02:17:21 by knakto           ###   ########.fr       */
=======
/*   Updated: 2025/04/26 21:42:23 by knakto           ###   ########.fr       */
>>>>>>> origin
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include <stdbool.h>
# include <stdlib.h>

<<<<<<< HEAD
int		*exnum(void);
void	set_exit(int num);
bool	is_exit(int num);
========
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 05:23:32 by knakto            #+#    #+#             */
/*   Updated: 2025/04/15 05:49:15 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_unset(char **arg)
{
	int		i;
>>>>>>>> origin:srcs/builtin/ft_unset.c

	if (len_arg(arg) == 1)
		return ;
	i = 1;
	while (arg[i])
		del_env(arg[i++]);
}
=======
int		*get_code(void);
void	set_exit(int num);
bool	is_exit(int num);

#endif
>>>>>>> origin
