/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:01:57 by icastell          #+#    #+#             */
/*   Updated: 2021/10/04 20:36:38 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The ft_putstr_fd() function writes the string 's' over
the provided file descriptor.*/

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	aux;

	aux = 0;
	if (s != NULL)
		aux += write(fd, s, ft_strlen(s));
	return (aux);
}
