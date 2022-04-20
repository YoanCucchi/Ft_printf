# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 18:29:49 by ycucchi           #+#    #+#              #
#    Updated: 2022/04/19 11:38:15 by ycucchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
SRCS = ./srcs/ft_printf.c ./srcs/main.c ./srcs/ft_print_utils.c \
./srcs/ft_parse.c ./srcs/ft_initialize_parameter.c ./srcs/ft_print_str.c \
./srcs/ft_print_nbr.c ./srcs/ft_print_hex.c
OBJ = ft_printf.o main.o ft_print_utils.o ft_parse.o \
ft_initialize_parameter.o ft_print_str.o ft_print_nbr.o ft_print_hex.o
OBJ_DIR = ./objects
LIBFT_PATH = ./libft/
LIBFT = libft.a
LIBFT_PRINTF = libftprintf.a
FLAGS = -Wall -Wextra -Werror
CC = gcc

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
PURPLE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	@$(CC) $(FLAGS) -c $(SRCS)
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"
	@cp $(LIBFT_PATH)$(LIBFT) ./$(LIBFT_PRINTF)
	@echo "$(CYAN)$(LIBFT) copied in root with name : $(LIBFT_PRINTF)$(DEFAULT)"
	@echo "$(PURPLE)Compiling $(NAME) with library..$(DEFAULT)"
	@$(CC) $(OBJ) $(LIBFT_PRINTF) $(FLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) with $(LIBFT_PRINTF) compiled!$(DEFAULT)"
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ) $(OBJ_DIR)
	@echo "$(CYAN)objects moved in $(OBJ_DIR)$(DEFAULT)"

debug:
	gcc -g $(FLAGS) -I . libft/libft.a $(SRCS) -o debug

git:
	git add -A
	git commit
	git push

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(GRAY)$(OBJ) cleaned!$(DEFAULT)"
	@rm -rf $(LIBFT_PRINTF)
	@echo "$(GRAY)$(LIBFT_PRINTF) cleaned!$(DEFAULT)"
	@make clean -C libft/

	rm -rf debug.dSYM
	rm -rf debug

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GRAY)$(NAME) cleaned!$(DEFAULT)"

re: fclean all
