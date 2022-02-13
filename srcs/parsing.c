/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/14 00:15:19 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

// static int	parse_digits(char *line, int *n);

/*
**	It finds the line starting with '$$$ exec p1', and checks if it
**	contains our player name. If so, we're player 1, otherwise we're player 2.
**	(It could be refactored to also extract both player names and store them
**	in dedicated fields of the t_filler structure; can be used for visualize).
*/
int	parse_playas(t_filler *f)
{
	char	*playa_num;

	if (find_line(&f->line, PLAYA_NUM_LN) < 0)
		return (-1);
	playa_num = ft_strchr(f->line, 'p') + 1;
	if (ft_strncmp(playa_num, "1", 1) == 0)
	{
		f->our_playa = PLAYA1;
		f->other_playa = PLAYA2;
	}
	else
	{
		f->our_playa = PLAYA2;
		f->other_playa = PLAYA1;
	}
	ft_strdel(&f->line);
	return (0);
}

/*
**	It fast-forwards to the first line of the board (jumping over the line that
**	serves as header for the columns), and start parsing the cells.
**	At each line, it jumps over the column at the very beginning, which
**	contains the number of the row.
**	It stops reading lines at the very last line of the board.
*/
int	parse_board(t_filler *f)
{
	int	i;
	int	offset;

	if (find_line(&f->line, FIRST_BOARD_LN) < 0)
		return (-1);
	i = 0;
	while (i < f->b_rows)
	{
		ft_strclr(f->board[i]);
		if (i > 0)
			get_next_line(STDIN_FILENO, &f->line);
		offset = (ft_strchr(f->line, ' ') + 1) - f->line;
		ft_strncpy(f->board[i], f->line + offset, f->b_cols);
		ft_strdel(&f->line);
		i++;
	}
	return (0);
}

/*
**	It starts by getting the size of the piece from the line that has already
**	been stored in f->line. Once the size it sets:
**	1. If it's NOT OUR TURN, it skips the piece lines. Then it parses the
**	 'got>' line. If the move is [0, 0]:
**		1. If there's no 'Plateu' line below, it means the other playa
**		lost and bailed (set boolean 'greedy' to 1, ALL next pieces ours!).
**		We gotta parse/place(print for now) the piece.
**		2. If there's a 'Plateau', we return!
**	2. If it's OUR TURN, will parse, place and delete the piece.
*/
int	handle_piece(t_filler *f, t_heatmap *hm)
{
	int	ret;
	int	i;

	if (find_line(&f->line, PIECE_SIZE_LN) < 0)
		return (-1);
	get_size(&f->line, &f->p_rows, &f->p_cols);
	f->piece = alloc_char_2darr(f->p_rows, f->p_cols);
	if (!f->piece)
		return (-1);
	i = 0;
	while (i < f->p_rows)
	{
		get_next_line(STDIN_FILENO, &f->line);
		ft_strncpy(f->piece[i], f->line, f->p_cols);
		ft_strdel(&f->line);
		i++;
	}
	if (place_piece(f, hm) < 0)
		ret = -1;
	else
		ret = 0;
	free_char_2darr(f->piece);
	free(f->piece);
	return (ret);
}

/*
**	It passes its 'str' argument (the address of a string), to the 
**	'parse_digits' function, which returns an 'int' value that will
**	be assigned to the 'rows' and 'cols' parameters.
**	It DELETES the string at the end, and returns '1'.
*/
void	get_size(char **ln, int *rows, int *cols)
{
	char	*ln_cpy;

	ln_cpy = *ln;
	while (!(ft_isdigit(*ln_cpy)))
		ln_cpy++;
	*rows = ft_atoi(ln_cpy);
	while (!(ft_isdigit(*ln_cpy)))
		ln_cpy++;
	*cols = ft_atoi(ln_cpy);
	ft_strdel(ln);
}
