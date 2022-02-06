/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:22:48 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/06 16:53:51 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

void	get_playa(t_filler *f);
void	get_board_size(t_filler *f);
void	parse_board(t_filler *f);

int	main(void)
{
	t_filler	f;

	// ft_printf("Buf: %d\n", BUFF_SIZE);
	get_playa(&f);
	ft_printf("you're playa #%d!\n", f.playa);
	init_board(&f);
	ft_printf("rows: %d, cols: %d\n", f.rows, f.cols);
	print_matrix(f.board, f.rows, f.cols); // just for now
	handle_token(&f);
	// while (1)
	// {
	// 	handle_token(&f);
	// 	// Place the token (print its coordinates on the board)
	// 	print_matrix(f.token, f.token_rows, f.token_cols); // just for now
	// 	ft_strdel(&f.token); // just for now
	// 	parse_board(&f);
	// 	print_matrix(f.board, f.rows, f.cols); // just for now
	// }
	system("leaks rodrodri.filler");
	return (0);
}

/*
**	It fast-forwards to the line starting with '$$$ exec', and checks if it
**	contains our player name. If so, we're player 1, otherwise we're player 2.
**	(It could be refactor to also extract both player names and store them
**	in dedicated fields of the t_filler structure; can be used for visualize).
*/
void	get_playa(t_filler *f)
{
	char	*line;

	line = find_line(PLAYA_LN);
	if (!line)
		exit(EXIT_FAILURE);
	if (ft_strstr(line, AUTHOR))
		f->playa = 1;
	else
		f->playa = 2;
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
