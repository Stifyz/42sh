/*
** error.h for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Fri Mar 25 16:58:55 2016 Quentin Bazin
** Last update Fri Mar 25 16:58:55 2016 Quentin Bazin
*/
#ifndef ERROR_H_
# define ERROR_H_

/* Ne pas oublier d'augmenter le compteur à chaque ajout */
# define ERROR_COUNT 127

typedef enum				e_err
{
  ERROR_MALLOC_FAILED			= 1,
  ERROR_PIPE_FAILED			= 2,
  ERROR_SYNTAX_ERROR			= 3,
  ERROR_TOO_FEW_ARGUMENTS		= 4,
  ERROR_TOO_MANY_ARGUMENTS		= 5,
  ERROR_POSITIVE_INTEGER_REQUIRED	= 6,
  ERROR_UNABLE_TO_OPEN_DIRECTORY	= 7,
  ERROR_END_OF_HISTORY			= 8,
  ERROR_VARIABLE_NAME_INVALID		= 9,
  ERROR_FORK_FAILED			= 10,
  ERROR_OPEN_FAILED			= 11,
  ERROR_AMBIGUOUS_OUTPUT_REDIRECT	= 12,
  ERROR_AMBIGUOUS_INPUT_REDIRECT	= 13,
  ERROR_INVALID_NULL_COMMAND		= 14,
  ERROR_COMMAND_NOT_FOUND		= 127
}					t_err;

void	fill_error_messages(char *messages[ERROR_COUNT]);

void	print_usage(char *program_name);
t_err	print_error(t_err error, ...);

#endif /* !ERROR_H_ */
