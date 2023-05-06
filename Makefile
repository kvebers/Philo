# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 12:20:09 by kvebers           #+#    #+#              #
#    Updated: 2023/05/06 10:50:03 by kvebers          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CFLAGS	= -Wall -Wextra -Werror -pthread -g
CC		= cc
SRC	=	src/philo.c \
		src/free.c \
		src/routine.c \
		src/controll_loop.c \
		src/time.c \
		utils/utils.c \
		utils/philo_utils.c \
		init/init_values.c \
		init/init_mutex.c \
		init/init_philos.c \
		1_philo/1_philo.c
RM = 		rm -f
SRC_O	= $(SRC:%.c=%.o)

all:  $(NAME)

$(NAME): $(SRC_O)
	$(CC) $(CFLAGS) $(SRC_O) -o $(NAME)

clean:
	- @$(RM) $(SRC_O)

fclean: clean
	- @$(RM) ${NAME}

re: fclean all

.PHONY: clean fclean all re
