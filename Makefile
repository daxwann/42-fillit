# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/26 15:59:13 by xwang             #+#    #+#              #
#    Updated: 2018/12/26 16:03:21 by xwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
SRCS = main.c output.c tetrimino.c piece.c list.c backtrack.c board.c
OBJ = ${SRCS:.c=.o}

all: $(NAME)
$(NAME):
	gcc $(FLAGS) -I. -c $(SRCS)
	gcc $(FLAGS) $(OBJ) -o $(NAME)
clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
