#------------[MANDATORY]
NAME		= minishell
CC			= cc
HEADER		= -I ./include -I $(LIBFT_DIR)/include
#------------[FLAGS]
CFLAGS		= $(DEBUG_FLAGS) $(W_FLAGS)
DEBUG_FLAGS	= -g3
W_FLAGS		= -Wall -Wextra -Werror
#------------[LIBRARY]
LIBFT_DIR	= ./lib/KML
LIBFT_FILE	= $(LIBFT_DIR)/kml.a
#------------[OBJECT_AND_SOURCE]
SRC			= $(addprefix srcs/, $(FILE))
OBJ			= $(SRC:.c=.o)
#------------[ROOT_FILES]
FILE		= $(STAGE1) $(STAGE2)
#------------[SUBFILES]
#------------[STAGE_ONE]
STAGE1		= $(addprefix $(S1_PATH)/, $(S1_FILE))
S1_PATH		= stage1
S1_FILE		= main.c
	#------------[FUNCTION_PUTSTR]
	STAGE2		= $(addprefix $(S2_PATH)/, $(S2_FILE))
	S2_PATH		= $(S1_PATH)/putstr
	S2_FILE		= putstr.c
#------------[PROCESS]
all: lib $(NAME)
$(NAME): $(OBJ) | $(BUILD_DIR)
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FILE) $(HEADER) -o $@
		@printf "\033[38;5;46m\033[1m⟪ Complete ⟫\033[0m\n"
%.o: %.c Makefile
	@printf "\033[38;5;226;1m"
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)
lib:
	@make -C $(LIBFT_DIR)
clean:
	@rm -rf $(OBJ)
	@make clean -C $(LIBFT_DIR)
fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@printf "\033[1A\033[2K"
re: fclean all
.PHONY: all clean fclean re lib
