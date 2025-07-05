# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marieke <marieke@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 12:58:17 by maraasve          #+#    #+#              #
#    Updated: 2025/07/05 11:30:13 by marieke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -isystem $(INCL_DIR) -isystem $(LIBFT_INCL_DIR)
AR = ar -rcs
RM = rm -rf

LIBFT_DIR = libft
LIBFT_INCL_DIR = libft/incl
LIBFT_NAME = $(LIBFT_DIR)/libft.a

INCL_DIR = incl
SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = build/obj

SRC =	ft_printf.c \
		output_char.c \
		output_num.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJ)
	@$(AR) $@ $(OBJ)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT_NAME):
	@cd $(LIBFT_DIR) && $(MAKE)
	@cp $(LIBFT_NAME) $(NAME)

clean:
	@$(RM) $(BUILD_DIR)
	@cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
	@$(RM) $(NAME)
	@cd $(LIBFT_DIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re
