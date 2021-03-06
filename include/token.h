/*
** token.h for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun May 22 14:44:27 2016 Quentin Bazin
** Last update Sun Jun  5 09:28:10 2016 Nicolas Zimmermann
*/

#ifndef TOKEN_H_
# define TOKEN_H_

# include <stdlib.h>
# include "error.h"

# define TOKEN_COUNT 5

typedef enum	e_token_type
{
  TOKEN_WHITESPACE,
  TOKEN_SEPARATOR,
  TOKEN_REDIRECTION,
  TOKEN_NAME,
  TOKEN_STRING
}		t_token_type;

# define OP_COUNT 10

typedef enum	e_operator
{
  OP_DLREDIR,
  OP_DRREDIR,
  OP_LREDIR,
  OP_RREDIR,
  OP_AND,
  OP_OR,
  OP_PIPE,
  OP_SEMICOLON
}		t_operator;

typedef enum	e_string_type
{
  STR_SIMPLE,
  STR_DOUBLE
}		t_string_type;

typedef union	u_token_value
{
  t_operator	operator;
  t_string_type	string_type;
  char		*string;
}		t_token_value;

typedef struct	s_token
{
  t_token_type	type;
  t_token_value	value;
  size_t	begin;
  size_t	end;
  char		*content;
}		t_token;

typedef struct		s_token_elem
{
  t_token		token;
  struct s_token_elem	*next;
}			t_token_elem;

typedef struct	s_token_list
{
  t_token_elem	*first;
  t_token_elem	*last;
  size_t	length;
}		t_token_list;

void	token_print(t_token *token);
void	token_list_print(t_token_list *list);

t_err	token_list_add(t_token_list *list, t_token *token);
void	token_list_free(t_token_list *list);

#endif /* !TOKEN_H_ */
