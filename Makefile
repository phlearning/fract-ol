UNAME 			= $(shell uname)

NAME 			= fractol

# Colors
GREEN			=	\033[0;32m
RED				=	\033[0;31m
BLUE			=	\033[0;34m
END				=	\033[0m

# Ft_printf
FT_PRINTF_DIR	= ft_printf
FT_PRINTFA		= $(addprefix ./$(FT_PRINTF_DIR)/, libftprintf.a)
FT_PRINTF_INC	= -I $(LIBFT_DIR)
FT_PRINTF_LNK	= -L $(FT_PRINTF_DIR) -lftprintf

# Libft & MLX

LIBFT_DIR		= libft
LIBFTA			= $(addprefix ./$(LIBFT_DIR)/, libft.a)
LIB_INC			= -I $(LIBFT_DIR)
LIB_LNK			= -L $(LIBFT_DIR) -lft

ifeq ($(UNAME), linux)
	MLX			= mlx_linux
	MLX_LNK 	= -L $(MLX) -lmlx -lXext -lX11
else 
	MLX			= mlx_opengl
	MLX_LNK 	= -L $(MLX) -lmlx -framework OpenGL -framework Appkit
endif 

MLX_INC			= -I $(MLX)
MLX_LIB			= $(addprefix $(MLX), mlx.a)

# SRCS

SRC_DIR			= src

SOURCES			= test.c \
				utils.c \
				mandelbrot.c \
				hook.c

SRC = $(addprefix $(SRC_DIR)/,$(SOURCES))

# OBJS

OBJS_DIR 		= objs

OBJS 			= $(addprefix ./$(OBJS_DIR)/,$(SOURCES:.c=.o))

# Compiling

CC				= gcc

CFLAGS 			= -Wall -Werror -Wextra

INCLUDE 		= -I include

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
	@make -C $(FT_PRINTF_DIR)
	@echo "$(BLUE) Ft_printf compiled $(END)"
	@make -s -C $(MLX)
	@echo "$(GREEN) MLX compiled $(END)"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LNK) $(LIB_LNK) $(FT_PRINTF_LNK) -lm -o $(NAME)
	@echo "$(BLUE) Fractol Compiled $(END)"

clean:
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean
	@make -C $(MLX) clean
	@echo "Fractol Cleaning Done"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean
	@echo "Fractol Fcleaning Done"

re: fclean all

.PHONY: all fclean clean re temp