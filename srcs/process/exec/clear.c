/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:srcs/builtin/ft_exit.c
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:41:26 by knakto            #+#    #+#             */
/*   Updated: 2025/04/17 03:12:52 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <stdio.h>

void	ft_exit(t_process *proc)
{
	// is_exit(1);
	printf("%d\n", *exnum() / 256);
========
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 00:48:11 by knakto            #+#    #+#             */
/*   Updated: 2025/04/27 01:35:34 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	clear_execution_failed(char **cmd, char **env)
{
	free_split(cmd);
>>>>>>>> origin:srcs/process/exec/clear.c
}
