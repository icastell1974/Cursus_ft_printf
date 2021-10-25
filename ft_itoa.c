/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:55:04 by icastell          #+#    #+#             */
/*   Updated: 2021/10/01 18:45:27 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The ft_itoa() function converts the initial int n to a NULL terminated
string. Each digit occupies one position in the string.*/

#include "ft_printf.h"

static char	ft_getdigit(long int n)
{
	size_t	digit;

	digit = n % 10;
	return (digit + '0');
}

static void	ft_strset(char *str, size_t len, int n)
{
	size_t		i;
	long int	nb;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		while (i < len)
		{
			str[len - (i++)] = ft_getdigit(nb * -1);
			nb = nb / 10;
		}
	}
	else
	{
		while (i < len)
		{
			str[len - (++i)] = ft_getdigit(nb);
			nb = nb / 10;
		}
	}
	return ;
}

static size_t	ft_lenint(int n)
{
	size_t		i;
	long int	nb;

	i = 1;
	nb = n;
	if (nb < 0)
		nb = nb * -1;
	while (nb >= 10)
	{	
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	len = ft_lenint(n);
	if (n < 0)
	{
		str = ft_calloc(len + 2, sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '-';
	}
	else
	{
		str = ft_calloc(len + 1, sizeof(char));
		if (!str)
			return (NULL);
	}
	ft_strset(str, len, n);
	return (str);
}
