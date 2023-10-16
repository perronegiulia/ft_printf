/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:35:54 by gmaia-pe          #+#    #+#             */
/*   Updated: 2023/10/17 00:06:01 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i' || specifier == 'u')
		count += print_digit((long)(va_arg(ap, int)), DECIMAL, specifier);
	else if (specifier == 'x')
		count += print_digit((long)(va_arg(ap, unsigned int)), HEXL, specifier);
	else if (specifier == 'X')
		count += print_digit((long)(va_arg(ap, unsigned int)), HEXU, specifier);
	else if (specifier == 'p')
		count += print_ptr(va_arg(ap, size_t), HEXL);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
/*
int main ()
{
  int count;
  ft_printf("Hello %s, you got this %i%% right, today is %d, 
  in hex %X, char -> %c\n", "Giulia",100, 27, 27, 'z');
	retu

  //count = ft_printf("hello %s\n", "giulia");
  //ft_printf("the char written are %d\n", count);
  count = ft_printf("%d\n", -2147483648);
  ft_printf("the chars written are %d\n", count);
  count = printf("%d\n", -2147483648);
  printf("the chars written are %d\n", count);

}
*/
