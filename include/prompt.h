/*
** prompt.h for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Thu May 26 15:21:03 2016 Quentin Bazin
** Last update Thu May 26 15:21:03 2016 Quentin Bazin
*/
#ifndef PROMPT_H_
# define PROMPT_H_

# include <stdbool.h>
# include "error.h"

# define KEY_COUNT 2

typedef enum	e_key
{
  K_LEFT,
  K_RIGHT
}		t_key;

typedef struct	s_prompt
{
  int		keys[KEY_COUNT];
  char		*str;
  int		pos;
  char		*line;
}		t_prompt;

typedef bool (*t_prompt_char_handler)(t_prompt *, int);

/* prompt.c */
t_err	prompt_init(t_prompt *prompt);
char	*prompt_read_line(t_prompt *prompt);

/* prompt_char_handlers.c */
void	prompt_fill_char_handlers(t_prompt_char_handler handlers[3]);

#endif /* !PROMPT_H_ */
