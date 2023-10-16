/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 23:55:24 by gmaia-pe          #+#    #+#             */
/*   Updated: 2023/10/16 23:58:09 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(size_t n, char *base)
{
	int	count;
	int	base_len;

	base_len = ft_strlen(base);
	count = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	if (n < 16)
	{
		write(1, "0x", 2);
		count += print_digit(n, base, 'x') + 2;
	}
	else
	{
		write(1, "0x", 2);
		count += print_digit(n / base_len, base, 'x') + 2;
		count += print_digit(n % base_len, base, 'x');
	}
	return (count);
}
