/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:58:16 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/01/10 20:05:44 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "./libft/libft.h"

void	signal_handler(int signum);

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	ft_printf("%d\n", getpid());
	while (1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			exit(-1);
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			exit(-1);
		pause();
	}
	return (0);
}

void	signal_handler(int signum)
{
	static int	bit_index = 7;
	static int	g_char = 0;

	if (signum == SIGUSR1)
		g_char = g_char | (1 << bit_index);
	else if (signum == SIGUSR2)
		g_char = g_char | (0 << bit_index);
	bit_index --;
	if (bit_index < 0)
	{
		if (write(1, &g_char, 1) == -1)
			exit(-1);
		bit_index = 7;
		g_char = 0;
	}
}
