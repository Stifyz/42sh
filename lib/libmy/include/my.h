/*
** my.h for Piscine_C_J09 in /home/bazin_q/rendu/Piscine_C_J09
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Thu Oct  8 09:15:00 2015 Quentin Bazin
** Last update Fri Dec 11 16:00:11 2015 Quentin Bazin
*/
#ifndef MY_H_
# define MY_H_

# include <stddef.h>
# include <stdbool.h>

/* Defines */
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif /* !M_PI */

# ifndef MY_GETLINE_READ_SIZE
#  define MY_GETLINE_READ_SIZE 4096
# endif /* !MY_GETLINE_READ_SIZE */

/* Structures */
typedef struct	s_vec2
{
  double	x;
  double	y;
}		t_vec2;

typedef struct	s_vec2i
{
  int		x;
  int		y;
}		t_vec2i;

/* Math functions */
unsigned int	my_abs(int n);
double		my_deg_to_rad(double degrees);
float		my_fabs(float n);
int		my_find_prime_sup(int nb);
float		my_fmax(float a, float b);
float		my_fmin(float a, float b);
unsigned int	my_int_len(int k);
int		my_isneg(int nb);
int		my_is_prime(int nombre);
int		my_max(int a, int b);
int		my_min(int a, int b);
int		my_power_rec(int nb, int power);
double		my_round(double x);
int		my_sqrt(int nb);

/* Character recognition */
bool		my_is_alpha(char c);
bool		my_is_alphanum(char c);
bool		my_is_num(char c);
bool		my_is_printable(char c);
bool		my_str_isalpha(char *str);
bool		my_str_islower(char *str);
bool		my_str_isnum(const char *str);
bool		my_str_isprintable(char *str);
bool		my_str_isupper(char *str);

/* Print functions */
void		my_putaddr(void *ptr);
void		my_putchar(char c);
void		my_putnchar(char c, int n);
void		my_puterr(const char *str);
long int	my_putnbr_base(long int nb, char *base);
int		my_put_nbr(int nb);
int		my_putstr(const char *str);
int		my_showmem(char *str, int size);
int		my_showstr(char *str);
int		my_show_wordtab(char **tab);

/* String operations */
char		*my_basename(char *path);
int		my_char_in_str(char *str, char c);
char		*my_epur_str(char *str);
void		*my_memcpy(void *dest, void *src, size_t n);
void		*my_memset(void *ptr, char c, size_t n);
char		*my_revstr(char *str);
char		*my_strcapitalize(char *str);
char		*my_strcat(char *dest, const char *src);
char		*my_strcatm(char *dest, const char *src);
char		*my_strchr(char *str, char c);
int		my_strcnt(const char *str, char c);
int		my_strcmp(const char *s1, const char *s2);
char		*my_strcpy(char *dest, char *src);
char		*my_strdel(char *str, int nb);
int		my_strdlen(const char *str, char delim);
char		*my_strdup(const char *str);
size_t		my_strichr(const char *str, char c);
char		*my_strins(char *str, char c, unsigned int pos);
int		my_strlcat(char *dest, char *src, int size);
int		my_strlen(const char *str);
char		*my_strlowcase(char *str);
int		my_strmatch(char *s1, char *s2);
char		*my_strncatm(char *dest, const char *src, int n);
char		*my_strncat(char *dest, const char *src, int n);
int		my_strncmp(const char *s1, const char *s2, int n);
char		*my_strncpy(char *dest, char *src, int nb);
char		*my_strndup(const char *src, int n);
char		**my_strspl(const char *str, bool keep_empty, char delim);
char		*my_strsplit(char *str, const char *delim, int part);
char		*my_strstr(char *str, const char *to_find);
char		*my_strupcase(char *str);

/* Type conversions */
int		my_getnbr_base(char *str, char *base);
int		my_getnbr(const char *str);
char		*my_itos(int nb);
char		**my_str_to_array(char *str, const char *delim);
char		**my_str_to_wordtab(char *str);

/* File operations */
char		*my_getline(const int fd);

/* Misc */
void		my_free_str_array(char **array);
void		my_sort_int_tab(int *tab, int size);
int		my_swap(int *a, int *b);
int		my_str_array_len(char **array);

#endif /* !MY_H_ */
