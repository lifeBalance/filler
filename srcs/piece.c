/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/09 17:45:21 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

void	parse_piece(t_filler *f);

/*
**	It starts by getting the size of the piece:
**	1. If it's not our turn skip the piece lines. Then it parses the 'got>'
**	line. If the move is [0, 0]:
**		1. If there's no 'Plateu' line below, it means the other playa
**		lost and bailed (set boolean 'greedy' to 1, ALL next pieces ours!).
**		We gotta parse/place(print for now) the piece.
**		2. If there's a 'Plateau', we return!
**	2. If it's our turn, will parse the piece.
*/
int	handle_piece(t_filler *f)
{
	get_size(&f->line, &f->p_rows, &f->p_cols);
	if (f->our_playa == f->next_turn || f->oponent_quit)
	{
		f->piece = alloc_char_2darr(f->p_rows, f->p_cols);
		if (!f->piece)
			return (-1);
		parse_piece(f);
		print_char2darr(f->piece); //<-- delete me!!
		free_char_2darr(f->piece); //<-- only after you place it!!!
		free(f->piece);
	}
	else
	{
		if (skip_lines(&f->line, f->p_rows) <= 0)
			return (-1);
		ft_printf("Skipped other guy's piece (%d %d)\n", f->p_rows, f->p_cols);
	}
	return (1);
}

void	parse_piece(t_filler *f)
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
