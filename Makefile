NAME = push_swap

CC = gcc

INC_DIR = libft/includes includes
SRC_DIR = $(shell find srcs -type d)
OBJ_DIR = obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)
CFLAGS =  -Wall -Werror -Wextra -g
IFLAG = $(foreach dir, $(INC_DIR), -I $(dir) )

SRCS = main.c chain_list.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

# Colors

_GREY=	$'\e[30m
_RED=	$'\e[31m
_GREEN=	$'\e[32m
_YELLOW=$'\e[33m
_BLUE=	$'\e[34m
_PURPLE=$'\e[35m
_CYAN=	$'\e[36m
_WHITE=	$'\e[37m

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAG) -c $< -o $@

$(NAME)	: $(OBJ)
	
	@$(CC) $(CFLAGS) $(IFLAG) $(OBJ) -o $@ libft/libft.a
	@echo "Compilated and executable created"

install:
	@make -C libft

re-install :
	@make -C libft re

clean: 
	@rm -rf $(OBJ_DIR)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re		: fclean install all