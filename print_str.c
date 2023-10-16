/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:36:38 by gmaia-pe          #+#    #+#             */
/*   Updated: 2023/10/16 21:45:02 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (count + 6);
	}
	while (*str)
	{
		print_char((char)*str);
		count++;
		str++;
	}
	return (count);
}
