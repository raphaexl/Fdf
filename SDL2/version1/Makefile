# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 22:15:58 by ebatchas          #+#    #+#              #
#    Updated: 2018/12/16 13:09:25 by ebatchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

SRCDIR=srcs
LIBDIR=libs
HEADDIR=includes
CFLAGS=-Wall -Wextra -I$(HEADDIR)
LDFLAGS= $(CFLAGS) -I$(HEADDIR) -L$(LIBDIR)/ -lft -lm -lSDL2main \
		 -lSDL2

SRC=$(SRCDIR)/main.c\
	$(SRCDIR)/input.c\
	$(SRCDIR)/utils.c\
	$(SRCDIR)/tools.c\
	$(SRCDIR)/read_file.c\
	$(SRCDIR)/draw.c\
	$(SRCDIR)/draw_sdl.c\
	$(SRCDIR)/init_sdl.c

OBJ=$(LIBDIR)/main.o\
	$(LIBDIR)/input.o\
	$(LIBDIR)/utils.o\
	$(LIBDIR)/tools.o\
	$(LIBDIR)/read_file.o\
	$(LIBDIR)/draw.o\
	$(LIBDIR)/draw_sdl.o\
	$(LIBDIR)/init_sdl.o

NAME=fdf

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBDIR)/libft/ fclean && make -C $(LIBDIR)/libft
	cp $(LIBDIR)/libft/libft.a $(LIBDIR)/
	$(CC) $(LDFLAGS) -o $@ $^

$(LIBDIR)/%.o:$(HEADDIR)/%.h

$(LIBDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY:clean fclean

clean:
	rm -rf $(LIBDIR)/*.o
	make -C $(LIBDIR)/libft clean

fclean:clean
	rm -rf $(NAME)
	make -C $(LIBDIR)/libft fclean

re : fclean all
