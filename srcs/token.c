/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/08 17:20:43 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

// static int	get_token_size(t_filler *f);
int	alloc_token(t_filler *f);
void	parse_token(t_filler *f);

/*
**	It starts by getting the size of the token:
**	1. If it's not our turn skip the token lines. Then it parses the 'got>'
**	line. If the move is [0, 0]:
**		1. If there's no 'Plateu' line below, it means the other playa
**		lost and bailed (set boolean 'greedy' to 1, ALL next pieces ours!).
**		We gotta parse/place(print for now) the token.
**		2. If there's a 'Plateau', we return!
**	2. If it's our turn, will parse the token.
*/
int	handle_piece(t_filler *f)
{
	if (f->our_playa == f->next)
	{
		if (find_line(&f->line, PIECE_SIZE_LN))
			get_size(&f->line, &f->p_rows, &f->p_cols);
		else
			return (-1);
		if (skip_lines(f, f->p_rows) <= 0)
			return (-1);
		ft_printf("Our piece was %d %d\n", f->p_rows, f->p_cols);
		// if (alloc_token(f))
		// 	parse_token(f);
		// else
		// 	return (-1);
		// print_char2darr(f->token, f->p_rows, f->p_cols); //<-- delete me!!
		// free_char_2darr(f->token, f->p_rows); //<-- only after you place it!!!
	}
	else
	{
		if (skip_lines(f, f->p_rows) <= 0)
			return (-1);
		ft_printf("Other guy's piece was %d %d\n", f->p_rows, f->p_cols);
	}
	toggle_next(f);
	return (1);
}

// handle_other_piece(t_filler *f)
// {
// 	if (f->our_playa == f->next || f->greedy)
// 	{
		
// 		ft_printf("skipping other playa's token\n");
// 		// if (check_play(&f->line) == 0)
// 		// {
// 		// 	ret = find_line(&f->line, PIECE_SIZE_LN);
// 		// 	if (ret < 0)
// 		// 		return (-1);
// 		// 	else if (ret == 0)
// 		// 	{
// 		// 		ft_strdel(&f->line);
// 		// 		return (0);
// 		// 	}
// 		// 	else if (ret == 1)
// 		// 	{
// 		// 		get_size(&f->line, &f->p_rows, &f->p_cols);
// 		// 		alloc_token(f);
// 		// 		parse_token(f);
// 		// 		f->greedy = 1;
// 		// 		print_char2darr(f->token, f->p_rows, f->p_cols); //<-- delete me!!
// 		// 		free_char_2darr(f->token, f->p_rows); //<-- only after you place it!!!
// 		// 	}
// 		// }
// 	}
// 	toggle_next(f);
// 	return (0);
// }

int	alloc_token(t_filler *f)
{
	f->token = alloc_char_2darr(f->p_rows, f->p_cols);
	if (!f->token)
		return (-1);
	return (1);
}

void	parse_token(t_filler *f)
{
	int		i;
	int		j;

	i = 0;
	while (i < f->p_rows)
	{
		get_next_line(STDIN_FILENO, &f->line);
		j = 0;
		while (j < f->p_cols)
		{
			f->token[i][j] = f->line[j];
			j++;
		}
		ft_strdel(&f->line);
		i++;
	}
}