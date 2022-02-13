/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:24:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/14 00:08:23 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define BUFF_SIZE		32
# define AUTHOR			"rodrodri"
# define BOARD_SIZE_LN	"Plateau"
# define PIECE_SIZE_LN	"Piece"
# define FIRST_BOARD_LN	"000"
# define PLAYA_NUM_LN	"$$$ exec p"
# define LAST_MOVE_LN	"<got"
# define END_GAME_LN	"=="
# define PLAYA1			'O'
# define PLAYA2			'X'

#include <stdio.h> // <=======Don't forget to delete this!!!
#include "heatmap.h"

/*
**	Type definitions
*/
typedef struct s_filler
{
	char	**board;
	char	**piece;
	char	*line;
	int		**heat_map;
	char	our_playa;
	char	other_playa;
	int		b_rows;
	int		b_cols;
	int		p_rows;
	int		p_cols;
	// int		p_width;
	// int		p_height;
	// char	just_played;
	// char	next_turn;
	// _Bool	oponent_quit;
}	t_filler;

/*
**	Prototypes
*/
int		parse_playas(t_filler *f);
void	get_size(char **line, int *rows, int *cols);
int		parse_board(t_filler *f);
int		handle_piece(t_filler *f, t_heatmap *hm);
int		place_piece(t_filler *f, t_heatmap *hm);

char	**alloc_char_2darr(int rows, int cols);
void	free_char_2darr(char **arr);
int		find_line(char **ln, const char *str);
int		skip_lines(char **str, int n);
void	print_char2darr(char **str);

int		make_filler_heatmap(t_filler *f, t_heatmap *hm);
void	print_filler_heatmap(t_heatmap *hm);

#endif