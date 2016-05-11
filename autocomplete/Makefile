##
## Makefile for Makefile in /home/zimmer_n
## 
## Made by Nicolas Zimmermann
## Login   <zimmer_n@epitech.net>
## 
## Started on  Fri Nov 13 15:25:22 2015 Nicolas Zimmermann
## Last update Tue May 10 15:57:21 2016 Nicolas Zimmermann
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -W -Wall -Werror -Wextra
CFLAGS	+= -I. -I../lib/libmy/include
CFLAGS	+= -L../lib/libmy -lmy

NAME   	= autocomplete

SRCS	= main.c \
	file_list.c \
	free_list.c \
	show_list.c

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
