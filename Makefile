NAME = libftprintf.a
CC = cc
CFLAGS = -g
AR = ar -rcs
# Directories
LIBFT_DIR = libft
LIBFT_NAME = $(LIBFT_DIR)/libft.a
PRINTF_SRC = src
PRINTF_OBJ = objs

SRC_FILES = ft_printf.c \
			ft_printf_utils.c \

OBJ_FILES = $(SRC_FILES:%.c=$(PRINTF_OBJ)/%.o)

all: libft $(NAME)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ_FILES)
	@cp $(LIBFT_NAME) $(NAME)
	@$(AR) $@ $(OBJ_FILES)
	@echo "[$(NAME)] Library created"

$(PRINTF_OBJ)/%.o:%.c | $(PRINTF_OBJ)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

#Create file $@ = the TARGET value
$(PRINTF_OBJ):
	@mkdir -p $@

$(LIBFT_NAME):
	@$(MAKE) -C $(LIBFT_DIR)

run: all
	@cc -g $(NAME) && ./a.out

clean:
	@rm -rf $(PRINTF_OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf a.out
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft