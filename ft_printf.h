/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maia <maia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:36:39 by gmaia-pe          #+#    #+#             */
/*   Updated: 2023/10/17 12:31:56 by maia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

# define DECIMAL   "0123456789"
# define HEXL "0123456789abcdef"
# define HEXU "0123456789ABCDEF"

size_t ft_strlen(const char *str);
int		ft_printf(const char *format, ...);
int		ft_print_format(char specifier, va_list ap);
int		ft_print_digit(long n, char *base, char specifier);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_ptr(size_t n, char *base);
int		ft_putnbr_base(long n, char *base, char specifier);

#endif
