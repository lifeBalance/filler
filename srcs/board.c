/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/06 16:23:00 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

static void	get_board_size(t_filler *f);

/*
**	1. It parses the size of the board (in rows and columns)
**	2. It allocates memory for a string to hold the board.
**	3. Finally it parses the board cells.
*/
void	init_board(t_filler *f)
{
	get_board_size(f);
	f->board = ft_strnew(f->rows * f->cols);
	if (!f->board)
		exit(EXIT_FAILURE);
	parse_board(f);
}

/*
**	It fast-forwards to the line which contains the size of the board (the
**	one that starts with "Plateau", and parses the number or rows and columns.
*/
static void	get_board_size(t_filler *f)
{
	char	*line;
	char	*line_cpy;

	line = find_line(BOARD_SIZE_LN);
	line_cpy = line;
	f->rows = parse_digits(&line);
	f->cols = parse_digits(&line);
	ft_strdel(&line_cpy);
}

/*
**	It fast-forwards to the first line of the board (jumping over the line that
**	serves as header for the columns), and start parsing the cells.
**	At each line, it jumps over the column at the very beginning, which
**	contains the number of the row.
**	It stops reading lines at the very last line of the board.
*/
void	parse_board(t_filler *f)
{
	char	*line;
	char	*line_cpy;
	int		i;

	line = find_line(FIRST_BOARD_LN);
	i = 0;
	while (1)
	{
		line_cpy = line;
		line = ft_strchr(line, ' ') + 1;
		while (*line && *line != '\n')
			f->board[i++] = *(line++);
		ft_strdel(&line_cpy);
		if (i < f->rows * f->cols)
			get_next_line(0, &line);
		else
			break ;
	}
}
