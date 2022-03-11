/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:37:24 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/11 15:13:07 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc visual.c -Iincludes -Ilibft/includes -L../libft -lft -lncurses
#include <ncurses.h>
#include <fcntl.h>
#include "visual.h"
#include "libft.h"

static void	print_banner(WINDOW *w, t_visualizer *v);
static void	print_board(WINDOW *w, t_visualizer *v);
static void	print_score(WINDOW *w, t_visualizer *v);

int	main(void)
{
	t_visualizer	v;
	WINDOW			*w_banner;
	WINDOW			*w_board;
	WINDOW			*w_score;

	w_board = NULL;
	w_banner = NULL;
	w_score = NULL;
	v.runs = 0;
	initscr();
	init_colors();
	print_banner(w_banner, &v);
	print_board(w_board, &v);
	print_score(w_score, &v);
	refresh();
	getch();
	endwin();
	return (0);
}

void	print_banner(WINDOW *w, t_visualizer *v)
{
	int	i;

	w = newwin(BANNER_HEIGHT, BANNER_WIDTH, 0, 0);
	v->fd = open("./bling/banner.txt", O_RDONLY);
	i = 0;
	while (i < BANNER_HEIGHT)
	{
		get_next_line(v->fd, &v->line);
		mvwprintw(w, i, 0, "%s", v->line);
		ft_strdel(&v->line);
		i++;
	}
	wrefresh(w);
	delwin(w);
	close(v->fd);
}

void	print_board(WINDOW *w, t_visualizer *v)
{
	int	i;

	v->fd = STDIN_FILENO;
	while(find_line(v->fd, &v->line, BOARD_SIZE_LN) == 0)
	{
		if (v->runs == 0)
		{
			parse_board_size(v);
			w = newwin(v->b_rows + 1, v->b_cols + 4, BANNER_HEIGHT + 1, 0);
		}
		ft_strdel(&v->line);
		i = 0;
		while (i < v->b_rows + 1)
		{
			get_next_line(v->fd, &v->line);
			colorize_line(w, v->line, i);
			ft_strdel(&v->line);
			i++;
		}
		usleep(50000);
		wrefresh(w);
		v->runs++;
	}
	delwin(w);
}

void	print_score(WINDOW *w, t_visualizer *v)
{
	v->fd = STDIN_FILENO;
	parse_score(v);
	w = newwin(1, 80, v->b_rows + BANNER_HEIGHT + 1, 0);
	if (v->score1 > v->score2)
		mvwprintw(w, 0, 0, "Player 1 wins!");
	else if (v->score1 < v->score2)
		mvwprintw(w, 0, 0, "Player 2 wins!");
	else
		mvwprintw(w, 0, 0, "Draw!");
	wrefresh(w);
	delwin(w);
	sleep(10);
}
