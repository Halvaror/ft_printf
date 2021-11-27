# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-b <alopez-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 20:34:28 by alopez-b          #+#    #+#              #
#    Updated: 2021/11/25 20:19:45 by alopez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
		ft_printf_utils.c \
		ft_printf_utils2.c

OBJS	= $(SRCS:.c=.o)

rm	= rm -f

CC = gcc

CFLAGS	= -Wall -Wextra -Werror -DDICK

NAME 	= libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

run:
	$(CC) $(CFLAGS) $(SRCS) 
	
clean:
	$(RM) $(OBJS) a.out

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re run