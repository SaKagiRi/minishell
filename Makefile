#! /bin/bash
#-------------[mandatory]
NAME		= minishell
OUTPUT_DIR	= ./
CC			= cc
DIR			= mkdir -p
RM			= rm -rf
CFLAGS		= -g3 -Wall -Wextra -Werror
HEADER		= -I ./include #$(LIBHEADER)

#-------------[onject]
OBJ_PATH	= obj
OBJ			= $(addprefix $(OBJ_PATH)/, $(FILES:.c=.o))
ALL_OBJ_PATH= $(addprefix $(OBJ_PATH)/, $(PATH))
$(OBJ_PATH):
	$(DIR) $(ALL_OBJ_PATH)

#-------------[source]
SRC_PATH	= srcs
SRC			= $(addprefix &(SRC_PATH/, $(FILES)))

#-------------[library]
LIBHEADER	= $(LIBFT_HEADER)
LIBFILE		= $(LIBFT_FILE)
LIBPATH		= lib
LIBS		= libs
	#-------------[LIBFT]
	LIBFT		= kml.a
	LIBFT_PATH		= $(LIBPATH)/KML
	LIBFT_FILE		= $(LIBFT_PATH)/$(LIBFT)
	LIBFT_HEADER	= -I $(LIBFT_PATH)/include
$(LIBS): $(LIBFT)
$(LIBFT):
	@make -C $(LIBFT_PATH)

#-------------[FILES]
PATH		= $(S1_PATH) $(PS_PATH)
FILES		= $(STAGE_1) $(PUTSTR)
	#-------------[STAGE_1]
	STAGE_1			= $(addprefix $(S1_PATH)/, $(S1_FILES))
	S1_PATH			= stage1
	S1_FILES		= main.c
		#-------------[PUTSTR]
		PUTSTR			= $(addprefix $(PS_PATH)/, $(PS_FILES))
		PS_PATH			= $(S1_PATH)/putstr
		PS_FILES		= putstr.c

#-------------[PROCESS]
all: $(LIBS) $(NAME)

check:
	printf "ok\n"

$(NAME): $(OBJ) | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFILE) $(HEADER) -o $(OUTPUT_DIR)/$@
	@printf "\033[38;5;46m\033[1m⟪ Complete ⟫\033[0m\n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c Makefile
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)

clean_lib:
	@make clean -C $(LIBFT_PATH)

fclean_lib:
	@make fclean -C $(LIBFT_PATH)

clean: clean_lib
	@rm -rf $(OBJ_PATH)

fclean: clean fclean_lib
	@rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re clean_lib fclean_lib
