# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 16:19:55 by rodrodri          #+#    #+#              #
#    Updated: 2022/02/08 19:20:51 by rodrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	rodrodri.filler

CC		:=	clang

CFLAGS	:=	-Wall -Werror -Wextra -Iincludes -Ilibft/includes
LDFLAGS	:=	-L./libft
LDLIBS	:=	-lft

OBJS_DIR	:= ./objs/
vpath	%.h ./includes
vpath	%.c ./srcs

OBJS	=	$(patsubst %,$(OBJS_DIR)/%,$(SRCS:.c=.o))
HDRS	=	filler.h
SRCS	=	main.c board.c piece.c play.c utils.c heat_map.c

all:		$(NAME)

$(NAME):	$(OBJS)
	make -sC libft
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(OBJS_DIR)/%.o: %.c $(HDRS)
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	/bin/rm -rf $(OBJS_DIR)
	make -sC libft clean

fclean:	clean
	/bin/rm -f $(NAME)
	make -sC libft fclean

re:	fclean all

.PHONY:	all clean fclean re
