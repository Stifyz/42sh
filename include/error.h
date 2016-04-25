/*
** error.h for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Apr 25 16:08:54 2016 Quentin Bazin
** Last update Mon Apr 25 16:08:54 2016 Quentin Bazin
*/
#ifndef ERROR_H_
# define ERROR_H_

/* Ne pas oublier d'augmenter le compteur à chaque ajout */
# define ERROR_COUNT 1

typedef enum		e_err
{
  ERROR_MALLOC_FAILED	= 1
}			t_err;

void	fill_error_messages(char *messages[ERROR_COUNT]);

void	print_usage(char *program_name);
t_err	print_error(t_err error, ...);

#endif /* !ERROR_H_ */
