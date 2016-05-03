/*
** lexer.h for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Apr 27 11:07:52 2016 Quentin Bazin
** Last update Wed Apr 27 11:07:52 2016 Quentin Bazin
*/
#ifndef LEXER_H_
# define LEXER_H_

# include <stddef.h>

typedef enum		e_token_type
{
  TOKEN_COMMAND		= 0,
  TOKEN_PARAMETER	= 1,
  TOKEN_SEPARATOR	= 2,
  TOKEN_LREDIR		= 3,
  TOKEN_RREDIR		= 4,
  TOKEN_DLREDIR		= 5,
  TOKEN_DRREDIR		= 6,
  TOKEN_AND		= 7,
  TOKEN_OR		= 8
}			t_token_type;

typedef struct		s_token
{
  size_t		begin;
  size_t		end;
  char			*str;
  t_token_type		type;
}			t_token;

typedef enum		e_result_type
{
  RESULT_TOKEN		= 0,
  RESULT_ERROR		= 1,
  RESULT_NULL		= 2
}			t_result_type;

typedef struct		s_result
{
  t_result_type		type;
  t_token		token;
}			t_result;

typedef struct		s_token_list
{
  t_token		token;
  struct s_token_list	*next;
}			t_token_list;

#endif /* !LEXER_H_ */
