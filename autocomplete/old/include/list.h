/*
** list.h for list.h in /home/audet_b/Projets/PSU_2015_minishell2/include/
**
** Made by Benjamin Audet
** Login   <audet_b@epitech.eu>
**
** Started on  Mon Apr  4 17:10:27 2016 Benjamin Audet
** Last update Fri Apr 29 15:44:45 2016 Benjamin Audet
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct		s_element
{
    char 		*file_name;
    struct s_element 	*next;
}	     	  	t_element;

typedef struct	s_list
{
  t_element 	*first;
}		t_list;

#endif /* !LIST_H_ */
