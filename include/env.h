/*
** env.h for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Fri Mar 25 17:24:33 2016 Quentin Bazin
** Last update Fri Mar 25 17:24:33 2016 Quentin Bazin
*/
#ifndef ENV_H_
# define ENV_H_

# ifndef VAL_OFFSET_
#  define VAL_OFFSET_ my_strchr(base_env, '=') + 1
# endif /* !VAL_OFFSET_ */

typedef struct	s_env
{
  char		*name;
  char		*value;
  struct s_env	*next;
}		t_env;

t_env	*env_init(char **base_env);
t_env	*env_init_variable(char *base_env);
char	**env_to_strarray(t_env *env);
char	*env_get_prog_path(char **env_path, char *prog_name);
void	env_free(t_env *env);

char	*my_getenv(t_env *env, char *name);
int	my_setenv(t_env **envp, char *name, char *value);
void	my_unsetenv(t_env **envp, char *pattern);

#endif /* !ENV_H_ */
