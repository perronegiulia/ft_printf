/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:36:39 by gmaia-pe          #+#    #+#             */
/*   Updated: 2023/10/16 21:36:41 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		print_format(char specifier, va_list ap);
int		print_digit(long n, int base, char specifier);
int		print_char(int c);
int		print_str(char *str);
int		ft_printptr(size_t n);

#endif
