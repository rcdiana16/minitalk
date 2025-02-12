/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diramire <diramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:45:30 by diana             #+#    #+#             */
/*   Updated: 2024/10/14 12:47:28 by diramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	j = 0;
	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[j] != '\0' && j < len)
	{
		i = 0;
		ptr = (char *)(haystack + j);
		while (needle[i] != '\0' && (j + i) < len)
		{
			if (needle[i] == haystack[j + i])
				i++;
			else
				break ;
			if (needle[i] == '\0')
				return (ptr);
		}
		j++;
	}
	return (0);
}
