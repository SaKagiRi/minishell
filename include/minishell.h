/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 21:05:40 by knakto            #+#    #+#             */
/*   Updated: 2025/04/30 20:42:47 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lib/KML/include/kml.h"
# include "../srcs/environment_variables/env.h"
# include "../srcs/execution/exec.h"
# include "../srcs/exit/exit.h"

extern volatile sig_atomic_t g_signal;

typedef enum e_word_type
{
	CMD, // 0
	SINGLE_QUOTE, // 1
	DOUBLE_QUOTE, // 2
	EXPAND, // 3
	OPERATOR, // 4
} t_word_type;

// static const char *g_word_type_names[] = {
//     "CMD",
//     "SINGLE_QUOTE",
//     "DOUBLE_QUOTE",
//     "EXPAND"
// };

typedef struct s_word_struct
{
	int	word_type;
	char *word;
	struct s_word_struct *next_word;
} t_word_struct;


void	string_extraction(char *line, t_word_struct **head);
int		word_len(char *start);
// void	append_node(t_word_struct **head, t_word_struct *new_node);
t_word_struct *create_new_word(char *word, t_word_type type);
int	word_len_inquote(char *start, t_word_type type);
t_word_type	sing_or_double(char *start);
int		ft_isquote(int c);
char 	*extract_input_word(char *start, int len, t_word_type type);
int		ft_isoperator(char *str);
void	append_node(t_word_struct **head, t_word_struct *new_node);
void	clear_word_list(t_word_struct *word_list);
int		get_word_len(char *start, t_word_type type);
t_word_type	get_word_type(char *start);
void	syntax_check(char *line);
// void 	clear_word_list(t_word_struct **word_list);
// int		word_len_in_quote(char *start);

#endif


// knakto check
// /minishell_beta_version> ls
// ===== Token List =====
// word : ls, type : 0
// ======================
// /minishell_beta_version> < 
// ===== Token List =====
// word : <, type : 4
// ======================
// /minishell_beta_version> < > << >> " ' |
// ===== Token List =====
// word : <, type : 4
// word : >, type : 4
// word : <<, type : 4
// word : >>, type : 4
// word :  ' |, type : 2
// ======================
// /minishell_beta_version> < aaaa > aaa
// ===== Token List =====
// word : <, type : 4
// word : aaaa, type : 0
// word : >, type : 4
// word : aaa, type : 0
// ======================
// /minishell_beta_version> < a > a << aa >> d |  "' 
// ===== Token List =====
// word : <, type : 4
// word : a, type : 0
// word : >, type : 4
// word : a, type : 0
// word : <<, type : 4
// word : aa, type : 0
// word : >>, type : 4
// word : d, type : 0
// word : |, type : 4
// word : ' , type : 2
// ======================

