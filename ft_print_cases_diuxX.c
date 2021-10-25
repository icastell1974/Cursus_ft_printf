/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cases_diuxX.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:57:14 by icastell          #+#    #+#             */
/*   Updated: 2021/10/14 14:27:11 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_di(t_print *printab)
{
	long	value;
	char	*s;

	value = va_arg(printab->args, int);
	s = ft_itoa(value);
	printab->total_length += ft_putstr_fd(s, 1);
	free(s);
	return ;
}

void	ft_print_u(t_print *printab)
{
	long	value;
	char	*s;

	value = va_arg(printab->args, unsigned int);
	s = ft_uitoa(value);
	printab->total_length += ft_putstr_fd(s, 1);
	free(s);
	return ;
}

void	ft_print_x(t_print *printab)
{
	unsigned int	value;
	char			*s;
	size_t			is_upper;

	is_upper = 0;
	value = va_arg(printab->args, unsigned int);
	if (printab->type == 'x')
		is_upper = 0;
	else if (printab->type == 'X')
		is_upper = 1;
	s = ft_hextoa(value, is_upper);
	printab->total_length += ft_putstr_fd(s, 1);
	free(s);
	return ;
}
