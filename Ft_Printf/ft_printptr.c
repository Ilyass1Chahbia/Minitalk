/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:34:09 by ilchahbi          #+#    #+#             */
/*   Updated: 2023/12/21 20:49:48 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(unsigned long n)
{
	int		count;
	char	nmr;

	count = 0;
	if (n >= 16)
	{
		count += ft_putptr(n / 16);
		count += ft_putptr(n % 16);
	}
	else
	{
		if (n <= 9)
			nmr = n + 48;
		else
			nmr = n - 10 + 97;
		count += write(1, &nmr, 1);
	}
	return (count);
}

int	ft_printptr(void *ptr)
{
	int				len;
	unsigned long	n;

	len = 2;
	n = (unsigned long)ptr;
	write(1, "0x", 2);
	return (ft_putptr(n) + len);
}
