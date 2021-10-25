# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icastell <icastell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 19:38:12 by icastell          #+#    #+#              #
#    Updated: 2021/10/25 16:40:22 by icastell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS =	ft_printf.c\
		ft_strchr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_strlen.c\
		ft_itoa.c\
		ft_uitoa.c\
		ft_hextoa.c\
		ft_hexltoa.c\
		ft_utils.c\
		ft_print_cases_csp.c\
		ft_print_cases_diuxX.c\

OBJS =	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

normi:
		norminette -R CheckForbiddenSourceHeader $(SRCS)

test:
		gcc -g -I. main.c $(SRCS) -o a.out
		./a.out

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re