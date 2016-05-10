##
## Makefile for  in /blinux_home/bazin_q/rendu/PSU_2015_my_select
##
## Made by Quentin Bazin
## Login   <bazin_q@epitech.net>
##
## Started on  Tue Dec 01 15:46:23 2015 Quentin Bazin
## Last update Mon May  9 16:06:58 2016 Benjamin Audet
##

NAME		= test_autocomplete

SOURCES		= autocomplet.c \
		  list_manage.c \
		  list_manipulation.c \
		  error.c

CFLAGS		+= -I./include

OBJS		= $(SOURCES:.c=.o)

MY_LIBS		= my_printf my

all: $(OBJS)
	gcc $(OBJS) -o $(NAME) $(CFLAGS)

