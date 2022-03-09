/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/09 20:01:22 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "logging.h"

void	flog_char_matrix(FILE *fd, char **str, int rows, int cols, const char *s)
{
	int		i;
	int		j;

	fprintf(fd, "<--- %s [%d %d] --->\n", s, rows, cols);
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			fprintf(fd, "%c", str[i][j]);
			j++;
		}
		fprintf(fd, "\n");
		i++;
	}
}

void	flog_heatmap(FILE *fd, int **arr, int rows, int cols)
{
	int		i;
	int		j;

	fprintf(fd, "<--- Heatmap --->\n");
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			fprintf(fd, "%4d", arr[i][j]);
			j++;
		}
		fprintf(fd, "\n\n");
		i++;
	}
}
