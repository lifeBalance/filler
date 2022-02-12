/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/12 13:27:29 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

static void	parse_piece(t_filler *f);

/*
**	It finds the line starting with '$$$ exec p1', and checks if it
**	contains our player name. If so, we're player 1, otherwise we're player 2.
**	(It could be refactored to also extract both player names and store them
**	in dedicated fields of the t_filler structure; can be used for visualize).
*/
int	get_our_playa(t_filler *f)
{
	int	ret;

	ret = find_line(&f->line, WHOS_PLAYA1_LN);
	if (ret < 0)
		return (-1);
	else if (ret == 0)
		return (0);
	if (ft_strstr(f->line, AUTHOR))
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
	return (1);
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
	int		i;
	int		offset;

	i = 0;
	while (i < f->b_rows)
	{
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
	get_size(&f->line, &f->p_rows, &f->p_cols);
	// ft_printf("Piece detected: %dx%d\n", f->p_rows, f->p_cols);
	if (f->our_playa == f->next_turn || f->oponent_quit)
	{
		f->piece = alloc_char_2darr(f->p_rows, f->p_cols);
		if (!f->piece)
			return (-1);
		parse_piece(f);
		print_char2darr(f->piece); //<-- delete me!!
		place_piece(f, hm); // this should be done here (print size for now)
		free_char_2darr(f->piece);
		free(f->piece);
	}
	else
	{
		if (skip_lines(&f->line, f->p_rows) <= 0)
			return (-1);// in case we get to == end?
		ft_printf("Skipped other guy's piece (%d %d)\n", f->p_rows, f->p_cols);
	}
	return (0);
}

static void	parse_piece(t_filler *f)
{
	int		i;

	i = 0;
	while (i < f->p_rows)
	{
		get_next_line(STDIN_FILENO, &f->line);
		ft_strncpy(f->piece[i], f->line, f->p_cols);
		ft_strdel(&f->line);
		i++;
	}
}
