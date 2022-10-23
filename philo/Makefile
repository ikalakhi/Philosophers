# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 20:59:17 by ikalakhi          #+#    #+#              #
#    Updated: 2022/10/02 18:46:06 by ikalakhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c philo_errors.c philo_utils.c threads.c atoi.c philo_initialize.c

OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -pthread #-g -fsanitize=thread

all : $(NAME)
$(NAME): $(OBJS)
	cc  $(SRC) $(CFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
