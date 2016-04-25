/*
** main.c for  in /home/bazin_q/rendu/CPE/sudoki-bi/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Fri Feb 26 21:12:44 2016 Quentin Bazin
** Last update Fri Feb 26 21:12:44 2016 Quentin Bazin
*/

#include "application.h"

int		main()
{
  t_application	app;

  if (application_init(&app))
    application_run(&app);
  application_free(&app);
  return (0);
}
