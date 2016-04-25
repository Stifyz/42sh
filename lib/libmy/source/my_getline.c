/*
** my_getline.c for  in /blinux_home/bazin_q/rendu/MyLibs/libmy/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Jan 06 16:11:44 2016 Quentin Bazin
** Last update Wed Jan 06 16:11:44 2016 Quentin Bazin
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char	*my_strnmcat(char *dest, const char *src, int n, int *dest_len)
{
  char	*new;
  int	i;

  i = 0;
  if ((new = malloc(*dest_len + n + 1)) == NULL)
    return (NULL);
  while (i < *dest_len + n)
    {
      if (i < *dest_len)
	new[i] = dest[i];
      else
	new[i] = src[i - *dest_len];
      ++i;
    }
  *dest_len += n;
  new[*dest_len] = '\0';
  free(dest);
  return (new);
}

char	*my_getline_core(const int	fd,
			 char		**cache,
			 int		*cache_len,
			 int		*read_size)
{
  char	buffer[MY_GETLINE_READ_SIZE];
  int	line_len;
  char	*line;
  int	i;

  while ((*read_size = read(fd, buffer, MY_GETLINE_READ_SIZE)) > 0)
    {
      i = 0;
      while (i < *read_size)
	{
	  if (buffer[i] == '\n')
	    {
	      line_len = *cache_len;
	      if ((line = my_strnmcat(*cache, buffer, i, &line_len)) == NULL)
		return (NULL);
	      *cache_len = *read_size - i - 1;
	      *cache = my_strndup(buffer + i + 1, *cache_len);
	      return (line);
	    }
	  ++i;
	}
      *cache = my_strnmcat(*cache, buffer, *read_size, cache_len);
    }
  return (NULL);
}

char		*my_getline(const int fd)
{
  static char	*cache = NULL;
  static int	cache_len = 0;
  static int	read_size = -1;
  char		*line;
  char		*tmp;
  int		i;

  if (fd == -1 || MY_GETLINE_READ_SIZE < 1)
    return (NULL);
  i = -1;
  while (cache != NULL && ++i <= cache_len)
    if ((i == cache_len && read_size == 0) || cache[i] == '\n')
      {
	tmp = cache;
	line = my_strndup(cache, i);
	cache_len -= i + 1;
	cache = my_strndup(cache + i + 1, cache_len);
	free(tmp);
	return (line);
      }
  line = my_getline_core(fd, &cache, &cache_len, &read_size);
  tmp = cache;
  if (read_size == 0 && cache_len > 0)
    cache = NULL;
  return ((read_size == 0 && cache_len > 0 && !(cache_len = 0)) ? tmp : line);
}
