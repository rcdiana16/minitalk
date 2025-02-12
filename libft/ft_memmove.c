/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 22:47:33 by diana             #+#    #+#             */
/*   Updated: 2024/10/11 08:58:36 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_d;
	unsigned char	*temp_s;
	size_t			counter;

	if (!src & !dst)
		return (dst);
	if (dst > src)
	{
		temp_d = (unsigned char *) dst + len - 1;
		temp_s = (unsigned char *) src + len - 1;
		counter = len;
		while (counter--)
			*(temp_d--) = *(temp_s--);
	}
	else
	{
		temp_d = (unsigned char *) dst;
		temp_s = (unsigned char *) src;
		counter = len;
		while (counter--)
			*(temp_d++) = *(temp_s++);
	}
	return (dst);
}
