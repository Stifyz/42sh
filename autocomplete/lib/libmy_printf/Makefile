##
## Makefile for Piscine_C_J10 in /home/bazin_q/rendu/Piscine_C_J10
## 
## Made by Quentin Bazin
## Login   <bazin_q@epitech.net>
## 
## Started on  Fri Oct  9 08:56:41 2015 Quentin Bazin
## Last update Tue Dec 01 16:02:17 2015 Quentin Bazin
##

CC		= gcc

NAME	= libmy_printf.a

SRCS	= source/my_printf.c \
		  source/my_printf_print_funcs.c \
		  source/my_printf_print_wrappers.c

ifeq ($(shell test -e ../libmy && echo "1" || echo "0"), 1)
	LIBMY_DIR	:=	../libmy
else
	LIBMY_DIR	:=	lib/libmy
endif

CFLAGS	+= -g -Wall -Wextra -Wfatal-errors -ansi -pedantic
CFLAGS	+= -Iinclude -I$(LIBMY_DIR)/include

LDFLAGS		= -L. -L$(LIBMY_DIR)

LDFLAGS		+= -lmy_printf -lmy

OBJS	= $(SRCS:.c=.o)

all: lib $(NAME)
	@echo "Done for $(NAME)."
	@fixmes="$(shell cat $(shell find . -name "*.c" -or -name "*.h") | grep FIXME | wc -l)" && [ "$$fixmes" != "0" ] && echo $$fixmes "fixme(s) remaining." || echo -n
	@[ -e TODO ] && echo "Don't forget to read the TODO file." || echo -n

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@ar rcs $(NAME) $(OBJS)

lib:
	@make --no-print-directory -C $(LIBMY_DIR)

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning library..."
	@rm -f $(NAME)
	@rm -f tests-*

re: fclean all

install_libs:
	@rm -rf lib
	@mkdir -p lib/libmy
	@cp -r ../libmy/{include,source,Makefile} lib/libmy/
	@make --no-print-directory -C lib/libmy fclean > /dev/null

tests:
	@$(CC) tests/tests-my_printf.c -o tests-my_printf $(CFLAGS) $(LDFLAGS)
	@$(CC) tests/tests-printf.c -o tests-printf $(CFLAGS)

%.o: %.c
	@echo "=>" $<
	@$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: all lib clean fclean re install_libs tests
