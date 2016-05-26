/*
** prompt.c for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Thu May 26 15:23:15 2016 Quentin Bazin
** Last update Thu May 26 15:23:15 2016 Quentin Bazin
*/

#include <my.h>
#include <ncurses.h>
#include <stdlib.h>
#include "prompt.h"
#include "utils.h"

t_err		prompt_init(t_prompt *prompt)
{
  char		*caps[KEY_COUNT];
  int		i;
  int		j;

  prompt->str = "> ";
  if (setterm(NULL) != OK)
    return (print_error(ERROR_SETTERM_FAILED));
  caps[K_LEFT] = tigetstr("kcub1");
  caps[K_RIGHT] = tigetstr("kcuf1");
  i = 0;
  while (i < KEY_COUNT)
    {
      prompt->keys[i] = 0;
      j = 0;
      while (caps[i][j])
	{
	  prompt->keys[i] += 128 * j + caps[i][j];
	  ++j;
	}
      ++i;
    }
  return (0);
}

char			*prompt_read_line(t_prompt *prompt)
{
  t_prompt_char_handler	handlers[3];
  bool			char_handled;
  int			ch;
  int			i;

  prompt->pos = 0;
  prompt->line = my_strdup("");
  prompt_fill_char_handlers(handlers);
  while ((ch = my_getch()) != -1 && ch != '\n' && ch != '\r')
    {
      if (ch == 4 && prompt->line && !prompt->line[0])
	break;
      i = 0;
      char_handled = false;
      while (i < 3 && !char_handled)
	char_handled = handlers[i++](prompt, ch);
    }
  if (ch == -1 || ch == 4)
    {
      free(prompt->line);
      return (NULL);
    }
  my_putstr("\n");
  return (prompt->line);
}
