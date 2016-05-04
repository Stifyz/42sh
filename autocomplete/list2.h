/*
** list.h for list.h in /home/audet_b/Projets/PSU_2015_minishell2/include/
**
** Made by Benjamin Audet
** Login   <audet_b@epitech.eu>
**
** Started on  Mon Apr  4 17:10:27 2016 Benjamin Audet
** Last update Fri Apr 29 15:44:15 2016 Benjamin Audet
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct		s_autocomp
{
    char 		*file_name;
    struct s_element 	*next;
}	     	  	t_autocomp;

#endif /* !LIST_H_ */
