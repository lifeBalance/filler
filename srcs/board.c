/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/09 17:51:17 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

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
