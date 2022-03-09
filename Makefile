# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 16:19:55 by rodrodri          #+#    #+#              #
#    Updated: 2022/03/09 10:03:00 by rodrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	rodrodri.filler

CC		:=	clang

CFLAGS	:=	-Wall -Werror -Wextra -Iincludes -Ilibft/includes
LDFLAGS	:=	-L./libft
LDLIBS	:=	-lft

OBJS_DIR	:= objs
SRCS_DIR	:= srcs
vpath		%.h includes
vpath		%.c srcs

HDRS	=	filler.h heatmap.h
SRCS	=	main.c parsing.c utils.c
SRCS	+=	solving.c heatmap.c heatmap_utils.c logging.c
OBJS	=	$(patsubst %,$(OBJS_DIR)/%,$(SRCS:.c=.o))

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
