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
			  source/error.c \
			  source/main.c

MY_LIBS		= my_printf my

include Makefile.libmy
include Makefile.common
