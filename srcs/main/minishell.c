/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 06:01:47 by knakto            #+#    #+#             */
/*   Updated: 2025/04/17 20:13:44 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

volatile sig_atomic_t	g_signal = 0;

//ตัวนี้จะลองเล่นๆก็ได้ เสร็จแค่ sigaction
int	main(int c, char **v, char **env)
{
	char	*user_input;
	// char	**split_line;
	

	init(c, v, env);
	while (1)
	{
		set_sig_bind_key();
		user_input = readline("minishell>");
		if (user_input != NULL)
			printf("line = %s\n", user_input);
		add_history(user_input);
		if (user_input == NULL)
		{
			user_input = ft_strdup("exit");
			printf("line = %s\n", user_input);
			break ;
		}
		// execution part
	}
	return (0);
}


//ตัวหลัก
// int	main(int c, char **v, char **env)
// {
// 	init_clone_env(env);
// 	print_env();
// }
