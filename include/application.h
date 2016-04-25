/*
** application.h for  in /home/bazin_q/rendu/CPE/sudoki-bi/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Fri Feb 26 21:13:25 2016 Quentin Bazin
** Last update Fri Feb 26 21:13:25 2016 Quentin Bazin
*/
#ifndef APPLICATION_H_
# define APPLICATION_H_

# include <stdbool.h>
# include "error.h"

typedef struct	s_application
{
  bool		is_running;
}		t_application;

t_err	application_init(t_application *app);
void	application_run(t_application *app);
void	application_free(t_application *app);

#endif /* !APPLICATION_H_ */
