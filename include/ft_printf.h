#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>


typedef enum		e_type
{
	DFLT,
	STR,
	INT,
	CHAR,
	PTR
}					t_type;

typedef struct		s_lst
{
	void			*elt;
	t_type			type;
	char			*str;
}					t_lst;

int					ft_printf(const char *format, ...);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbrendl(int n);

size_t				ft_strlen(const char *s);
char				*ft_itoa(int n);
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_ptr_to_hex(const void *ptr, char (*res)[13]);

#endif
