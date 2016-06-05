/*
** lexer_utils.c for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun May 22 14:47:28 2016 Quentin Bazin
** Last update Sun Jun  5 17:19:31 2016 Nicolas Zimmermann
*/

#include <ctype.h>
#include <my.h>
#include <string.h>
#include "lexer.h"

bool	lexer_is_name(char c, char last_c, char next_c)
{
  char	*reserved;
  int	i;

  i = 0;
  reserved = ";|<>&\t \"\'";
  if (c == '\\') 
    if (!next_c && last_c != '\\')
      return (false);
  if (!c)
    return (false);
  while (reserved[i])
    if (c == reserved[i++] && last_c != '\\')
      return (false);
  return (true);
}

bool	lexer_is_whitespace(char c)
{
  return (c == ' ' || c == '\t');
}

int	count_backslash(char *str, size_t pos)
{
  int	cnt;

  cnt = 0;
  while (str[--pos] == '\\')
    {
      cnt++;
      if (pos > 0)
	pos--;
      else
	return (cnt);
    }
  return (cnt);
}

char	*clear_name(char *str)
{
  int	i;
  int	j;
  char	*dup;

  i = -1;
  j = 0;
  while (str[++i])
    if (str[i] == '\\' && str[i + 1] == '\\')
      {
	j++;
	i++;
      }
    else if (str[i] != '\\')
      j++;
  if (!(dup = malloc(j + 1)))
    return (NULL);
  i = -1;
  j = 0;
  while (str[++i])
    if (str[i] == '\\' && str[i + 1] == '\\')
      dup[j++] = str[i++];
    else if (str[i] != '\\')
      dup[j++] = str[i];
  free(str);
  dup[j] = '\0';
  return (dup);
}

char	*clear_string(char *str)
{
  int	i;
  int	j;
  char	*dup;

  i = -1;
  j = 0;
  while (str[++i])
    if (str[i] == '\\' &&
	(str[i + 1] == '\'' || str[i + 1] == '\"' || str[i + 1] == '\\'))
      {
	j++;
	i++;
      }
    else
      j++;
  if (!(dup = malloc(j + 1)))
    return (NULL);
  i = -1;
  j = 0;
  while (str[++i])
    if (str[i] == '\\' &&
	(str[i + 1] == '\'' || str[i + 1] == '\"' || str[i + 1] == '\\'))
      dup[j++] = str[++i];
    else
      dup[j++] = str[i];
  free(str);
  dup[j] = 0;
  return (dup);
}
