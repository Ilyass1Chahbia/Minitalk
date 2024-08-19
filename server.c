/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:27:33 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/02 14:46:01 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bits_to_ascii(int signal_num, siginfo_t *info, void *context)
{
	static int		bit;
	static int		i;
	static pid_t	pid_rn;

	(void) context;
	if (pid_rn != info->si_pid)
	{
		i = 0;
		bit = 0;
	}
	if (signal_num == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
	pid_rn = info->si_pid;
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	signal_fetched;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("ERROR!!!\n");
		return (0);
	}
	signal_fetched.sa_flags = SA_SIGINFO;
	signal_fetched.sa_sigaction = ft_bits_to_ascii;
	pid = getpid();
	ft_printf("%d\n", pid);
	while (argc == 1)
	{
		sigaction(SIGUSR1, &signal_fetched, NULL);
		sigaction(SIGUSR2, &signal_fetched, NULL);
		pause();
	}
	return (0);
}
