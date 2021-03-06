/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_numeric_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/02 17:21:46 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "pf_numeric.h"

static void
put_n(unsigned long long n, char *digits, unsigned long long base, int *ret);

/*
**	It prints it unsigned long long integer argument in the base given by
**	its 'digits' string argument. It returns the number of characters written.
*/
int	put_ull_base(unsigned long long n, char *digits)
{
	unsigned long	base;
	int				ret;

	base = 0;
	ret = 0;
	while (digits[base])
		base++;
	put_n(n, digits, base, &ret);
	return (ret);
}

/*
**	Recursively prints it unsigned long long integer argument in the base
**	given by its 'digits' string argument. It returns the number of characters
**	written.
*/
static void
	put_n(unsigned long long n, char *digits, unsigned long long base, int *ret)
{
	if (n >= base)
		put_n(n / base, digits, base, ret);
	*ret += ft_putchar(*(digits + (n % base)));
}

/*
**	Returns the amount of digits of the 'unsigned long long int' argument,
**	in the given 'unsigned long long' base.
*/
int	amount_digits(long long n, t_spec *spec)
{
	int			ret;
	long long	base;

	if (spec->specifier == OCTAL)
		base = 8;
	else if (spec->specifier == LOWHEX || spec->specifier == UPPHEX || \
		spec->specifier == ADDRESS)
		base = 16;
	else
		base = 10;
	ret = 1;
	if (n < 0)
		n = -n;
	while (n >= base)
	{
		n /= base;
		ret++;
	}
	return (ret);
}

/*
**	Prints a string argument 'n' times.
**	Returns the amount of characters (bytes) written.
*/
int	putstr_repeat(char *s, int n)
{
	int	ret;

	ret = 0;
	while (n > 0)
	{
		ret += ft_putstr(s);
		n--;
	}
	return (ret);
}

/*
**	Cancels flags in the 'spec' structure:
**	- A '-' overrides a '0' if both are given.
**	- A '+' overrides a ' ' (space flag) if both are used.
*/
void	cancel_flags(t_spec *spec)
{
	if (test_bit(ZERO, spec->flags) && test_bit(MINUS, spec->flags))
		clear_bit(ZERO, &spec->flags);
	if (test_bit(PLUS, spec->flags) && test_bit(SPACE, spec->flags))
		clear_bit(SPACE, &spec->flags);
}
