/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diramire <diramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:33:16 by diana             #+#    #+#             */
/*   Updated: 2024/10/14 12:49:02 by diramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_d(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -(long)n;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*fill_up(long n, char *result, long nb_cases)
{
	while (nb_cases > 0)
	{
		result[nb_cases - 1] = n % 10 + '0';
		n = n / 10;
		nb_cases--;
	}
	return (result);
}

static char	*fill_up_neg(long long n, char *result, long nb_cases)
{
	result[0] = '-';
	n = -n;
	while (nb_cases - 1 > 0)
	{
		result[nb_cases - 1] = n % 10 + '0';
		n = n / 10;
		nb_cases--;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	nb_cases;
	long	num;

	num = n;
	nb_cases = count_d(num);
	if (num == -2147483648)
	{
		result = malloc(sizeof(char) * 12);
		if (!result)
			return (NULL);
		ft_strlcpy(result, "-2147483648", 13);
		return (result);
	}
	result = malloc(sizeof(char ) * (nb_cases + 1));
	if (!result)
		return (NULL);
	result[nb_cases] = '\0';
	if (n < 0)
		fill_up_neg(num, result, nb_cases);
	else
		fill_up(num, result, nb_cases);
	return (result);
}
