# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 11:13:51 by pvong             #+#    #+#              #
#    Updated: 2023/01/13 15:18:02 by pvong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

# Colors
GREEN			=	\033[0;32m
RED				=	\033[0;31m
BLUE			=	\033[0;34m
END				=	\033[0m

SRCS	= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		  ft_strchr.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c\
		  ft_strlcpy.c ft_strlcat.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		  ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
		  ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c \
		  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		  ft_strcmp.c

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		  ft_lstdelone.c

OBJS	= $(SRCS:.c=.o)

BONUS_OBJS	= $(BONUS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -O3

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)
				
bonus:		$(OBJS) $(BONUS_OBJS)
			@ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
			@ranlib $(NAME)


clean:
			@rm -f $(OBJS)
			@rm -f $(BONUS_OBJS)
			@echo "$(BLUE)Cleaned libft$(END)"

fclean:		clean
			@rm -f $(NAME)
			@echo "$(RED)Fcleaned libft$(END)"

re:			fclean all

.PHONY:		all clean fclean re bonus

