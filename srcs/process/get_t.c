/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:21:47 by knakto            #+#    #+#             */
<<<<<<<< HEAD:srcs/execution/get_t.c
/*   Updated: 2025/04/12 20:45:06 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
========
/*   Updated: 2025/04/29 04:24:15 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
>>>>>>>> origin:srcs/process/get_t.c

t_process	**get_t_process(void)
{
	static t_process	*process = NULL;

	return (&process);
}
