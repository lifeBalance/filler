/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:22:48 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/06 22:36:09 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

void	init_filler(t_filler *f);
void	get_our_playa(t_filler *f);
void	get_board_size(t_filler *f);
int		parse_board(t_filler *f);

int	main(void)
{
	t_filler	f;

	// ft_printf("Buf: %d\n", BUFF_SIZE);
	ft_memset(&f, 0, sizeof(f));
	get_our_playa(&f);
	ft_printf("we're playa #%d!\n", f.we);
	init_board(&f);
	f.next = 1;
	while (1)
	{
		handle_token(&f);
		if (parse_board(&f) == 0)
			break ;
	// 	// Place the token (print its coordinates on the board)
	}
	system("leaks rodrodri.filler");
	return (0);
}

/*
**	It fast-forwards to the line starting with '$$$ exec', and checks if it
**	contains our player name. If so, we're player 1, otherwise we're player 2.
**	(It could be refactor to also extract both player names and store them
**	in dedicated fields of the t_filler structure; can be used for visualize).
*/
void	get_our_playa(t_filler *f)
{
	char	*line;

	line = find_line(PLAYA_LN);
	if (!line)
		exit(EXIT_FAILURE);
	if (ft_strstr(line, AUTHOR))
		f->we = 1;
	else
		f->we = 2;
	ft_strdel(&line);
}

// int	get_last_move(void)
// {
// 	char	*line;
// 	char	*line_cpy;
// 	int		last_move;

// 	get_next_line(0, &line);
// 	line_cpy = line;
// 	line = ft_strchr(line, '(');
// 	if (line[1] == 'O')
// 		last_move = 1;
// 	else
// 		last_move = 2;
// 	ft_strdel(&line_cpy);
// 	return (last_move);
// }
