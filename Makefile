##
## Makefile for  in /blinux_home/bazin_q/rendu/PSU_2015_my_select
## 
## Made by Quentin Bazin
## Login   <bazin_q@epitech.net>
## 
## Started on  Tue Dec 01 15:46:23 2015 Quentin Bazin
## Last update Mon Dec 14 13:18:25 2015 Quentin Bazin
##

NAME		= 42sh

INC_DIRS	= include

SOURCES		= source/application.c \
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
			  source/redirection.c \
			  source/signals.c \
			  source/token.c \
			  source/utils.c

MY_LIBS		= my_printf my

LIBS_EXT	= ncurses

include Makefile.libmy
include Makefile.common
