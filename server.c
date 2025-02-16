/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:52:28 by diana             #+#    #+#             */
/*   Updated: 2025/02/16 12:54:55 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
//#include "minitalk.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int	ft_recursive_power(int nb, int power)
{
	int	res;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		res = nb * ft_recursive_power(nb, power - 1);
		return (res);
	}
}

char	*letter_to_string(char const *s1, char const letter)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	tab[j++] = letter;
	tab[j] = 0;
	free ((void *)(s1));
	return (tab);
}

void	signal_handler(int signum)
{
	static int	counter = 0;
	static int	result = 0;
	static char	*final;

	if (!final)
		final = ft_strdup("");
	if (signum == SIGUSR1)
		result = result + 0;
	else if (signum == SIGUSR2)
		result = result + (1 * ft_recursive_power(2, 7 - counter));
	counter++;
	if (counter == 8)
	{
		final = letter_to_string(final, result);
		if (result == '\0')
		{
			ft_printf("%s\n", final);
			final = NULL;
		}
		counter = 0;
		result = 0;
	}
}

int	main(void)
{
	struct sigaction	signal_received;

	ft_printf("Server's PID: %d\n", getpid());
	signal_received.sa_handler = signal_handler;
	signal_received.sa_flags = 0;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
		usleep(50);
}

/*
void signal_handler(int sig) {
	static int bit_count = 0;
    static unsigned char received_data = 0;

    if (sig == SIGUSR1)
        received_data |= (1 << (7 - bit_count));
    
    bit_count++;

    if (bit_count == 8) {
		ft_printf("Recibido: %c (%d)\n", received_data, received_data);
		fflush(stdout);

		if (received_data == '\0'){
			ft_printf("Servidor cerrando...\n");
			fflush(stdout);
			exit(0);
		}
        write(1, &received_data, 1);
        bit_count = 0;
        received_data = 0;
    }
}


int main() {
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    ft_printf("Servidor PID: %d\n", getpid());

    while (1) {
        pause();
    }

    return 0;
}
*/