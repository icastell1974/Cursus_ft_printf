/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexltoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:54:53 by icastell          #+#    #+#             */
/*   Updated: 2021/10/25 13:38:08 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The ft_hexltoa() function converts the initial hexadecimal n to a NULL
terminated string. Each digit occupies one position in the string.*/

#include "ft_printf.h"

static char	ft_getdigit(unsigned long n)
{
	unsigned long	digit;

	digit = n % 16;
	return (HEXADECIMAL[digit]);
}

static void	ft_strset(char *str, size_t len, unsigned long n)
{
	size_t			i;
	unsigned long	nb;

	i = 0;
	nb = n;
	while (i < len)
	{
		str[len - (++i)] = ft_getdigit(nb);
		nb = nb / 16;
	}
	return ;
}

static size_t	ft_lenhexl(unsigned long n)
{
	size_t			i;
	unsigned long	nb;

	i = 0;
	nb = n;
	if (!n)
		i++;
	while (nb > 0)
	{	
		nb = nb / 16;
		i++;
	}
	return (i);
}

char	*ft_hexltoa(unsigned long n)
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	len = ft_lenhexl(n);
	if (len == 0)
		return (0);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strset(str, len, n);
	return (str);
}
