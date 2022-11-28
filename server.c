/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:36:33 by fefernan          #+#    #+#             */
/*   Updated: 2022/11/28 19:42:23 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_error(int pid, char *str)
{
	if (str)
		free(str);
	ft_putstr_fd("server: error inesperado.\n", 2);
	kill(pid, SIGUSR2);
	exit(EXIT_FAILURE);
}

char	*add_char_str(char *str, char c)
{
	char	*add;
	int		i;

	add = NULL;
	if (!c)
		return (NULL);
	if (!str)
	{
		add = (char *)malloc(sizeof(char) * 2);
		if (!add)
			return (NULL);
		return (add[0] = c, add[1] = '\0', add);
	}
	add = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!add)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (str[++i])
		add[i] = str[i];
	free(str);
	return (add[i++] = c, add[i] = '\0', add);
}

char	*poner_string(char *mensaje)
{
	ft_putstr_fd(mensaje, 1);
	free(mensaje);
	return (NULL);
}

void	controlador_sen(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bits = 0;
	static int	pid = 0;
	static char	*mensaje;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c |= 0x80 >> bits;
	if (++bits == 8)
	{
		if (c)
			mensaje = add_char_str(mensaje, c);
		else
			mensaje = poner_string(mensaje);
		bits = 0;
		c = 0xFF;
	}
	if (kill(pid, SIGUSR1) == -1)
		ft_error(pid, mensaje);
}

int	main(void)
{
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = controlador_sen;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
}
