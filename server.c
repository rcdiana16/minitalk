/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:52:28 by diana             #+#    #+#             */
/*   Updated: 2025/02/15 21:10:36 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
//#include "minitalk.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

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
