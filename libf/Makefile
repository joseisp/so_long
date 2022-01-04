# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 00:03:19 by jinacio-          #+#    #+#              #
#    Updated: 2021/12/14 01:30:40 by jinacio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libf.a

FT = libf_initialize.c libf_secondary.c libf.c

OBJ = $(FT:.c=.o)

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	${GCC} ${CFLAGS} -c ${FT}
	ar rc $(NAME) ${OBJ}

clean:
	rm -f *.o

fclean:	clean
	rm -f ${NAME}

re:	fclean all