/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pxx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:07:09 by diana             #+#    #+#             */
/*   Updated: 2024/12/14 10:28:12 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexa(unsigned int nb, char format)
{
	int		count;
	char	c;
	char	*base;

	count = 0;
	if (nb >= 16)
	{
		count += ft_puthexa(nb / 16, format);
		if (count == -1)
			return (-1);
	}
	if (format == 'x')
		base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	c = base[nb % 16];
	if (write(1, &c, 1) == -1)
		return (-1);
	count++;
	return (count);
}

static int	print_prefix(void)
{
	if (write(1, "0x", 2) == -1)
		return (-1);
	return (2);
}

static int	print_hex(uintptr_t nb)
{
	int		count;
	char	*base;
	char	c;

	count = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		count += print_hex(nb / 16);
		if (count == -1)
			return (-1);
	}
	c = base[nb % 16];
	if (write(1, &c, 1) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_putptr(uintptr_t nb)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		return (3);
	}
	count += print_prefix();
	if (count == -1)
		return (-1);
	count += print_hex(nb);
	if (count == -1)
		return (-1);
	return (count);
}
