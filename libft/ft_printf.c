/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:02:07 by diana             #+#    #+#             */
/*   Updated: 2024/12/14 10:28:16 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_percent(char const format, va_list *args)
{
	int	result;

	result = 0;
	if (format == 'c')
		result += ft_putchar(va_arg(*args, int));
	if (format == 's')
		result += ft_putstr(va_arg(*args, char *));
	if (format == 'd' || format == 'i')
		result += ft_putnbr(va_arg(*args, int));
	if (format == 'p')
		result += ft_putptr(va_arg(*args, uintptr_t));
	if (format == 'x')
		result += ft_puthexa(va_arg(*args, unsigned int), format);
	if (format == 'X')
		result += ft_puthexa(va_arg(*args, unsigned int), format);
	if (format == 'u')
		result += ft_put_u(va_arg(*args, unsigned int));
	if (format == '%')
		result += ft_putchar('%');
	return (result);
}

static int	parse_format(char const *format, va_list args)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			result += handle_percent(format[i], &args);
			if (result == -1)
				return (-1);
		}
		else
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
			result++;
		}
		i++;
	}
	return (result);
}

int	ft_printf(char const *format, ...)
{
	int		result;
	va_list	args;

	result = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	result = parse_format(format, args);
	va_end(args);
	return (result);
}
