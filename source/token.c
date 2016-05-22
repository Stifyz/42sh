/*
** token.c for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun May 22 14:44:34 2016 Quentin Bazin
** Last update Sun May 22 14:44:34 2016 Quentin Bazin
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "token.h"

void		token_print(t_token *token)
{
  char		*token_types[TOKEN_COUNT];
  unsigned int	i;

  i = 0;
  token_types[0] = "WHITESPACE";
  token_types[1] = "OPERATOR";
  token_types[2] = "NAME";
  while (i < TOKEN_COUNT)
    {
      if (token->type == i)
	{
	  printf(token_types[i]);
	  if (token->type != TOKEN_WHITESPACE)
	    printf("(%s)", token->content);
	  printf("\n");
	}
      ++i;
    }
  fflush(stdout);
}

void		token_list_print(t_token_list *list)
{
  t_token_elem	*tmp;

  tmp = list->first;
  while (tmp)
    {
      token_print(&tmp->token);
      tmp = tmp->next;
    }
}

t_err		token_list_add(t_token_list *list, t_token *token)
{
  t_token_elem	*new;

  if (!(new = malloc(sizeof(t_token_elem))))
    return (print_error(ERROR_MALLOC_FAILED));
  memcpy(&new->token, token, sizeof(t_token));
  new->next = NULL;
  if (!list->first)
    list->first = new;
  if (list->last)
    list->last->next = new;
  list->last = new;
  list->length++;
  return (0);
}

void		token_list_free(t_token_list *list)
{
  t_token_elem	*tmp;
  t_token_elem	*next;

  tmp = list->first;
  while (tmp)
    {
      next = tmp->next;
      free(tmp->token.content);
      free(tmp);
      tmp = next;
    }
}
