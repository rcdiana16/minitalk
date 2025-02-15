/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:52:24 by diana             #+#    #+#             */
/*   Updated: 2025/02/15 21:10:26 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
//#include "minitalk.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void send_bit(int pid, int bit) {
    if (bit == 0) {
        kill(pid, SIGUSR1);  // Enviar SIGUSR1 (bit 0)
    } else {
        kill(pid, SIGUSR2);  // Enviar SIGUSR2 (bit 1)
    }
}

void send_char(int pid, char c) {
    for (int i = 7; i >= 0; i--) {
        int bit = (c >> i) & 1;  // Extraer el bit en la posición i
        send_bit(pid, bit);  // Enviar el bit al servidor
        usleep(100);  // Espera para no sobrecargar el servidor
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        ft_printf("Uso: %s <PID del servidor> <mensaje>\n", argv[0]);
        return 1;
    }

    int server_pid = atoi(argv[1]);  // Obtener PID del servidor
    char *message = argv[2];  // Obtener el mensaje a enviar

    // Enviar cada carácter del mensaje al servidor
    for (int i = 0; message[i] != '\0'; i++) {
        send_char(server_pid, message[i]);
    }
	ft_printf("Enviando caracter nulo...\n");
	fflush(stdout);
	send_char(server_pid, '\0');
    return 0;
}
