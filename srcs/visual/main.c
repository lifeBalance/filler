/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:37:24 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/11 21:07:07 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <fcntl.h>
#include "visual.h"
#include "libft.h"

static void	print_banner(t_visualizer *v);
static void	print_board(t_visualizer *v);
static void	print_score(t_visualizer *v);

int	main(void)
{
	t_visualizer	v;

	v.w_board = NULL;
	v.w_banner = NULL;
	v.w_score = NULL;
	v.runs = 0;
	initscr();
	init_colors();
	print_banner(&v);
	wrefresh(v.w_banner);
	print_board(&v);
	print_score(&v);
	refresh();
	getch();
	delwin(v.w_banner);
	delwin(v.w_board);
	endwin();
	return (0);
}

void	print_banner(t_visualizer *v)
{
	int	i;

	v->w_banner = newwin(BANNER_HEIGHT, BANNER_WIDTH, 0, 0);
	v->fd = open("./bling/banner.txt", O_RDONLY);
	i = 0;
	while (i < BANNER_HEIGHT)
	{
		get_next_line(v->fd, &v->line);
		mvwprintw(v->w_banner, i, 0, "%s", v->line);
		ft_strdel(&v->line);
		i++;
	}
	close(v->fd);
}

void	print_board(t_visualizer *v)
{
	int	i;

	v->fd = STDIN_FILENO;
	while (find_line(v->fd, &v->line, BOARD_SIZE_LN) == 0)
	{
		if (v->runs == 0)
		{
			parse_board_size(v);
			v->w_board = \
				newwin(v->b_rows + 1, v->b_cols + 4, BANNER_HEIGHT + 1, 0);
		}
		ft_strdel(&v->line);
		i = 0;
		while (i < v->b_rows + 1)
		{
			get_next_line(v->fd, &v->line);
			colorize_b_line(v, i);
			ft_strdel(&v->line);
			i++;
		}
		usleep(50000);
		wrefresh(v->w_board);
		v->runs++;
	}
}

void	print_score(t_visualizer *v)
{
	v->fd = STDIN_FILENO;
	parse_score(v);
	v->w_score = newwin(1, 80, v->b_rows + BANNER_HEIGHT + 1, 0);
	if (v->score1 > v->score2)
		mvwprintw(v->w_score, 0, 0, "Player 1 wins!");
	else if (v->score1 < v->score2)
		mvwprintw(v->w_score, 0, 0, "Player 2 wins!");
	else
		mvwprintw(v->w_score, 0, 0, "Draw!");
	wrefresh(v->w_score);
	delwin(v->w_score);
	sleep(10);
}
