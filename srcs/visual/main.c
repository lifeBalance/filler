/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:37:24 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/10 17:40:15 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc visual.c -Iincludes -Ilibft/includes -L../libft -lft -lncurses
#include <ncurses.h>
#include <fcntl.h>
#include "visual.h"
#include "libft.h"

static void	print_banner(WINDOW *w, t_visualizer *v);
static void	print_board(WINDOW *w, t_visualizer *v);
static int	find_line(int fd, char **ln, const char *str);

// void	parse_banner(t_visualizer *v);
// WINDOW	*new_box(int height, int width, int start_y, int start_x);

int	main(void)
{
	t_visualizer	v;
	WINDOW			*w_banner;
	WINDOW			*w_board;

	// v.fd = STDIN_FILENO;
	v.b_rows = 15;
	v.b_cols = 17;

	// parse_banner(&v);
	// parse_playas (names and numbers)
	// parse size of board
	// parse board
	initscr();
	init_colors();

	w_banner = newwin(BANNER_HEIGHT, BANNER_WIDTH, 0, 0);
	w_board = newwin(v.b_rows + 2, v.b_cols + 4, BANNER_HEIGHT + 1, 0);
	print_banner(w_banner, &v);
	print_board(w_board, &v);
	// addstr("Hello world\n");
	// print the banner in ncurses
	// print the playas in ncurses
	// print the size in ncurses
	// print the board in ncurses
	refresh();
	// getch();
	endwin();
	return (0);
}

void	print_banner(WINDOW *w, t_visualizer *v)
{
	int	i;

	v->fd = open("banner.txt", O_RDONLY);
	i = 0;
	while (i < BANNER_HEIGHT)
	{
		get_next_line(v->fd, &v->line);
		mvwprintw(w, i, 0, "%s", v->line);
		ft_strdel(&v->line);
		i++;
	}
	wrefresh(w);
	// wgetch(w);
	close(v->fd);
}

void	print_board(WINDOW *w, t_visualizer *v)
{
	int	i;

	v->fd = open("output", O_RDONLY);
	while (find_line(v->fd, &v->line, BOARD_SIZE_LN) == 0)
	{
		i = 0;
		while (1)
		{
			colorize_board(w, v->line, i);
			ft_strdel(&v->line);
			if (i > v->b_rows + 2)
				break ;
			get_next_line(v->fd, &v->line);
			i++;
		}
		usleep(500000);
		wrefresh(w);
	}
	wgetch(w);
	close(v->fd);
}

static int	find_line(int fd, char **ln, const char *str)
{
	int		ret;

	ret = get_next_line(fd, ln);
	while (ret > 0)
	{
		if (ft_strstr(*ln, str))
			return (0);
		else
		{
			ft_strdel(ln);
			ret = get_next_line(fd, ln);
		}
	}
	return (-1);
}

// void	parse_banner(t_visualizer *v)
// {
// 	int	i;

// 	v->fd = open("banner.txt", O_RDONLY);
// 	i = 0;
// 	while (i < BANNER_HEIGHT)
// 	{
// 		ft_strncpy(v->banner[i], v->line, BANNER_WIDTH);
// 		printf("yo\n");
// 		i++;
// 	}
// }

// WINDOW	*new_box(int height, int width, int start_y, int start_x)
// {
// 	WINDOW *local_win;

// 	local_win = newwin(height, width, start_y, start_x);
// 	box(local_win, 0 , 0);
// 	wrefresh(local_win);
// 	return (local_win);
// }