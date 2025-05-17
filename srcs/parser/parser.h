/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 22:01:45 by gyeepach          #+#    #+#             */
/*   Updated: 2025/05/12 21:43:28 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h> 
# include <readline/history.h>
// # include "../include/minishell.h"
// # include "../process/process.h"

extern volatile sig_atomic_t	g_signal;

typedef enum e_word_type
{
	READ,
	HEREDOC,
	WRITE,
	APPEND,
	CMD,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	EXPAND,
	PIPE,
	OPERATOR
}	t_word_type;

// static const char *g_word_type_names[] = {
//     "CMD",
//     "SINGLE_QUOTE",
//     "DOUBLE_QUOTE",
//     "EXPAND"
// };

typedef struct s_word_struct
{
	int						word_type;
	char					*word;
	struct s_word_struct	*next_word;
}	t_word_struct;

void			string_extraction(char *line, t_word_struct **head);
int				word_len(char *start);
// void	append_node(t_word_struct **head, t_word_struct *new_node);
t_word_struct	*create_new_word(char *word, t_word_type type);
int				word_len_inquote(char *start, t_word_type type);
t_word_type		sing_or_double(char *start);
int				ft_isquote(int c);
char			*extract_input_word(char *start, int len, t_word_type type);
int				ft_isoperator(char *str);
void			append_node(t_word_struct **head, t_word_struct *new_node);
void			clear_word_list(t_word_struct *word_list);
int				get_word_len(char *start, t_word_type type);
t_word_type		get_word_type(char *start);
bool			valid_pipe(char *start, char *line);
// void	syntax_check(char *line);
bool			syntax_check(char *line);
t_word_type		def_operator(char *str);
void			word_to_proc(t_word_struct **head, t_process **proc);
// void 	clear_word_list(t_word_struct **word_list);
// int		word_len_in_quote(char *start);
bool			valid_rdir(char *start, char *line);
bool			valid_here_app(char *start, char *line);
bool			detect_other_symbol(char *ptr);
bool			is_pipe(char *start, int valid_single, int valid_double);
bool			is_here_or_append(char *start,
					int valid_single, int valid_double);
bool			is_redirect(char *start, int valid_single, int valid_double);
bool			is_single_qoute(char *start, int valid_double);
bool			is_double_qoute(char *start, int valid_single);
bool			quote_not_close(int valid_single, int valid_double);
bool			print_syntax_error(void);
void			list_word_expansion(t_word_struct **head);
char 			*find_env_value(char *key);

#endif