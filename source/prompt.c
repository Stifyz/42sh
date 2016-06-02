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
#include "application.h"
#include "utils.h"

void	init_caps(char *caps[KEY_COUNT])
{
  caps[K_LEFT] = tigetstr("kcub1");
  caps[K_RIGHT] = tigetstr("kcuf1");
  caps[K_BACKSPACE] = tigetstr("kbs");
  caps[K_DEL] = tigetstr("kdch1");
  caps[K_HOME] = tigetstr("khome");
  caps[K_END] = tigetstr("kend");
  caps[K_TAB] = tigetstr("ht");
}

#include <my_printf.h>

void	print_key(int key)
{
  char	*seq;
  char	c;
  int	value;

  seq = NULL;
  value = key;
  while (key > 0)
    {
      c = key & 0x7F;
      seq = my_strncatm(seq, &c, 1);
      key >>= 7;
    }
  my_revstr(seq);
  my_printf("Key with value %d = '%S'\n", value, seq);
}

t_err		prompt_init(t_prompt *prompt, t_application *app)
{
  char		*caps[KEY_COUNT];
  int		i;
  int		j;

  i = 0;
  prompt->str = "> ";
  prompt->app = app;
  init_caps(caps);
  while (i < KEY_COUNT)
    {
      prompt->keys[i] = 0;
      j = 0;
      while (caps[i][j])
	{
	  prompt->keys[i] <<= 7;
	  prompt->keys[i] |= caps[i][j];
	  ++j;
	}
      /* print_key(prompt->keys[i]); */
      ++i;
    }
  return (0);
}

char			*prompt_read_line(t_prompt *prompt)
{
  t_prompt_char_handler	handlers[HANDLER_COUNT];
  bool			char_handled;
  int			ch;
  int			i;

  prompt->pos = 0;
  prompt->line = my_strdup("");
  prompt_fill_char_handlers(handlers);
  while ((ch = my_getch()) != -1 && ch != '\n' && ch != '\r')
    {
      /* print_key(ch); */
      if (ch == 4 && prompt->line && !prompt->line[0])
	break;
      i = 0;
      char_handled = false;
      while (i < HANDLER_COUNT && !char_handled)
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
