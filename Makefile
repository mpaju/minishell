# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/04 10:08:01 by mpaju             #+#    #+#              #
#    Updated: 2017/10/27 17:09:39 by mpaju            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
NAME		= minishell
UNAME		= Minishell
FLAGS		= -Wall -Werror -Wextra

LIB_DIR		= libft/
LIB_NAME	= libft.a
LIB			= $(addprefix $(LIB_DIR), $(LIB_NAME))
LINK_LIB	= -L./$(LIB_DIR) -lft

TERM_LIB	= -ltermcap

HEAD_LOC	= includes
HEAD_FILE	= $(addprefix $(INCS)/, minishell.h)

HEAD_LOCS	= -Iincludes -Ilibft/includes

SRC 		=	main.c \
				utils.c \
				parse_input.c \
				check_and_exec.c \
				builtins/cd.c \
				builtins/echo.c \
				builtins/env_ops.c \
				builtins/exit.c \
				builtins/setenv.c \
				builtins/unsetenv.c

SRC_DIR		= sources
OBJ_DIR		= objects
SRCS		= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJS_DIR	= $(sort $(dir $(OBJS)))

all: build $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) -o $@ $^ -g $(LINK_LIB) $(TERM_LIB)
	@echo "\033[0;37m$(UNAME) make all done\033[0;38m"

build:
	@mkdir -p $(OBJS_DIR)

$(LIB):
	@make -C $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) $(HEAD_LOCS) -c -o $@ $< -g

clean:
	@make clean -C $(LIB_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "\033[0;33m$(UNAME) make clean done\033[0;38m"

fclean:
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIB_DIR)
	@echo "\033[0;34m$(UNAME) make fclean done\033[0;38m"

re:
	@make fclean all
	@echo "\033[0;36m$(UNAME) make re done\033[0;38m"

.PHONY: re fclean clean deb build $(NAME) all
