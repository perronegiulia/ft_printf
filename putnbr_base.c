/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 23:54:24 by gmaia-pe          #+#    #+#             */
/*   Updated: 2023/10/16 23:59:19 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_base(long n, char *base, char specifier)
{
	int	count;
	int	base_len;

	base_len = ft_strlen(base);
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (putnbr_base(-n, base, specifier) + 1);
	}
	else if (n < base_len)
		return (print_char(base[n]));
	else
	{
		count = putnbr_base(n / base_len, base, specifier);
		return (count + putnbr_base(n % base_len, base, specifier));
	}
}
