# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 18:29:49 by ycucchi           #+#    #+#              #
#    Updated: 2022/04/11 15:25:27 by ycucchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
SRCS = main.c
HEADER = ft_printf.h
OBJ = $(SRCS:.c=.o)
LIBFT_PATH = ./libft/
LIBFT = ./libft/libftprintf.a
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LIBFT_PATH)
	gcc $(FLAGS) -c $(SRCS)
	gcc $(OBJ) $(LIBFT) $(FLAGS) -o $(NAME)


clean:
	rm -rf $(OBJ)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all
