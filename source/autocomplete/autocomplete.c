/*
** autocomplete.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/autocomplete
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 31 12:13:15 2016 Nicolas Zimmermann
** Last update Sun Jun  5 01:40:36 2016 Nicolas Zimmermann
*/

#include <my.h>
#include "application.h"
#include "autocomplete.h"
#include "lexer.h"

t_err			autocomplete_lexer(char *cmds, t_token_list *list)
{
  t_string_reader	reader;

  my_memset(list, 0, sizeof(t_token_list));
  reader.string = cmds;
  reader.length = my_strlen(cmds);
  reader.pos = 0;
  return (lexer_fill_token_list(&reader, list));
}

t_token_elem	*autocomplete_found_curs_pos(t_token_list *list,
					     t_prompt *prompt)
{
  t_token_elem	*tmp;

  tmp = list->first;
  while (tmp && tmp->token.end != (size_t)prompt->pos)
    tmp = tmp->next;
  if (tmp && tmp->token.type == TOKEN_NAME)
    return (tmp);
  else
    return (NULL);
}

t_err		autocomplete(t_prompt *prompt)
{
  t_autocomp	autoc;
  t_token_list	list;
  t_token_elem	*act;
  t_err		err;

  if (!prompt->line || !*prompt->line)
    return (0);
  if ((err = autocomplete_lexer(prompt->line, &list)))
    return (err);
  if (!(act = autocomplete_found_curs_pos(&list, prompt)))
    return (0);
  if ((autoc.is_folder = my_char_in_str(act->token.content, '/')) == true)
    err = autocomplete_folder(act->token.content, &autoc);
  else
    err = autocomplete_file(act->token.content, &autoc, prompt->app->path);
  if (err || (err = oh_my_42sh(&autoc, prompt)))
    return (err);
  free_file_list(&autoc);
  token_list_free(&list);
  return (err);
}
