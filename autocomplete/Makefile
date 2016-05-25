##
## Makefile for Makefile in /home/zimmer_n
## 
## Made by Nicolas Zimmermann
## Login   <zimmer_n@epitech.net>
## 
## Started on  Fri Nov 13 15:25:22 2015 Nicolas Zimmermann
## Last update Wed May 25 19:42:45 2016 Nicolas Zimmermann
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -W -Wall -Werror -Wextra
CFLAGS	+= -I./include -I../lib/libmy/include -I../lib/libmy/include -I../lib/libmy_printf/include
CFLAGS	+= -L../lib/libmy_printf -lmy_printf -L../lib/libmy -lmy -lncurses

NAME   	= autocomplete

SRCS	= main.c \
	list/file_list.c \
	list/free_list.c \
	list/show_list.c \
	list/get_elem_nb.c \
	termcaps/my_getmaxyx.c \
	OM42sh/OM42sh.c \
	OM42sh/display_autocomplete.c

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
