/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:24:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/06 16:59:46 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define BUFF_SIZE		32
# define AUTHOR			"rodrodri"
# define BOARD_SIZE_LN	"Plateau"
# define PIECE_SIZE_LN	"Piece"
# define FIRST_BOARD_LN	"000"
# define PLAYA_LN		"$$$ exec"

#include <stdio.h> // <=======Don't forget to delete this!!!

/*
**	Type definitions
*/
typedef struct s_filler
{
	char	*board;
	char	*token;
	int		playa;
	int		rows;
	int		cols;
	int		token_rows;
	int		token_cols;
	int		last_move;
	_Bool	greedy;
}	t_filler;

/*
**	Prototypes
*/
void	init_board(t_filler *f);
void	parse_board(t_filler *f);
int		parse_digits(char **line);
void	handle_token(t_filler *f);

char	*find_line(const char *str);
void	skip_lines(int n);
int		check_play(void);
void	print_matrix(char *s, int rows, int cols);

#endif