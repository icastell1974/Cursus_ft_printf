/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:55:30 by icastell          #+#    #+#             */
/*   Updated: 2021/10/01 19:56:13 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The ft_uitoa() function converts the initial unsigned int n to a NULL
terminated string. Each digit occupies one position in the string.*/

#include "ft_printf.h"

static char	ft_getdigit(long int n)
{
	size_t	digit;

	digit = n % 10;
	return (digit + '0');
}

static void	ft_strset(char *str, size_t len, unsigned int n)
{
	size_t		i;
	long int	nb;

	i = 0;
	nb = n;
	while (i < len)
	{
		str[len - (++i)] = ft_getdigit(nb);
		nb = nb / 10;
	}
	return ;
}

static size_t	ft_lenuint(unsigned int n)
{
	size_t		i;
	long int	nb;

	i = 1;
	nb = n;
	while (nb >= 10)
	{	
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	len = ft_lenuint(n);
	if (len == 0)
		return (0);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strset(str, len, n);
	return (str);
}
