/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/06 22:34:47 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

static void	get_token_size(t_filler *f, char *line);
static void	alloc_parse_token(t_filler *f);
static char	*nextln_is_piece(char **token_line);

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
void	handle_token(t_filler *f)
{
	char	*line;

	get_token_size(f, find_line(PIECE_SIZE_LN));
	ft_printf("token rows: %d, token cols: %d\n", f->token_rows, f->token_cols);
	if (f->we == f->next || f->greedy)
	{
		alloc_parse_token(f);
		print_token(f);
	}
	else
	{
		skip_lines(f->token_rows);
		ft_printf("skipping other playa's token\n");
		if (check_play(f) == 0 && nextln_is_piece(&line))
		{
			get_token_size(f, line);
			alloc_parse_token(f);
			f->greedy = 1;
			print_token(f); //<-- delete me!!
		}
	}
	toggle_next(f);
}

void	get_token_size(t_filler *f, char *line)
{
	char	*line_cpy;

	if (!line)
		return ;
	line_cpy = line;
	f->token_rows = parse_digits(&line);
	f->token_cols = parse_digits(&line);
	ft_strdel(&line_cpy);
}

void	alloc_parse_token(t_filler *f)
{
	char	*line;
	char	*line_cpy;
	int		i;

	f->token = ft_strnew(f->token_rows * f->token_cols);
	if (!f->token)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < f->token_rows * f->token_cols)
	{
		get_next_line(0, &line);
		line_cpy = line;
		while (*line && *line != '\n')
			f->token[i++] = *(line++);
		ft_strdel(&line_cpy);
	}
}

/*
**	If next line is a token, returns the line, otherwise, returns NULL.
*/
char	*nextln_is_piece(char **token_line)
{
	get_next_line(0, token_line);
	if (ft_strstr(*token_line, "Piece"))
		return (*token_line);
	else
	{
		ft_strdel(token_line);
		return (0);
	}
}
