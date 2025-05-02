/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<<< HEAD:lib/KML/srcs/print/get_t.c
/*   Created: 2025/04/11 04:14:00 by knakto            #+#    #+#             */
/*   Updated: 2025/04/11 04:27:08 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	*get_fd(void)
{
	static int	fd = 1;

	return (&fd);
========
/*   Created: 2025/04/26 21:41:35 by knakto            #+#    #+#             */
/*   Updated: 2025/04/29 19:13:50 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

int	*get_code(void)
{
	static int	status = 0;

	return (&status);
>>>>>>>> origin:srcs/exit/get_t.c
}
