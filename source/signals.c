/*
** signals.c for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Apr 26 13:47:05 2016 Quentin Bazin
** Last update Tue Apr 26 13:47:05 2016 Quentin Bazin
*/

#include <my.h>
#include <sys/wait.h>
#include "signals.h"

void	signals_check_status(int status)
{
  if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == SIGSEGV)
	{
	  my_puterr("Segmentation fault");
	  if (WCOREDUMP(status))
	    my_puterr(" (core dumped)");
	  my_puterr("\n");
	}
      else if (WTERMSIG(status) == SIGFPE)
	{
	  my_puterr("Floating exception");
	  if (WCOREDUMP(status))
	    my_puterr(" (core dumped)");
	  my_puterr("\n");
	}
    }
}
