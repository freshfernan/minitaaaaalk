/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:36:33 by fefernan          #+#    #+#             */
/*   Updated: 2022/10/14 14:32:39 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	handler_sigusr2(int signum)
{
	(void)signum;
	printf("0");
}

void	handler_sigusr1(int signum)
{
	(void)signum;
	printf("1");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	signal(SIGUSR1, handler_sigusr1);
	signal(SIGUSR2, handler_sigusr2);
	while (1)
		pause();
	return (0);
}
