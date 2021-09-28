/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:40:49 by tuytters          #+#    #+#             */
/*   Updated: 2021/09/28 14:18:03 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef OPEN_MAX
#  define OPEN_MAX 10264
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <stddef.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_struct
{
	int					format;
	int					pourcent;
	int					pluspetit0;
	int					tl;
	long				di;
	unsigned int		x;
	unsigned int		x_maj;
	unsigned long long	p;
	long long			u;
	char				c;
	char				*s;
}	t_struct;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

long long	ft_atoi(const char *nptr);
void		ft_bzero(void *s, size_t n);
int			ft_binary_len(int n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstadd_front(t_list **alst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memset(void *b, int c, size_t n);
int			ft_numlen(long long n);
void		ft_putchar_fd(char c, int fd);
void		ft_putchar(char c);
void		ft_putendl_fd(char *s, int fd);
void		ft_putendl(char *s);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putstr(char *s);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t n);
size_t		ft_strlen(const char *s);
int			ft_strlenprint(char *s);
int			ft_strlenhexa(unsigned long long n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		ft_baseprint1(t_struct *tab, va_list list, char *str, int i);
void		ft_baseprint2(t_struct *tab);
void		ft_change(t_struct *tab);
int			ft_formatnum(va_list list, t_struct *tab, char *str, int i);
int			ft_formatuchar(va_list list, t_struct *tab, char *str, int i);
void		ft_initialise_tab(t_struct *tab);
void		ft_nbr(t_struct *tab, int n, char str);
int			ft_printf(const char *format, ...);
void		ft_putchar_print(t_struct *tab, char c);
void		ft_puthexa_print(t_struct *tab, unsigned long n);
void		ft_puthexa_maj_print(t_struct *tab, unsigned long n);
void		ft_puthexapoint_print(t_struct *tab, unsigned long long n);
void		ft_putnbr_print(t_struct *tab, int n);
void		ft_putstr_print(t_struct *tab, char *s);
void		ft_putu_print(t_struct *tab);
int			ft_tab(va_list list, t_struct *tab, char *str, int i);
char		*ft_writehexa(t_struct *tab, int i,
				unsigned long long nbr, char *str);
void		ft_writemoins(t_struct *tab);
char		*ft_strchrgnl(const char *s, int c);
char		*ft_strjoingnl(char const *s1, char const *s2);
size_t		ft_strlengnl(const char *s);
int			get_next_line(int fd, char **line);
char		*ft_strdupgnl(const char *s);
char		*ft_substrgnl(char const *s, unsigned int start, size_t len);
long long	itobi(int x);
char		*ft_realloc(char *str, int to_add);

#endif
