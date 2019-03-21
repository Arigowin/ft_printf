#include <stdlib.h>
#include "ft_printf.h"

void		reduce(char **str, char *s2, int dir, int wth, int prc)
{
	int			j;
	int			len;

	j = 0;
	len = ft_strlen(s2);
	if (dir == 0 && wth > 0 && wth > len && wth - len > wth - prc)
		j = wth - len;
	else if (dir == 0 && wth > 0 && wth > prc)
		j = wth - prc;
	ft_memcpy((*str) + j, s2, prc);
}

void		ft_cat(char **str, char *s2, int dir, int wth)
{
	int			j;
	int			len;

	j = 0;
	len = ft_strlen(s2);
	if (wth < len)
	{
		ft_strdel(str);
		*str = ft_strdup(s2);
		return ;
	}
	if (dir == 0 && wth > len)
		j = wth - len;
	ft_memcpy((*str) + j, s2, len);
}

int			conv_s(t_lst *lst, va_list ap, int wth, int prc)
{
	char		*buff;
	char		*str;
	int			dir;
	int			len;

	dir = 0;
	if (wth < 0)
	{
		dir++;
		wth = -wth;
	}
	buff = va_arg(ap, char *);
	if (NULL == (str = ft_strnew(1 + wth + ft_strlen(buff))))
		return (-1);
	if (buff == NULL && (prc >= 6 || prc == 0))
	{
		ft_bzero(str, ft_strlen(str) + 1);
		buff = "(null)";
	}
	ft_add_n_char(&str, ' ', wth);
	if (prc > 0 && ft_strlen(buff) > 0 && prc < (int)ft_strlen(buff))
		reduce(&str, buff, dir, wth, prc);
	else
		ft_cat(&str, buff, dir, wth);
	if (prc == 0 && ft_strchr(lst->str, '.'))
		ft_bzero(str, ft_strlen(str));
	len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (len);
}

