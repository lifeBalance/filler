/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/14 00:37:47 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include "heatmap.h"

/*
**	It prints the token and releases it when done. It doesn't return anything.
*/
void	print_char2darr(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
}

void	print_filler_heatmap(t_heatmap *hm)
{
	int	i;
	int	j;

	i = 0;
	while (i < hm->rows)
	{
		j = 0;
		while (j < hm->cols)
		{
			printf("%4d", hm->map[i][j]);
			j++;
		}
		printf("\n\n");
		i++;
	}
}

// static int	measure_piece(t_filler *f)
// {
// 	int	i;
// 	int	j;

// 	f->p_height = f->p_rows;
// 	i = f->p_rows - 1;
// 	while (i > 0)
// 	{
// 		j = 0;
// 		while (j < f->p_cols)
// 		{
// 			if (f->piece[i][j] != '.')
// 				break ;
// 			j++;
// 		}
// 		if (j == f->p_cols)
// 			f->p_height--;
// 		else
// 			break ;
// 		i--;
// 	}
// 	f->p_width = f->p_cols;
// 	j = f->p_cols - 1;
// 	while (j > 0)
// 	{
// 		i = 0;
// 		while (i < f->p_rows)
// 		{
// 			if (f->piece[i][j] != '.')
// 				break ;
// 			i++;
// 		}
// 		if (i == f->p_rows)
// 			f->p_width--;
// 		else
// 			break ;
// 		j--;
// 	}
// 	return (0);
// }

/*
**	It reads the line with the last play, checking if its value is "[0, 0]"
**	It also determines the player that played last, setting the 'last_move'
**	field accordingly.
**	Regardless of the player, it returns:
**		*  0 if the last play was "[0, 0]", or
**		*  1 otherwise.
**		* -1 if the next line is '== ... fin'
*/
// int	check_play(t_filler *f)
// {
// 	int	zero_play;

// 	zero_play = 0;
// 	get_next_line(STDIN_FILENO, &f->line);
// 	f->just_played = *(ft_strchr(f->line, '(') + 1);
// 	if (ft_strstr(f->line, "[0, 0]"))
// 		zero_play = 1;
// 	set_next_turn(f);
// 	ft_strdel(&f->line);
// 	get_next_line(STDIN_FILENO, &f->line);
// 	if (ft_strstr(f->line, PIECE_SIZE_LN) && zero_play && \
// 		f->just_played == f->other_playa)// checks it was opponent's turn!!
// 	{
// 		f->oponent_quit = 1;
// 		return (0);
// 	}
// 	else if (ft_strstr(f->line, END_GAME_LN))
// 	{
// 		ft_strdel(&f->line);
// 		return (-1);
// 	}
// 	else if (ft_strstr(f->line, BOARD_SIZE_LN))
// 		ft_strdel(&f->line);
// 	return (1);
// }

// static void	set_next_turn(t_filler *f)
// {
// 	if (f->just_played == PLAYA1)
// 		f->next_turn = PLAYA2;
// 	else
// 		f->next_turn = PLAYA1;
// }


// static void	parse_piece(t_filler *f)
// {
// 	int		i;

// 	i = 0;
// 	while (i < f->p_rows)
// 	{
// 		get_next_line(STDIN_FILENO, &f->line);
// 		ft_strncpy(f->piece[i], f->line, f->p_cols);
// 		ft_strdel(&f->line);
// 		i++;
// 	}
// }
