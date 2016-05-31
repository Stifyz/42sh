/*
** prompt_char_handlers.c for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Thu May 26 15:48:21 2016 Quentin Bazin
** Last update Thu May 26 15:48:21 2016 Quentin Bazin
*/

#include <my.h>
#include "prompt.h"

bool	prompt_add_char(t_prompt *prompt, int ch)
{
  if ((ch > 31 && ch < 127) || ch == '\t')
    {
      prompt->line = my_strinsm(prompt->line, ch, prompt->pos);
      my_putstr(prompt->line + prompt->pos);
      my_putnchar('\b', my_strlen(prompt->line) - prompt->pos - 1);
      ++prompt->pos;
      return (true);
    }
  return (false);
}

bool	prompt_remove_char(t_prompt *prompt, int ch)
{
  if (!prompt->line || !prompt->line[0] || (prompt->pos < 1 && ch == 127))
    return (false);
  if (ch == prompt->keys[K_BACKSPACE] || ch == prompt->keys[K_DEL])
    {
      if (ch == prompt->keys[K_BACKSPACE])
	{
	  --prompt->pos;
	  my_putchar('\b');
	}
      my_strdel(prompt->line + prompt->pos, 1);
      my_putstr(prompt->line + prompt->pos);
      my_putchar(' ');
      my_putnchar('\b', my_strlen(prompt->line) - prompt->pos + 1);
      return (true);
    }
  return (false);
}

bool	prompt_move(t_prompt *prompt, int ch)
{
  if (ch == prompt->keys[K_LEFT] && prompt->pos > 0)
    {
      my_putchar('\b');
      --prompt->pos;
      return (true);
    }
  else if (ch == prompt->keys[K_RIGHT] && prompt->pos < my_strlen(prompt->line))
    {
      my_putchar(prompt->line[prompt->pos]);
      ++prompt->pos;
      return (true);
    }
  else if (ch == prompt->keys[K_HOME])
    {
      my_putnchar('\b', prompt->pos);
      prompt->pos = 0;
      return (true);
    }
  else if (ch == prompt->keys[K_END])
    {
      my_putstr(prompt->line + prompt->pos);
      prompt->pos = my_strlen(prompt->line);
      return (true);
    }
  return (false);
}

void	prompt_fill_char_handlers(t_prompt_char_handler handlers[3])
{
  handlers[0] = prompt_add_char;
  handlers[1] = prompt_remove_char;
  handlers[2] = prompt_move;
}
