# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 11:14:06 by ycucchi           #+#    #+#              #
#    Updated: 2022/05/03 11:14:13 by ycucchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PRINTF_SRCS = ft_printf.c ft_print_utils.c \
ft_parse.c ft_initialize_parameter.c ft_print_str.c \
ft_print_nbr.c ft_print_hex.c ft_length_flags.c \
ft_print_flag_hex.c ft_print_octal.c ft_octal_helper.c \
ft_hex_helper.c ft_print_unbr.c

LIBFT_SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
 ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c\
ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c\
ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c\
ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c\
ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c\
ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c\
ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c\
ft_toupper.c ft_itoa_unsigned.c ft_long_itoa.c ft_unsigned_long_itoa.c \
ft_nbrlen.c ft_print_char.c ft_putnstr.c ft_octal_itoa.c ft_itoa_base.c

PRINTF_OBJ = $(addprefix $(PRINTF_OBJ_DIR), $(PRINTF_SRCS:%.c=%.o))
PRINTF_SRC = $(addprefix $(PRINTF_SRCS_DIR), $(PRINTF_SRCS:%.c=%.c))
PRINTF_SRCS_DIR = ./srcs/
PRINTF_OBJ_DIR = ./objects/
OBJ = $(PRINTF_SRCS:.c=.o)
LIBFT_OBJ = $(addprefix $(LIBFT_OBJ_DIR), $(LIBFT_SRCS:.c=.o))
LIBFT_OBJ_DIR = ./libft/objects/
OBJ_DIR = ./objects

INCLUDES = -I includes/ft_printf.h
LIBFT_PATH = ./libft/
LIBFT = libft.a
FLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	@$(CC) $(FLAGS) -c $(PRINTF_SRC) $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ) $(OBJ_DIR)
	@ar rcs $(NAME) $(PRINTF_OBJ) $(LIBFT_OBJ)

git:
	git add -A
	git commit -m "$m"
	git push

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(GRAY)$(OBJ) cleaned!$(DEFAULT)"
	@rm -rf $(LIBFT_PRINTF)
	@echo "$(GRAY)$(LIBFT_PRINTF) cleaned!$(DEFAULT)"
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GRAY)$(NAME) cleaned!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re