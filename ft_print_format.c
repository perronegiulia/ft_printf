/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maia <maia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:30:27 by maia              #+#    #+#             */
/*   Updated: 2023/10/17 12:30:29 by maia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i' || specifier == 'u')
		count += ft_print_digit((long)(va_arg(ap, int)), DECIMAL, specifier);
	else if (specifier == 'x')
		count += ft_print_digit((long)(va_arg(ap, unsigned int)), HEXL,
				specifier);
	else if (specifier == 'X')
		count += ft_print_digit((long)(va_arg(ap, unsigned int)), HEXU,
				specifier);
	else if (specifier == 'p')
		count += ft_print_ptr(va_arg(ap, size_t), HEXL);
	else
		count += write(1, &specifier, 1);
	return (count);
}
