/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/08 22:45:17 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

static void	set_next_turn(t_filler *f);

/*
**	It reads the line with the last play, checking if its value is "[0, 0]"
**	It also determines the player that played last, setting the 'last_move'
**	field accordingly.
**	Regardless of the player, it returns 0 if the last play was "[0, 0]",
**	and 1 otherwise.
*/
int		check_play(t_filler *f)
{
	int		play;

	// printf("Checking play...\n");
	if (ft_strstr(f->line, "[0, 0]"))
		play = 0;
	else
		play = 1;
	f->just_played = *(ft_strchr(f->line, '(') + 1);
	set_next_turn(f);
	ft_strdel(&f->line);
	ft_printf("(%c) just played. Next goes (%c)\n",
		f->just_played, f->next_turn); // <==== delete me!!!!
	if (play == 0)
	{
		// ft_printf("other guy moved [0, 0]\n"); // <==== delete me!!!!
		get_next_line(STDIN_FILENO, &f->line);
		if (ft_strstr(f->line, PIECE_SIZE_LN))
		{
			f->oponent_quit = 1;
			handle_piece(f);
		} else
			ft_strdel(&f->line);
	}
	return (play);
}

static void	set_next_turn(t_filler *f)
{
	if (f->just_played == PLAYA1)
		f->next_turn = PLAYA2;
	else
		f->next_turn = PLAYA1;
}
