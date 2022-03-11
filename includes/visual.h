/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:24:24 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/10 17:41:51 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

/*
**	Nested Headers
*/
# include <ncurses.h>

/*
**	Macro definitions
*/
# define BUFF_SIZE		32
# define BANNER_HEIGHT	12
# define BANNER_WIDTH	80

# define AUTHOR			"rodrodri"
# define BOARD_SIZE_LN	"Plateau"
# define PIECE_SIZE_LN	"Piece"
# define FIRST_BOARD_LN	"000"
# define PLAYA_NUM_LN	"$$$ exec p"
# define LAST_MOVE_LN	"<got"
# define END_GAME_LN	"=="

# define PLAYA1_COLOR	1
# define PLAYA1_COLOR2	2
# define PLAYA2_COLOR	3
# define PLAYA2_COLOR2	4
# define NUM_COLOR		5

/*
**	Type definitions
*/
typedef struct s_visualizer
{
	char	banner[BANNER_HEIGHT][BANNER_WIDTH + 1];
	int		fd;
	int		fd2;
	char	*line;
	char	**board;
	char	**piece;
	char	our_playa;
	char	other_playa;
	int		b_rows;
	int		b_cols;
	int		p_rows;
	int		p_cols;
	int		y;
	int		x;
	int		runs;
}	t_visualizer;

/*
**	Prototypes
*/
void	init_colors();
void	colorize_board(WINDOW *w, char *line, int win_row);

#endif