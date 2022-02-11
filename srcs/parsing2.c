/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/11 16:08:01 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

static void	set_next_turn(t_filler *f);
static int	parse_digits(char *line, int *n);

int	get_size(char **ln, int *rows, int *cols)
{
	int		advance;

	advance = parse_digits(*ln, rows);
	parse_digits(*ln + advance, cols);
	ft_strdel(ln);
	return (1);
}

/*
**	It parses its 'str' argument (the address of a string), searching for
**	digits, which are stored in an 'int' variable returned at the end.
*/
int	parse_digits(char *line, int *n)
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

/*
**	It reads the line with the last play, checking if its value is "[0, 0]"
**	It also determines the player that played last, setting the 'last_move'
**	field accordingly.
**	Regardless of the player, it returns 0 if the last play was "[0, 0]",
**	and 1 otherwise.
*/
int	check_play(t_filler *f)
{
	f->just_played = *(ft_strchr(f->line, '(') + 1);
	set_next_turn(f);
	ft_strdel(&f->line);
	get_next_line(STDIN_FILENO, &f->line);
	if (ft_strstr(f->line, PIECE_SIZE_LN))
	{
		f->oponent_quit = 1;
		handle_piece(f);
	}
	else if (ft_strstr(f->line, END_GAME_LN))
	{
		ft_strdel(&f->line);
		return (-1);
	}
	else if (ft_strstr(f->line, BOARD_SIZE_LN))
	{
		ft_strdel(&f->line);
		skip_lines(&f->line, 1);
	}
	return (0);
}

static void	set_next_turn(t_filler *f)
{
	if (f->just_played == PLAYA1)
		f->next_turn = PLAYA2;
	else
		f->next_turn = PLAYA1;
}
