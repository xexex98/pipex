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

HEADER_B	=	./inc/pipex_bonus.h\

SRC			=	./src/pipex.c\
				./src/pipex_utils.c\

SRC_B		=	./src_bonus/pipex_bonus.c\
				./src_bonus/pipex_utils_bonus.c\

OBJ	= $(SRC:.c=.o)

OBJ_B	= $(SRC_B:.c=.o)

CC			= gcc
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror
INC			= -I ./inc -I ./libft -I ./gnl
LIB			= -L ./libft -lft

all: $(NAME)

%.o: %.c  $(HEADER) $(HEADER_B)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	@make -C ./libft
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME) $(LIB)
	rm ./src/*.o

# $(NAME_B) поменяяять
b: $(OBJ_B) $(HEADER_B)
	$(CC) $(CFLAGS) $(INC) $(OBJ_B) -o $(NAME) $(LIB)
	rm ./src_bonus/*.o

clean:
	make clean -C ./libft
	$(RM) $(OBJ) $(OBJ_B)
# $(NAME_B) поменяяять
f: clean
	make clean -C ./libft
	$(RM) $(NAME) $(NAME_B)

re: fclean all

.PHONY: bonus all clean fclean re