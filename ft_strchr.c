/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:57:09 by icastell          #+#    #+#             */
/*   Updated: 2021/10/01 18:51:10 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The ft_strchr() function locates the first occurrence of c (converted to
a char) in the string pointed to by str.  The terminating null character is
considered to be part of the string; therefore if c is `\0', the functions
locate the terminating `\0'. Returns a pointer to the located character,
or NULL if the character does not appear in the string.*/

#include "ft_printf.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*aux;

	i = 0;
	aux = (char *)str;
	while (aux[i] != '\0')
	{
		if (aux[i] == (char)c)
			return (&aux[i]);
		i++;
	}
	if (aux[i] == c)
		return (&aux[i]);
	else
		return (0);
}
