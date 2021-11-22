# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-b <alopez-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 20:34:28 by alopez-b          #+#    #+#              #
#    Updated: 2021/11/15 20:04:01 by alopez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
		ft_printf_utils.c

OBJS	= $(SRCS:.c=.o)

rm	= rm -f

CC = gcc

CFLAGS	= -Wall -Wextra -Werror -DDEBUG

NAME 	= ft_printf.a

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