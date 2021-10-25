/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:49:51 by icastell          #+#    #+#             */
/*   Updated: 2021/10/14 14:27:33 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

# define TYPES "cspdiuxX%"
# define HEXADECIMAL "0123456789abcdef"

typedef struct s_print
{
	va_list	args;
	int		width;
	int		type;
	int		total_length;
}			t_print;

int		ft_printf(const char *last, ...);
char	*ft_strchr(const char *str, int c);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *str);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_hextoa(unsigned int n, size_t is_upper);
char	*ft_hexltoa(unsigned long n);
void	ft_bzero(void *ptr, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_print_cases(t_print *printab);
void	ft_print_c(t_print *printab);
void	ft_print_s(t_print *printab);
void	ft_print_p(t_print *printab);
void	ft_print_di(t_print *printab);
void	ft_print_u(t_print *printab);
void	ft_print_x(t_print *printab);

#endif