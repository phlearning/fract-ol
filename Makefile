UNAME = $(shell uname)

CC		= gcc

NAME = fract-ol

SRC_MAIN = test.c

OBJS_DIR = objs

OBJS_MAIN = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I include

all:		$(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	