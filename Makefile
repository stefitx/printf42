# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 05:04:24 by atudor            #+#    #+#              #
#    Updated: 2023/10/21 16:51:57 by atudor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_putstr_utils.c ft_numbers.c ft_hex_and_ptr.c

SRCSBONUS = #
 			
OBJS = ${SRCS:.c=.o}
OBJSBONUS = ${SRCSBONUS:.c=.o}

NAME = libftprintf.a
HEADER = ft_printf.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g


# Implicit method
%.o:%.c 	$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@


# My methods
all: 		${NAME}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

#bonus:		${OBJS} ${OBJSBONUS}
#			ar rcs ${NAME} ${OBJS} ${OBJSBONUS}
#			@touch bonus

clean: 		
			${RM} ${OBJS} ${OBJSBONUS}

fclean: 	clean
			${RM} ${NAME}
			${RM} bonus

re:			fclean all

.PHONY: all clean fclean re
