/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:54:53 by icastell          #+#    #+#             */
/*   Updated: 2021/10/05 18:23:25 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The ft_hextoa() function converts the initial hexadecimal n to a NULL
terminated string. Each digit occupies one position in the string.*/

#include "ft_printf.h"

static int	ft_toupper(int c)
{
	int	upper;

	upper = c;
	if ((c >= 97) && (c <= 122))
		upper = upper - 32;
	return (upper);
}

static char	ft_getdigit(long int n, size_t is_upper)
{
	size_t	digit;
	size_t	num_hex;

	digit = n % 16;
	num_hex = HEXADECIMAL[digit];
	if (is_upper == 1)
		num_hex = ft_toupper(num_hex);
	return (num_hex);
}

static void	ft_strset(char *str, size_t len, unsigned int n, size_t is_upper)
{
	size_t		i;
	long int	nb;

	i = 0;
	nb = n;
	while (i < len)
	{
		str[len - (++i)] = ft_getdigit(nb, is_upper);
		nb = nb / 16;
	}
	return ;
}

static size_t	ft_lenhex(unsigned int n)
{
	size_t		i;
	long int	nb;

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

char	*ft_hextoa(unsigned int n, size_t is_upper)
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	len = ft_lenhex(n);
	if (len == 0)
		return (0);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strset(str, len, n, is_upper);
	return (str);
}
