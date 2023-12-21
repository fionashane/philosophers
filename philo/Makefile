# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 10:37:42 by fsalimba          #+#    #+#              #
#    Updated: 2023/12/20 10:37:44 by fsalimba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= philo

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

SRCS			=	system_manager.c argument_checker.c \
					data_initialiser.c time_handler.c \
					routine_handler.c philo_handler.c \
					printing_engine.c time_access.c \
					philo_access.c fork_access.c \
					iterating_access.c data_access.c \
					philo_utility.c
OBJS			= $(SRCS:%.c=%.o)

all:				$(NAME)

%.o: %.c
					$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):		$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
					$(RM) $(OBJS)

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re