#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
#include <stdarg.h>

typedef enum		e_type
{
	DFLT,
	STR,
	INT,
	CHAR,
	PTR,
	OCT,
	UINT,
	LHEX,
	UHEX,
	FLT
}					t_type;

typedef struct		s_lst
{
	void			*elt;
	double			flt;
	t_type			type;
	char			*str;
	struct s_lst	*next;
}					t_lst;

int					ft_printf(const char *format, ...);

void				parse(t_lst **lst, va_list ap, const char *format);
int					print_all(t_lst *lst);
int					exec_type(t_lst *lst);
int					exec_opt(t_lst *lst);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbrendl(int n);
void				ft_putupper(char const *s);

t_lst				*lst_add(t_lst **lst, void *elt, t_type type, char *str);
t_lst				*lst_add_flt(t_lst **lst, double elt, t_type type, char *str);
void				lst_free(t_lst **lst);

size_t				ft_strlen(const char *s);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
int					ft_atoi(const char *str);
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_ptr_to_hex(const void *ptr, char (*res)[13]);
void				ft_strdel(char **as);
char				*ft_strsub(char const *s, size_t start, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
int					ft_isdigit(int c);
int					ft_toupper(int c);

#endif
