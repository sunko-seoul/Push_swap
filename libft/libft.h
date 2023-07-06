/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:20:04 by sunko             #+#    #+#             */
/*   Updated: 2023/05/29 18:10:27 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/* get_next_line */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* is function*/
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);

/*mem function*/
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);

/*str function*/
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnstr(const char *haystack, const char *need, size_t l);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);

/*fd function*/
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);

/*other function*/
long long		ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_calloc(size_t count, size_t size);
char			*ft_itoa(int n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);

/*other function*/
void			ft_bzero(void *s, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_calloc(size_t count, size_t size);
char			*ft_itoa(int n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);

/*ft_printf*/
int				ft_printf(const char *str, ...);
int				format_specifiers(const char *str, va_list *ap, int *rst);
int				ft_error(int *rst, char *str);
int				goto_hexa_upper(unsigned int nb, int *rst);
int				print_hexa_upper(va_list *ap, int *rst);
int				goto_hexa_low(unsigned int nb, int *rst);
int				print_hexa_low(va_list *ap, int *rst);
int				print_character(va_list *ap, int *rst);
int				print_string(va_list *ap, int *rst);
int				print_decimal(va_list *ap, int *rst);
int				print_pointer(va_list *ap, int *rst);
void			goto_memory(unsigned long long nb, int *rst);
int				print_unsigned_decimal(va_list *ap, int *rst);
char			*ft_unsigned_itoa(unsigned int n);

#endif
