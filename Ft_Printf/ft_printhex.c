/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:43:45 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/03/03 14:32:24 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int n, const char f)
{
	char	nmr;
	int		count;

	count = 0;
	if (n >= 16)
	{
		count += ft_printhex((n / 16), f);
		count += ft_printhex((n % 16), f);
	}
	else
	{
		if (n <= 9)
			nmr = n + 48;
		else
		{
			if (f == 'x')
				nmr = n - 10 + 97;
			else if (f == 'X')
				nmr = n - 10 + 65;
		}
		count += write(1, &nmr, 1);
	}
	return (count);
}
