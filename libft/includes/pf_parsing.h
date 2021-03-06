/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:19:30 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/05 11:56:06 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PARSING_H
# define PF_PARSING_H

/*
**	Function prototypes:
*/
int		pf_parse_digits(char **fmt, t_spec *spec);
void	handle_star(char **fmt, va_list args, t_spec *spec);
void	handle_double_flag(int flag, int dbl_flag, t_spec *spec);

#endif