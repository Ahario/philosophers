# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 15:41:15 by hyeo              #+#    #+#              #
#    Updated: 2022/07/27 15:41:16 by hyeo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = philo_atoi.c philo_error.c philo_utils.c philo_utils2.c\
		philo_utils3.c philo.c
OBJS = ${SRCS:.c=.o}
CC    = gcc
CFLAGS	= -Wextra -Wall -Werror -g
#CFLAGS += -g -fsanitize=address
NAME	= philo
.c.o:		&{CC} &{CFLAGS} -c -o $@ $<

${NAME} : ${OBJS}
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all:  ${NAME}

clean:
	 rm -f ${OBJS}
	
fclean :	clean
	rm -f ${NAME}

re : fclean all clean

leaks: 
	leaks -atExit -- ./pipex

.PHONY: all bonus clean fclean re
