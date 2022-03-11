/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:24:24 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/11 14:05:43 by rodrodri         ###   ########.fr       */
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
	int		fd;
	char	*line;
	char	**board;
	char	**piece;
	int		score1;
	int		score2;
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
void	colorize_line(WINDOW *w, char *line, int win_row);
void	parse_board_size(t_visualizer *v);
int		find_line(int fd, char **ln, const char *str);
void	parse_score(t_visualizer *v);

#endif