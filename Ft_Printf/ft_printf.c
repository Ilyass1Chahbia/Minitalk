/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:12:23 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/03/03 14:33:50 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_f(char f, va_list arg)
{
	int	count;

	count = 0;
	if (f == '%')
		count += ft_putchar('%');
	else if (f == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (f == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (f == 'd' || f == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (f == 'u')
		count += ft_printunsigned(va_arg(arg, unsigned int));
	else if (f == 'p')
		count += ft_printptr(va_arg(arg, void *));
	else if (f == 'x' || f == 'X')
		count += ft_printhex(va_arg(arg, unsigned int), f);
	return (count);
}

int	ft_printf(const char *f, ...)
{
	va_list	arg;
	int		count;

	va_end(arg);
	count = 0;
	va_start(arg, f);
	while (*f != '\0')
	{
		if (write(1, "", 0) < 0)
			return (-1);
		if (*f == '%')
			count = count + print_f(*(++f), arg);
		else
			count = count + write(1, f, 1);
		f++;
	}
	return (count);
}
