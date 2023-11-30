# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 12:58:17 by maraasve          #+#    #+#              #
#    Updated: 2023/11/30 13:54:03 by maraasve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar -rcs
LIBFT_DIR = ./libft
LIBFT_NAME = $(LIBFT_DIR)/libft.a

SRC = ft_printf.c \
			ft_printf_utils.c \
			ft_printf_utils2.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJ)
	@$(AR) $@ $(OBJ)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_NAME):
	@cd $(LIBFT_DIR) && $(MAKE)
	@cp $(LIBFT_NAME) $(NAME)

clean:
	@$(RM) $(OBJ)
	@cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
	@$(RM) $(NAME)
	@cd $(LIBFT_DIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re



