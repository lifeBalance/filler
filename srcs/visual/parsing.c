/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:08:45 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/11 22:41:38 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "visual.h"

static int	parse_digits(char *line, int *n);
static void	parse_size(char **ln, int *rows, int *cols);

void	parse_piece_size(t_visualizer *v)
{
	get_next_line(v->fd, &v->line);
	parse_size(&v->line, &v->p_rows, &v->p_cols);
	ft_strdel(&v->line);
}

void	parse_board_size(t_visualizer *v)
{
	get_next_line(v->fd, &v->line);
	parse_size(&v->line, &v->b_rows, &v->b_cols);
	v->w_board = newwin(v->b_rows + 1, v->b_cols + 4, 1, 1);
	ft_strdel(&v->line);
}

/*
**	It passes its 'str' argument (the address of a string), to the 
**	'parse_digits' function, which returns an 'int' value that will
**	be assigned to the 'rows' and 'cols' parameters.
**	It DELETES the string at the end, and returns '1'.
*/
void	parse_size(char **ln, int *rows, int *cols)
{
	int		advance;

	advance = parse_digits(*ln, rows);
	parse_digits(*ln + advance, cols);
}

/*
**	It parses its 'str' argument, searching for digits, which
**	are stored in an 'int' variable returned at the end.
*/
static int	parse_digits(char *line, int *n)
{
	int	i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	*n = 0;
	while (line[i] && ft_isdigit(line[i]))
	{
		*n = *n * 10 + (line[i] - '0');
		i++;
	}
	return (i);
}

void	parse_score(t_visualizer *v)
{
	v->score1 = 0;
	v->score2 = 0;
	if (find_line(v->fd, &v->line, END_GAME_LN) == 0)
		parse_digits(v->line, &v->score1);
	ft_strdel(&v->line);
	if (find_line(v->fd, &v->line, END_GAME_LN) == 0)
		parse_digits(v->line, &v->score2);
	ft_strdel(&v->line);
}
