/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:29:45 by fefernan          #+#    #+#             */
/*   Updated: 2022/11/26 12:15:09 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_error(char *str)
{
	if (str)
		free(str);
	ft_putstr_fd("client: error inesperado.\n", 2);
	exit(EXIT_FAILURE);
}

int	enviar_nulo(int pid, char *str)
{
	static int	i = 0;

	if (i++ != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_error(str);
		return (0);
	}
	return (1);
}

int	enviar_bit(int pid, char *str)
{
	static char	*mens = 0;
	static int	s_pid = 0;
	static int	bits = 0;

	if (str)
		mens = ft_strdup(str);
	if (!mens)
		ft_error(0);
	if (pid)
		s_pid = pid;
	if (mens[bits / 8])
	{
		if (mens[bits / 8] & (0x80 >> (bits % 8)))
		{
			if (kill(s_pid, SIGUSR2) == -1)
				ft_error(mens);
		}
		else if (kill(s_pid, SIGUSR1) == -1)
			ft_error(mens);
		return (bits++, 0);
	}
	if (!enviar_nulo(s_pid, mens))
		return (0);
	return (free(str), free(mens), 1);
}

void	controlador_seniales(int signum)
{
	int	envio;

	envio = 0;
	if (signum == SIGUSR1)
		envio = enviar_bit(0, 0);
	else if (signum == SIGUSR2)
	{
		ft_putstr_fd("client: error en el servidor, cerrando. \n", 2);
		exit(EXIT_FAILURE);
	}
	if (envio)
	{
		ft_putstr_fd("client: exito en la operación. \n", 1);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3 || !ft_str_isnumeric(argv[1]))
	{
		ft_putstr_fd("client: argumentos invalidos\n", 2);
		ft_putstr_fd("\tformato correcto: ./client PID_SERVIDOR MENSAJE\n", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, controlador_seniales);
	signal(SIGUSR2, controlador_seniales);
	enviar_bit(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
