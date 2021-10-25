/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:48:46 by icastell          #+#    #+#             */
/*   Updated: 2021/10/04 20:37:39 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *ptr, size_t n)
{
	size_t			i;
	unsigned char	*aux;

	if (n != 0)
	{
		aux = (unsigned char *)ptr;
		i = 0;
		while (i < n)
		{
			aux[i] = '\0';
			i++;
		}
	}
	return ;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
