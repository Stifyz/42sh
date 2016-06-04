##
## Makefile for  in /blinux_home/bazin_q/rendu/PSU_2015_my_select
## 
## Made by Quentin Bazin
## Login   <bazin_q@epitech.net>
## 
## Started on  Tue Dec 01 15:46:23 2015 Quentin Bazin
## Last update Tue Dec 01 15:46:23 2015 Quentin Bazin
##

NAME		= 42sh

INC_DIRS	= include

SOURCES		= source/application.c \
			  source/autocomplete/OM42sh.c \
			  source/autocomplete/autocomplete.c \
			  source/autocomplete/display_autocomplete.c \
			  source/autocomplete/file_list.c \
			  source/autocomplete/free_list.c \
			  source/autocomplete/my_getmaxyx.c \
			  source/autocomplete/rm_elem.c \
			  source/autocomplete/sort_list.c \
			  source/autocomplete/swap_elem.c \
			  source/builtin_cd.c \
			  source/builtin_env.c \
			  source/builtins.c \
			  source/command.c \
			  source/command_run.c \
			  source/env.c \
			  source/env_utils.c \
			  source/error.c \
			  source/lexer.c \
			  source/lexer_match.c \
			  source/lexer_utils.c \
			  source/main.c \
			  source/parser.c \
			  source/parser_command.c \
			  source/prompt.c \
			  source/prompt_char_handlers.c \
			  source/redirection.c \
			  source/signals.c \
			  source/token.c \
			  source/utils.c

MY_LIBS		= my_printf my

LIBS_EXT	= ncurses

include Makefile.libmy
include Makefile.common
