/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:08:45 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/11 18:07:32 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "visual.h"

int	find_line(int fd, char **ln, const char *str)
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

int	skip_lines(t_visualizer *v, int n)
{
	v->fd = STDIN_FILENO;
	while (get_next_line(v->fd, &v->line) > 0)
	{
		ft_strdel(&v->line);
		n--;
		if (n == 0)
			return (0);
	}
	return (-1);
}
