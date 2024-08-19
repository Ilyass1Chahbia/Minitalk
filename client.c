/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:27:25 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/05/15 13:25:48 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	long_n(unsigned long int n, int neg, int j)
{
	int	nb;

	nb = n;
	if (nb == -2147483648)
		return (-2147483648);
	if (j >= 20 && neg > 0)
		return (-1);
	if (n > ULONG_MAX && neg > 0)
		return (-1);
	if (n > ULONG_MAX && neg < 0)
		return (0);
	if (j >= 20 && neg < 0)
		return (0);
	return ((int)n * neg);
}

int	ft_atoi(const char *str)
{
	int	neg;
	int	n;
	int	i;
	int	j;

	neg = 1;
	i = 0;
	j = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = n * 10 + str[i++] - 48;
		j++;
	}
	return (long_n(n, neg, j));
}

void	ft_ascii_to_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		usleep(150);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 3 || pid > 2147483647)
			return (0);
		while (argv[2][i] != '\0')
		{
			ft_ascii_to_bits(pid, argv[2][i]);
			i++;
		}
		ft_ascii_to_bits(pid, '\0');
	}
	else
	{
		ft_printf("ERROR!!!\n");
		return (0);
	}
	return (0);
}
