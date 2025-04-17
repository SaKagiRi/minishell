/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:14:47 by knakto            #+#    #+#             */
/*   Updated: 2025/04/17 03:12:41 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

int	*exnum(void)
{
	static int	status = 0;

	return (&status);
}

static int	*ext(void)
{
	static int	ext = 0;

	return (&ext);
}

bool	is_exit(int num)
{
	if (num == 0)
		return (!*ext());
	*ext() = num;
	return (!*ext());
}

void	set_exit(int num)
{
	if (num == -1)
		exit(EXIT_FAILURE);
	*exnum() = num;
	exit(*exnum());
}
