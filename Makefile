UNAME = $(shell uname)

NAME = fractol

# Colors
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

# Libft & MLX

LIBFT_DIR	= libft
LIBFTA	= $(addprefix ./$(LIBFT_DIR)/, libft.a)
LIB_INC	= -I $(LIBFT_DIR)
LIB_LNK	= -L $(LIBFT_DIR) -lft

ifeq ($(UNAME), linux)
	MLX	= mlx_linux
	MLX_LNK = -L $(MLX) -lmlx -lXext -lX11
else 
	MLX	= mlx_opengl
	MLX_LNK = -L $(MLX) -lmlx -framework OpenGL -framework Appkit
endif 

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX), mlx.a)

# SRCS

SRC_DIR		= src

SOURCES	= test.c \
		utils.c \
		mandelbrot.c \
		hook.c

SRC = $(addprefix $(SRC_DIR)/,$(SOURCES))

# OBJS

OBJS_DIR = objs

OBJS = $(addprefix ./$(OBJS_DIR)/,$(SOURCES:.c=.o))

# Compiling

CC		= gcc

CFLAGS 	= -Wall -Werror -Wextra

INCLUDE = -I include

all: temp $(NAME)

temp:
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(LIB_INC) $(MLX_INC) $(INCLUDE) -c $< -o $@
	@echo "Compiling..."

$(NAME):	$(OBJS)
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN) Libft compiled $(END)"
	@make -s -C $(MLX)
	@echo "$(BLUE) MLX compiled $(END)"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LNK) $(LIB_LNK) -lm -o $(NAME)
	@echo "$(GREEN) Fractol Compiled $(END)"

clean:
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX) clean
	@echo "Cleaned"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "fcleaned"

re: fclean all

.PHONY: all fclean clean re temp