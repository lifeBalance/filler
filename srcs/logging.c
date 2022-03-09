/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/09 13:49:05 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "logging.h"

void	flog(int fd, const char *s)
{
	write(fd, s, ft_strlen(s));
}

void	flog_char_matrix(int fd, char **str, int rows, int cols)
{
	int		i;
	int		j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			write(fd, str[i] + j, 1);
			j++;
		}
		write(fd, "\n", 1);
		i++;
	}
}

void	flog_heatmap(int fd, int **arr, int rows, int cols)
{
	int		i;
	int		j;
	char	ch;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (arr[i][j] < 0)
				ch = '0';
			else
				ch = arr[i][j] + '0';
			write(fd, &ch, 1);
			j++;
		}
		write(fd, "\n", 1);
		i++;
	}
}

void	flog_playa(int fd, char playa)
{
	write(fd, "Our playa: ", ft_strlen("Our playa: "));
	write(fd, &playa, 1);
	write(fd, "\n", 1);
}

void	flog_size(int fd, const char *str, int rows, int cols)
{
	char	*n;
	write(fd, str, ft_strlen(str));
	n = ft_itoa(rows);
	write(fd, n, ft_strlen(n));
	ft_strdel(&n);
	write(fd, " ", 1);
	n = ft_itoa(cols);
	write(fd, n, ft_strlen(n));
	ft_strdel(&n);
	write(fd, "\n", 1);
}
