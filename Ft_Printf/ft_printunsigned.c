/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:57:09 by ilchahbi          #+#    #+#             */
/*   Updated: 2023/12/21 20:49:51 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned int n)
{
	int		count;
	char	nbr;

	count = 0;
	if (n > 9)
	{
		count += ft_printunsigned(n / 10);
		count += ft_printunsigned(n % 10);
	}
	if (n >= 0 && n <= 9)
	{
		nbr = n + 48;
		count += write(1, &nbr, 1);
	}
	return (count);
}
