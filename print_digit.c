/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:34:02 by gmaia-pe          #+#    #+#             */
/*   Updated: 2023/10/16 21:42:26 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	print_digit(long n, int base, char specifier)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (specifier == 'u')
		n = (unsigned int)n;
	if (specifier == 'X')
		symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base, specifier) + 1);
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit(n / base, base, specifier);
		return (count + print_digit(n % base, base, specifier));
	}
}

int	ft_printptr(size_t n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	if (n < 16)
	{
		write(1, "0x", 2);
		count += print_digit(n, 16, 'x') + 2;
	}
	else
	{
		write(1, "0x", 2);
		count += print_digit(n / 16, 16, 'x') + 2;
		count += print_digit(n % 16, 16, 'x');
	}
	return (count);
}
