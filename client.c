/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:52:24 by diana             #+#    #+#             */
/*   Updated: 2025/02/16 15:28:05 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	send_signals(int pid, char *message)
{
	int				character;
	int				i;

	character = 0;
	while (message[character])
	{
		i = -1;
		while (++i < 8)
		{
			if (((unsigned char)(message[character] >> (7 - i)) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((unsigned char)(message[character] >> (7 - i)) & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(50);
		}
		character++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	char				*message;
	int					server_id;

	if (argc == 3)
	{
		server_id = ft_atoi(argv[1]);
		if (!server_id)
		{
			ft_printf("ERROR");
			return (0);
		}
		message = argv[2];
		if (message[0] == 0)
		{
			ft_printf("You did not send anything. Send something\n");
			return (0);
		}
		send_signals(server_id, message);
	}
	else
		ft_printf("ERROR. Follow this order: ./client <PID> <MESSAGE>\n");
	return (0);
}
