/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cases_csp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:57:14 by icastell          #+#    #+#             */
/*   Updated: 2021/10/14 14:25:28 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(t_print *printab)
{
	char	c;

	c = va_arg(printab->args, int);
	printab->total_length += ft_putchar_fd(c, 1);
	return ;
}

void	ft_print_s(t_print *printab)
{
	char	*s;

	s = va_arg(printab->args, char *);
	if (!s)
		s = "(null)";
	printab->total_length += ft_putstr_fd(s, 1);
	return ;
}

void	ft_print_p(t_print *printab)
{
	unsigned long	value;
	char			*s;

	value = (unsigned long)va_arg(printab->args, unsigned long);
	s = ft_hexltoa(value);
	if (s)
	{
		printab->total_length += ft_putstr_fd("0x", 1);
		printab->total_length += ft_putstr_fd(s, 1);
		free(s);
	}
	return ;
}
