/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_idu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:58:12 by diana             #+#    #+#             */
/*   Updated: 2024/12/14 10:28:07 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(long long nb)
{
	int		count;
	char	c;

	count = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		nb *= -1;
		count++;
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		if (count == -1)
			return (-1);
	}
	c = nb % 10 + 48;
	if (write(1, &c, 1) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_put_u(unsigned int nb)
{
	int	count;
	int	c;

	count = 0;
	if (nb >= 10)
	{
		count += ft_put_u(nb / 10);
		if (count == -1)
			return (-1);
	}
	c = nb % 10 + 48;
	if (write(1, &c, 1) == -1)
		return (-1);
	count++;
	return (count);
}
