/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:30:36 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/18 13:52:26 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

//libft
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strchr(const char *str, int c);
size_t			ft_strlcat(char *dest, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *src, const char *str, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strrchr(const char *str, int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			**ft_split(char const *s, char c);

//get next line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char			*get_next_line(int fd);
char			*finish_sen(char *sen, char *read_ptr, int i, int j);
char			*end_file(char *sen, char *read_ptr, int read_count, int j);
int				copy_cat(char *sen, char *read_ptr, int j);
char			*make_sen(char *read_ptr, char *sen, int fd);
char			*new_malloc(char *str);
char			*gnl_cpy(char *dest, char *src);
int				strlength(char *str);
int				read_count_check(char *sen, char *read_ptr, int read_count);

// printf
int				ft_printf_char(va_list ptr, int len);
int				ft_printf_string(va_list ptr, int len);
int				ft_printf_pointer(va_list ptr, int len);
int				ft_printf_int(va_list ptr, int len);
int				ft_printf_unsigndec(va_list ptr, int len);
int				ft_printf_hexalower(va_list ptr, int len);
int				ft_printf_hexaupper(va_list ptr, int len);
int				ft_printf_check(const char *string, int i, va_list ptr,
					int len);
unsigned long	intcheck(long j);
char			*ft_mallocaaa(unsigned long j);
int				ft_printf(const char *string, ...);

#endif
