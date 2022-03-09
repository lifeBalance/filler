/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/09 10:08:01 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "logging.h"

void	fprint_char2darr(t_filler *f, char **str, int rows, int cols)
{
	int		i;
	int		j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			write(f->file, str[i] + j, 1);
			j++;
		}
		write(f->file, "\n", 1);
		i++;
	}
}

void	fprint_playa(t_filler *f)
{
	write(f->file, "Our playa: ", ft_strlen("Our playa: "));
	write(f->file, &(f->our_playa), 1);
	write(f->file, "\n", 1);
}

void	fprint_size(t_filler *f, const char *str, int rows, int cols)
{
	char	*n;
	write(f->file, str, ft_strlen(str));
	n = ft_itoa(rows);
	write(f->file, n, ft_strlen(n));
	ft_strdel(&n);
	write(f->file, " ", 1);
	n = ft_itoa(cols);
	write(f->file, n, ft_strlen(n));
	ft_strdel(&n);
	write(f->file, "\n", 1);
}
