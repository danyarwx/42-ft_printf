NAME = libftprintf.a

CC          := cc
CFLAGS      := -Wall -Wextra -Werror -I include
RM          := rm -f

SRC_DIR     := src
OBJ_DIR     := obj
LIBFT_DIR   := libft
LIBFT_A     := $(LIBFT_DIR)/libft.a

SRCS := $(addprefix $(SRC_DIR)/, \
		ft_printf.c \
		ft_put_chars.c \
		ft_put_nbr.c \
		ft_put_unbr.c \
		ft_put_ptr.c \
		ft_put_hex.c)

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJ_DIR) $(OBJS)
	@cp $(LIBFT_A) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "built $(NAME)"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/ft_printf.h include/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
