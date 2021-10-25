# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 19:38:12 by icastell          #+#    #+#              #
#    Updated: 2021/10/14 14:21:30 by icastell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

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

#OBJS_BONUS =	$(SRCS_BONUS:.c=.o)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

$(OBJS):	$(SRCS)
			gcc $(FLAGS) -c $(SRCS)

test:
		gcc -g -I. main.c $(SRCS) -o a.out
		./a.out

all:	$(NAME)

#bonus:	$(OBJS) $(OBJS_BONUS)
#		ar rcs $(NAME) $(OBJS_BONUS) $(OBJS_BONUS)

clean:
		rm -f $(OBJS)
#		rm -f $(OBJS_BONUS)

fclean:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re