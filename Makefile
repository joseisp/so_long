# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 22:30:43 by jinacio-          #+#    #+#              #
#    Updated: 2021/12/14 03:11:08 by jinacio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

MINILIBX = -lmlx -lXext -lX11

PATHLIB = ./libf

LIBF = ./libf/libf.a

SRCDIR = src
OBJDIR = obj

COMPILE = main.c get_next_line.c get_next_line_utils.c \
so_long.h hooks.c walk.c colect.c check_map.c \
getting_map.c getting_position.c validate.c walk_aux.c \
check_error.c

SRC = $(addprefix $(SRCDIR)/, $(COMPILE))
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

TAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJDIR) $(OBJ)
		make -C libf
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MINILIBX) $(LIBF)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
				$(CC) $(CFLAGS) -c $< -o $@	-I./src -I./libf

$(OBJDIR):
		mkdir -p $(OBJDIR)

clean:
		make clean -C libf
		rm -rf $(OBJDIR)

fclean: clean
		rm -f $(NAME)
		make fclean -C libf

re: fclean all