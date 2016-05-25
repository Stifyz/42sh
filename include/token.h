/*
** token.h for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun May 22 14:44:27 2016 Quentin Bazin
** Last update Sun May 22 14:44:27 2016 Quentin Bazin
*/
#ifndef TOKEN_H_
# define TOKEN_H_

# include <stdlib.h>
# include "error.h"

# define TOKEN_COUNT 3

typedef enum	e_token_type
{
  TOKEN_WHITESPACE,
  TOKEN_OPERATOR,
  TOKEN_NAME
}		t_token_type;

# define OP_COUNT 8

typedef enum	e_operator
{
  OP_SEMICOLON,
  OP_PIPE,
  OP_LREDIR,
  OP_RREDIR,
  OP_DLREDIR,
  OP_DRREDIR,
  OP_AND,
  OP_OR
}		t_operator;

typedef union	u_token_value
{
  t_operator	operator;
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
