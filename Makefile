# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 16:19:55 by rodrodri          #+#    #+#              #
#    Updated: 2022/03/11 09:52:15 by rodrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILLER		:=	rodrodri.filler
VISUALIZER	:=	visualizer

CC		:=	clang

CFLAGS	:=	-Wall -Werror -Wextra -Iincludes -Ilibft/includes
LDFLAGS	:=	-L./libft
LDLIBS	:=	-lft

FIL_HDRS	=	filler.h #logging.h
VIS_HDRS	=	visual.h

FIL_SDIR	:= ./srcs/filler
FIL_ODIR	:= ./objs/filler

VIS_SDIR	:= ./srcs/visual
VIS_ODIR	:= ./objs/visual

FIL_SRC_LIST	=	main.c parsing.c utils.c solving.c #logging.c
FIL_SRC_LIST	+=	heatmap.c heatmap_utils.c

VIS_SRC_LIST	=	main.c color.c

FIL_SRCS	=	$(addprefix $(FIL_SDIR)/,$(FIL_SRC_LIST))
FIL_OBJS	=	$(patsubst  $(FIL_SDIR)/%,$(FIL_ODIR)/%,$(FIL_SRCS:.c=.o))

VIS_SRCS	=	$(addprefix $(VIS_SDIR)/,$(VIS_SRC_LIST))
VIS_OBJS	=	$(patsubst  $(VIS_SDIR)/%,$(VIS_ODIR)/%,$(VIS_SRCS:.c=.o))

all:		$(FILLER) $(VISUALIZER)

$(FILLER):	$(FIL_OBJS)
	mv $(notdir $(FIL_OBJS)) $(FIL_ODIR)
	$(CC) $(CFLAGS) $(FIL_OBJS) $(LDFLAGS) $(LDLIBS) -o $(FILLER)

$(FIL_OBJS): $(FIL_SRCS)
	mkdir -p $(FIL_ODIR)
	$(CC) $(CFLAGS) -c $^

$(VISUALIZER):	$(VIS_OBJS)
	mv $(notdir $(VIS_OBJS)) $(VIS_ODIR)
	$(CC) $(CFLAGS) $(VIS_OBJS) $(LDFLAGS) $(LDLIBS) -lft -lncurses -o $(VISUALIZER)

$(VIS_OBJS): $(VIS_SRCS)
	mkdir -p $(VIS_ODIR)
	$(CC) $(CFLAGS) -c $^

clean:
	/bin/rm -rf $(VIS_ODIR) $(FIL_ODIR)
	make -sC libft clean

fclean:	clean
	/bin/rm -f $(FILLER) $(VISUALIZER)
	make -sC libft fclean

re:	fclean all

.PHONY:	all clean fclean re
