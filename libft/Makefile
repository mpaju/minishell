# **************************************************************************** #

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra

FILES		=	string/ft_str3join.c										  \
				string/ft_strcat.c											  \
				string/ft_strchr.c											  \
				string/ft_strclen.c											  \
				string/ft_strclr.c											  \
				string/ft_strcmp.c											  \
				string/ft_strcpy.c											  \
				string/ft_strdel.c											  \
				string/ft_strdup.c											  \
				string/ft_strequ.c											  \
				string/ft_striter.c											  \
				string/ft_striteri.c										  \
				string/ft_strjoin.c											  \
				string/ft_strlcat.c											  \
				string/ft_strlen.c											  \
				string/ft_strmap.c											  \
				string/ft_strmapi.c											  \
				string/ft_strncat.c											  \
				string/ft_strncmp.c											  \
				string/ft_strncpy.c											  \
				string/ft_strndup.c											  \
				string/ft_strnequ.c											  \
				string/ft_strnew.c											  \
				string/ft_strnstr.c											  \
				string/ft_strrchr.c											  \
				string/ft_strreplace.c										  \
				string/ft_strsplit.c										  \
				string/ft_strstr.c											  \
				string/ft_strsub.c											  \
				string/ft_strtrim.c											  \
				memory/ft_memalloc.c										  \
				memory/ft_memccpy.c											  \
				memory/ft_memchr.c											  \
				memory/ft_memcmp.c											  \
				memory/ft_memcpy.c											  \
				memory/ft_memdel.c											  \
				memory/ft_memmove.c											  \
				memory/ft_memset.c											  \
				output/ft_print_n_chars.c									  \
				output/ft_putchar.c											  \
				output/ft_putchar_fd.c										  \
				output/ft_putendl.c											  \
				output/ft_putendl_fd.c										  \
				output/ft_putnbr.c											  \
				output/ft_putnbr_fd.c										  \
				output/ft_putstr.c											  \
				output/ft_putstr_fd.c										  \
				list/ft_lstadd.c											  \
				list/ft_lstaddlast.c										  \
				list/ft_lstdel.c											  \
				list/ft_lstdelone.c											  \
				list/ft_lstiter.c											  \
				list/ft_lstmap.c											  \
				list/ft_lstnew.c											  \
				list/ft_lstswap.c											  \
				utils/ft_atoi.c											  	  \
	 			utils/ft_bzero.c											  \
	 			utils/ft_chrpos.c											  \
	 			utils/ft_freesplit.c										  \
	 			utils/ft_get_filetype.c										  \
				utils/ft_isalnum.c											  \
				utils/ft_isalpha.c											  \
				utils/ft_isascii.c											  \
				utils/ft_isdigit.c											  \
				utils/ft_islower.c											  \
				utils/ft_isprint.c											  \
				utils/ft_isupper.c											  \
				utils/ft_itoa.c											  	  \
				utils/ft_skip_char.c										  \
				utils/ft_tolower.c											  \
	  			get_next_line.c													  

SRC_DIR		=	sources
SRC_FILES	=	$(addprefix $(SRC_DIR)/, $(FILES))

OBJ_DIR		=	objects
OBJ_FILES	=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
OBJ_DIRS	=	$(sort $(dir $(OBJ_FILES)))

HEAD		=	libft.h get_next_line.h
HEAD_DIR	=	includes
HEAD_FILES	=	$(addprefix $(HEAD_DIR)/, $(HEAD))
HEAD_LINK	=	-I
HEAD_LOC	=	$(addprefix $(HEAD_LINK), $(HEAD_DIR))

NAME		=	libft.a
UNAME		=	Libft

all: build $(NAME)

build:
	@mkdir -p $(OBJ_DIRS)

$(NAME): $(OBJ_FILES)
	@ar rc $(NAME) $(OBJ_FILES)
	@ranlib $(NAME)
	@echo "\033[0;37m$(UNAME) make all done\033[0;38m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) $(HEAD_LOC) -c -o $@ $< -g

clean:
	@rm -f $(OBJ_FILES)
	@echo "\033[0;33m$(UNAME) make clean done\033[0;38m"

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@echo "\033[0;34m$(UNAME) make fclean done\033[0;38m"

re: fclean all
	@echo "\033[0;36m$(UNAME) make re done\033[0;38m"

.PHONY: re fclean clean deb all
