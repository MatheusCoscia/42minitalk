/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrodri <matrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:08:54 by matrodri          #+#    #+#             */
/*   Updated: 2021/10/26 21:19:09 by matrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static int	ft_intsize(int n)
{
	size_t	i;

	if (n > 0)
		i = 0;
	else
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	size = ft_intsize(n);
	str = ft_calloc(size, sizeof(char));
	if (n == -2147483648)
		return (ft_strncpy(str, "-2147483648\0", 12));
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	str[size--] = '\0';
	while (n > 0)
	{
		str[size--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
