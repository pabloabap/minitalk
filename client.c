/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:58:08 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/01/10 20:19:01 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
#include <signal.h>

static void	bit_sender(int pid, char c)
{
	int	n;

	n = 7;
	while (n >= 0)
	{
		if (c >> n & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(-1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(-1);
		}
		usleep(50);
		n--;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[2][i])
		{
			if (ft_atoi(argv[1]) < 2)
			{
				ft_printf("ERROR! Indique process ID del servidor\n");
				exit(-1);
			}
			bit_sender(ft_atoi(argv[1]), argv[2][i]);
			i++;
		}
	}
	else
	{
		ft_printf("ERROR! Args: process ID servidor y char/string\n");
		exit(-1);
	}
	return (0);
}
