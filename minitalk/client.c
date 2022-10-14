/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:29:45 by fefernan          #+#    #+#             */
/*   Updated: 2022/10/14 14:36:10 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	send_signals(char *message, int pid)
{
	int	i;
	int	shift;

	shift = -1;
	i = 0;
	while (message[i])
	{
		while (++shift < 8)
		{
			if (message [i] & 0x80 >> shift)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(3);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		printf("client: invalid arguments\n");
		printf("\tcorrect format [./%s SERVER_PID MESSAGE\n]", argv[0]);
		exit(EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	send_signals(argv[2], pid);
	return (0);
}