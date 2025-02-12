/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 21:24:48 by diana             #+#    #+#             */
/*   Updated: 2024/10/04 21:26:21 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_d;
	unsigned char	*temp_s;

	if (!dst && !src)
	{
		return (NULL);
	}
	temp_d = (unsigned char *) dst;
	temp_s = (unsigned char *) src;
	while (n > 0)
	{
		*(temp_d++) = *(temp_s++);
		n--;
	}
	return (dst);
}
