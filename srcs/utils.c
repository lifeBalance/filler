/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:07:35 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/09 18:21:58 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

/*
**	It fast-forwards to the line which contains its 'str' argument.
**	Return values:
**		- If the line is found, 1.
**		- If the line is NOT found, 0.
*/
int	find_line(char **ln, const char *str)
{
	int		ret;

	if (!(*ln))
		ft_strdel(ln);
	ret = get_next_line(STDIN_FILENO, ln);
	while (ret > 0)
	{
		if (ft_strstr(*ln, str))
			return (1);
		else
		{
			ft_strdel(ln);
			ret = get_next_line(STDIN_FILENO, ln);
		}
	}
	return (0);
}

/*
**	It skips a given number of lines, freeing allocated lines along the way.
*/
int	skip_lines(char **str, int n)
{
	if (!(*str))
		ft_strdel(str);
	while (n--)
	{
		if (get_next_line(STDIN_FILENO, str) <= 0)
			return (-1);
		ft_strdel(str);
	}
	return (1);
}

/*
**	It prints the token and releases it when done. It doesn't return anything.
*/
void	print_char2darr(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
}

char **alloc_char_2darr(int rows, int cols)
{
	char **arr;
	int i;

	arr = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!arr)
		return (0);
	ft_memset(arr, 0, sizeof(char *) * (rows + 1));
	i = 0;
	while (i < rows)
	{
		arr[i] = ft_strnew(cols);
		if (!arr[i])
		{
			free_char_2darr(arr);
			return (0);
		}
		i++;
	}
	arr[i] = 0;
	return (arr);
}

void	free_char_2darr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(arr + i);
		i++;
	}
	ft_memdel((void **)arr);
}
