/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:34:02 by gmaia-pe          #+#    #+#             */
/*   Updated: 2023/10/16 23:56:51 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	print_digit(long n, char *base, char specifier)
{
	int		count;
	int		base_len;

	base_len = ft_strlen(base);
	if (specifier == 'u')
		n = (unsigned int)n;
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base, specifier) + 1);
	}
	else if (n < base_len)
		return (print_char(base[n]));
	else
	{
		count = print_digit(n / base_len, base, specifier);
		return (count + print_digit(n % base_len, base, specifier));
	}
}
