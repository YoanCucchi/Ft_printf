# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 18:29:49 by ycucchi           #+#    #+#              #
#    Updated: 2022/04/11 15:25:27 by ycucchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
SRCS = ./srcs/ft_printf.c ./srcs/main.c ./srcs/ft_utils.c
OBJ = ft_printf.o main.o ft_utils.o
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
	@echo "$(PURPLE)Compiling libft..$(DEFAULT)"


	@make -C $(LIBFT_PATH)


	@echo "$(GREEN)libft compiled!$(DEFAULT)"


	@$(CC) $(FLAGS) -c $(SRCS)


	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"


	@cp $(LIBFT_PATH)$(LIBFT) ./$(LIBFT_PRINTF)


	@echo "$(GREEN)$(LIBFT) copied in root with name : $(LIBFT_PRINTF)$(DEFAULT)"
	@echo "$(PURPLE)Compiling $(NAME) with library..$(DEFAULT)"


	@$(CC) $(OBJ) $(LIBFT_PRINTF) $(FLAGS) -o $(NAME)

	
	@echo "$(GREEN)$(NAME) with $(LIBFT_PRINTF) compiled!$(DEFAULT)"

clean:
	@rm -rf $(OBJ)
	@echo "$(GRAY)$(OBJ) cleaned!$(DEFAULT)"
	@rm -rf $(LIBFT_PRINTF)
	@echo "$(GRAY)$(LIBFT_PRINTF) cleaned!$(DEFAULT)"
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GRAY)$(NAME) cleaned!$(DEFAULT)"

re: fclean all
