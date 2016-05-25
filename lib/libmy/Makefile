##
## Makefile for Piscine_C_J10 in /home/bazin_q/rendu/Piscine_C_J10
## 
## Made by Quentin Bazin
## Login   <bazin_q@epitech.net>
## 
## Started on  Fri Oct  9 08:56:41 2015 Quentin Bazin
## Last update Fri Dec 11 16:00:32 2015 Quentin Bazin
##

CC	= gcc

CFLAGS	+= -g -Wall -Wextra -Wfatal-errors -ansi -pedantic
CFLAGS	+= -Iinclude

NAME	= libmy.a

# Math functions
SRCS	+=	source/my_abs.c \
			source/my_deg_to_rad.c \
			source/my_find_prime_sup.c \
			source/my_int_len.c \
			source/my_isneg.c \
			source/my_is_prime.c \
			source/my_max.c \
			source/my_min.c \
			source/my_power_rec.c \
			source/my_round.c \
			source/my_sqrt.c

# Character recognition
SRCS	+=	source/my_is_num.c \
			source/my_str_isalpha.c \
			source/my_str_islower.c \
			source/my_str_isnum.c \
			source/my_str_isprintable.c \
			source/my_str_isupper.c

# Print functions
SRCS	+=	source/my_putaddr.c \
			source/my_putchar.c \
			source/my_putnbr_base.c \
			source/my_put_nbr.c \
			source/my_putstr.c \
			source/my_showmem.c \
			source/my_showstr.c \
			source/my_show_wordtab.c

# String operations
SRCS	+=	source/my_basename.c \
			source/my_char_in_str.c \
			source/my_epur_str.c \
			source/my_memcpy.c \
			source/my_memset.c \
			source/my_revstr.c \
			source/my_strcapitalize.c \
			source/my_strcat.c \
			source/my_strcatm.c \
			source/my_strchr.c \
			source/my_strcnt.c \
			source/my_strcmp.c \
			source/my_strcpy.c \
			source/my_strdel.c \
			source/my_strdup.c \
			source/my_strins.c \
			source/my_strlcat.c \
			source/my_strmatch.c \
			source/my_strlen.c \
			source/my_strlowcase.c \
			source/my_strncat.c \
			source/my_strncmp.c \
			source/my_strncpy.c \
			source/my_strspl.c \
			source/my_strsplit.c \
			source/my_strstr.c \
			source/my_strupcase.c

# Type conversions
SRCS	+=	source/my_getnbr_base.c \
			source/my_getnbr.c \
			source/my_itos.c \
			source/my_str_to_wordtab.c

# File operations
SRCS	+=	source/my_getline.c

# Misc
SRCS	+=	source/my_sort_int_tab.c \
			source/my_str_array_len.c \
			source/my_swap.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)
	@echo "Done for $(NAME)"

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@ar rcs $(NAME) $(OBJS) $(LDFLAGS)

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning library..."
	@rm -f $(NAME)

%.o: %.c
	@echo "=>" $<
	@$(CC) -c $< -o $@ $(CFLAGS)

re: fclean all

tests:
	@[ -d tests ] && make --no-print-directory -C tests || echo -n

.PHONY: all clean fclean re tests
