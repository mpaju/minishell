/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 19:00:38 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/20 19:00:40 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					get_next_line(const int fd, char **line);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, int nbyte);
int					ft_chrpos(char *str, char x);
void				ft_freesplit(char **str);
char				*ft_get_filetype(char *path);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_islower(char c);
int					ft_isupper(char c);
char				*ft_itoa(int n);
void				ft_lstadd(t_list **alst, t_list *newlst);
int					ft_lstaddlast(t_list **alst, t_list *newlist);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_lstswap(t_list *lst, t_list *prev);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *str1, const void *str2, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t num);
void				*ft_memset(void *str, int c, size_t n);
void				ft_print_chars(char chr, int count);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putstr(char *str);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_skip_char(char *str, char c);
char				*ft_strcat(char *dest, const char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t dstsize);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(char *str, int c);
size_t				ft_strclen(char *str, char c);
void				ft_strclr(char *s);
char				*ft_strrchr(char *str, int c);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, const char *src, size_t num);
void				ft_strdel(char **as);
char				*ft_strdup(char *src);
char				*ft_strndup(char *str, size_t num);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_str3join(char const *s1, char const *s2, \
					const char *s3);
int					ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size);
char				*ft_strreplace(char *str, char *strin, char *strout);
char				**ft_strsplit(char const *s, char x);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strnstr(const char *big, const char *little, \
					size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
#endif
