/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:06:57 by icastell          #+#    #+#             */
/*   Updated: 2021/10/14 14:27:23 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_find_type(t_print *printab, const char *str, const int pos)
{
	char	*type;

	type = ft_strchr(TYPES, str[pos]);
	if (type != NULL)
		printab->type = ((int)*type);
}

void	ft_print_cases(t_print *printab)
{
	if (printab->type == 'c')
		ft_print_c(printab);
	else if (printab->type == 's')
		ft_print_s(printab);
	else if (printab->type == 'p')
		ft_print_p(printab);
	else if (printab->type == 'd' || printab->type == 'i')
		ft_print_di(printab);
	else if (printab->type == 'u')
		ft_print_u(printab);
	else if (printab->type == 'x' || printab->type == 'X')
		ft_print_x(printab);
	else if (printab->type == '%')
	{
		ft_putchar_fd('%', 1);
		printab->total_length++;
	}
	return ;
}

static int	ft_to_print(t_print *printab, const char *str, const int pos)
{
	ft_find_type(printab, str, pos);
	if (printab->type != 0)
		ft_print_cases(printab);
	else
		printab->total_length += ft_putchar_fd(str[pos], 1);
	return (pos);
}

static t_print	*ft_initialize(t_print *printab)
{
	printab->width = 0;
	printab->type = 0;
	printab->total_length = 0;
	return (printab);
}

int	ft_printf(const char *last, ...)
{
	t_print		*printab;
	int			cnt;
	int			i;

	if (!last || !*last)
		return (0);
	printab = (t_print *)ft_calloc(1, sizeof(t_print));
	if (!printab)
		return (-1);
	ft_initialize(printab);
	va_start(printab->args, last);
	cnt = 0;
	i = -1;
	while (last[++i])
	{
		if (last[i] == '%')
			i = ft_to_print(printab, last, i + 1);
		else
			printab->total_length += ft_putchar_fd(last[i], 1);
	}
	cnt = printab->total_length;
	va_end(printab->args);
	free(printab);
	return (cnt);
}
