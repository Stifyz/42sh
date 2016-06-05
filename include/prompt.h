/*
** prompt.h for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Thu May 26 15:21:03 2016 Quentin Bazin
** Last update Sun Jun  5 01:05:27 2016 Nicolas Zimmermann
*/
#ifndef PROMPT_H_
# define PROMPT_H_

# include <stdbool.h>
# include "error.h"

# define HANDLER_COUNT 4
# define KEY_COUNT 7

struct s_application;

typedef enum	e_key
{
  K_LEFT,
  K_RIGHT,
  K_BACKSPACE,
  K_DEL,
  K_HOME,
  K_END,
  K_TAB
}		t_key;

typedef struct		s_prompt
{
  struct s_application	*app;
  int			keys[KEY_COUNT];
  char			*str;
  int			pos;
  char			*line;
}			t_prompt;

typedef bool (*t_prompt_char_handler)(t_prompt *, int);

/* prompt.c */
t_err	prompt_init(t_prompt *prompt, struct s_application *app);
char	*prompt_read_line(t_prompt *prompt);

void	print_key(int key); /* FIXME: DEBUG, TO REMOVE */

/* prompt_char_handlers.c */
void	prompt_fill_char_handlers(t_prompt_char_handler[HANDLER_COUNT]);
bool    prompt_add_char(t_prompt *prompt, int ch);
bool	prompt_move(t_prompt *prompt, int ch);

#endif /* !PROMPT_H_ */
