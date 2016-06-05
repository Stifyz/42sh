/*
** signals.h for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sat Mar 26 10:53:10 2016 Quentin Bazin
** Last update Sat Mar 26 10:53:10 2016 Quentin Bazin
*/
#ifndef SIGNALS_H_
# define SIGNALS_H_

# include "application.h"

void	signals_check_status(t_application *app, t_command *command);
void	signals_handle_sigint();

#endif /* !SIGNALS_H_ */
