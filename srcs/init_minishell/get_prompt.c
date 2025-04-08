/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 06:26:09 by knakto            #+#    #+#             */
/*   Updated: 2025/04/06 17:52:36 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	get_uid(void)
{
	int		fd;
	int		uid;
	char	*line;

	fd = open("/proc/self/status", O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, "Uid:", 4))
		{
			uid = ft_atoi(line + 5);
			free(line);
			return (uid);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (-1);
}

int		len_till_in(char *s, char c, int d)
{
	int	i;
	int	dd;

	i = 0;
	dd = 0;
	if (!s || !c || d <= 0)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
		{
			dd++;
			if (dd == d)
				break ;
		}
		i++;
	}
	return (i);
}

char	*coppy(char *str)
{
	char	*res;
	int		len;
	int		i;

	len = len_till_in(str, ':', 1);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (len > i)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_user_name(void)
{
	char	*line;
	char	*uid;
	int		len;
	int		len_uid;
	int		fd;

	fd = open("/etc/passwd", O_RDONLY);
	if (fd < 0)
		return (ft_strdup(NULL));
	line = get_next_line(fd);
	uid = ft_itoa(get_uid());
	len_uid = ft_strlen(uid);
	while (line)
	{
		len = len_till_in(line, ':', 2);
		if (!ft_strncmp(line + len + 1, uid, len_uid))
		{
			free(uid);
			uid = coppy(line);
			free(line);
			return (uid);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(uid);
	return (NULL);
}
