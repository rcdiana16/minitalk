/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:52:32 by diana             #+#    #+#             */
/*   Updated: 2025/02/15 20:51:21 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

NAME_SERVER = server
NAME_CLIENT = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = server.c \
	   client.c \

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean
	
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	
re: fclean $(NAME)

.PHONY: clean fclean re