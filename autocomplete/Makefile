##
## Makefile for Makefile in /home/zimmer_n
## 
## Made by Nicolas Zimmermann
## Login   <zimmer_n@epitech.net>
## 
## Started on  Fri Nov 13 15:25:22 2015 Nicolas Zimmermann
## Last update Wed May 25 18:03:49 2016 Nicolas Zimmermann
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -W -Wall -Werror -Wextra
CFLAGS	+= -I./include -I../lib/libmy/include -I../lib/libmy/include -I../lib/libmy_printf/include
CFLAGS	+= -L../lib/libmy -lmy -L../lib/libmy_printf -lmy_printf -lncurses

NAME   	= autocomplete

SRCS	= main.c \
	list/file_list.c \
	list/free_list.c \
	list/show_list.c \
	OM42sh/OM42sh.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
