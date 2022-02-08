/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/08 19:37:51 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

/*
**	1. It parses the size of the board (in rows and columns)
**	2. It allocates memory for a string to hold the board.
**	3. Finally it parses the board cells.
*/
int	alloc_board(t_filler *f)
{
	f->board = alloc_char_2darr(f->b_rows, f->b_cols);
	if (!f->board)
		return (-1);
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
	char	*ln_cpy;
	int		i;
	int		j;

	i = 0;
	while (i < f->b_rows)
	{
		if (i > 0)
			get_next_line(STDIN_FILENO, &f->line);
		ln_cpy = f->line;
		ln_cpy = ft_strchr(ln_cpy, ' ') + 1;
		j = 0;
		while (j < f->b_cols && *ln_cpy && *ln_cpy != '\n')
		{
			f->board[i][j] = ln_cpy[j];
			j++;
		}
		ft_strdel(&f->line);
		i++;
	}
	return (0);
}
