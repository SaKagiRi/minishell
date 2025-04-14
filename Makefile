#------------[MANDATORY]
NAME		= minishell
CC			= cc
HEADER		= -I ./include -I $(LIBFT_DIR)/include
#------------[FLAGS]
CFLAGS		= $(DEBUG_FLAGS) $(W_FLAGS)
DEBUG_FLAGS	= -g3 -lreadline
W_FLAGS		= #-Wall -Wextra -Werror
#------------[LIBRARY]
LIBFT_DIR	= ./lib/KML
LIBFT_FILE	= $(LIBFT_DIR)/kml.a
#------------[OBJECT_AND_SOURCE]
SRC			= $(addprefix srcs/, $(FILE))
OBJ			= $(SRC:.c=.o)
#------------[ROOT_FILES]
FILE		= $(MAIN) $(INIT) $(EXEC) $(ENV) $(BUILTIN)
#------------[SUBFILES] #------------[MAIN]
MAIN		= $(addprefix $(MAIN_PATH)/, $(MAIN_FILE))
MAIN_PATH		= main
MAIN_FILE		= minishell.c get_t.c
#------------[INIT_MINISHELL]
INIT		= $(addprefix $(INIT_PATH)/, $(INIT_FILE))
INIT_PATH		= init_minishell
INIT_FILE		= init.c
#------------[EXECUTION]
EXEC		= $(addprefix $(EXEC_PATH)/, $(EXEC_FILE))
EXEC_PATH		= execution
EXEC_FILE		= exec.c heredoc.c redirect.c clear.c get_t.c process.c
#------------[BUILTIN]
BUILTIN		= $(addprefix $(BUILTIN_PATH)/, $(BUILTIN_FILE))
BUILTIN_PATH		= builtin
BUILTIN_FILE		= ft_chdir.c builtin.c ft_echo.c
#------------[ENV]
ENV		= $(addprefix $(ENV_PATH)/, $(ENV_FILE))
ENV_PATH		= export
ENV_FILE		= env.c env_collect.c env_search.c export_sort.c print.c
#------------[PROCESS]
all: lib $(NAME)
$(NAME): $(OBJ) | $(BUILD_DIR)
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FILE) $(HEADER) -o $@
		@printf "\033[38;5;46m\033[1m⟪ Complete ⟫\033[0m\n"
%.o: %.c Makefile
	@printf "\033[38;5;226;1m"
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)
	@printf "\033[1A\033[2K"
lib:
	@make -C $(LIBFT_DIR)
clean:
	@rm -rf $(OBJ)
	@make clean -C $(LIBFT_DIR)
fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
re: fclean all
.PHONY: all clean fclean re lib
