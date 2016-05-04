/*
** main.c for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Fri Mar 25 16:57:01 2016 Quentin Bazin
** Last update Fri Mar 25 16:57:01 2016 Quentin Bazin
*/

#include "application.h"

int		main(int argc, char **argv, char **env)
{
  t_application	app;

  (void)argc;
  (void)argv;
  if (application_init(&app, env) == 0)
    application_run(&app);
  application_free(&app);
  return (app.exit_code);
}
