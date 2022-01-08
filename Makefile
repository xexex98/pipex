# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 13:37:47 by mbarra            #+#    #+#              #
#    Updated: 2022/01/07 15:47:51 by mbarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex\

HEADER		=	./inc/pipex.h\

# HEADER_B	=	./inc/pipex_bonus.h\

SRC			=	./src/pipex.c\

# SRC_B		=	../gnl/get_next_line.c\
				# ../gnl/get_next_line_utils.c\

OBJ	= $(SRC:.c=.o)

# OBJ_B	= $(SRC_B:.c=.o)

CC			= gcc
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror

all: $(NAME)
# %.o: %.c  $(HEADER) $(HEADER_B)
%.o: %.c  $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# $(NAME_B) : 
# bonus: $(OBJ_B) $(HEADER_B)
# 	$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_B)

clean:
	$(RM) $(OBJ)
#  $(OBJ_B)
fclean: clean
	$(RM) $(NAME)
#  $(NAME_B)
re: fclean all

.PHONY: bonus all clean fclean re