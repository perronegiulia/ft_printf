/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maia <maia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:35:54 by gmaia-pe          #+#    #+#             */
/*   Updated: 2023/10/17 12:32:21 by maia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += ft_print_format(*(++format), ap);
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
