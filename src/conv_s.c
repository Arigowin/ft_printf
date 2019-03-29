#include <stdlib.h>
#include "ft_printf.h"

void		reduce(t_lst *lst, char **str, char *s2, int dir)
{
	int			j;
	int			len;

	j = 0;
	len = ft_strlen(s2);
	if (dir == 0 && lst->flg.wth > 0 && lst->flg.wth > len
			&& lst->flg.wth - len > lst->flg.wth - lst->flg.prc)
		j = lst->flg.wth - len;
	else if (dir == 0 && lst->flg.wth > 0 && lst->flg.wth > lst->flg.prc)
		j = lst->flg.wth - lst->flg.prc;
	ft_memcpy((*str) + j, s2, lst->flg.prc);
}

void		ft_cat(t_lst *lst, char **str, char *s2, int dir)
{
	int			j;
	int			len;

	j = 0;
	len = ft_strlen(s2);
	if (lst->flg.wth < len)
	{
		ft_strdel(str);
		*str = ft_strdup(s2);
		return ;
	}
	if (dir == 0 && lst->flg.wth > len)
		j = lst->flg.wth - len;
	ft_memcpy((*str) + j, s2, len);
}

int			conv_s(t_lst *lst, va_list ap)
{
	char		*buff;
	char		*str;
	int			dir;
	int			len;

	dir = 0;
	if (lst->flg.wth < 0)
	{
		dir++;
		lst->flg.wth = -lst->flg.wth;
	}
	buff = va_arg(ap, char *);
	if (NULL == (str = ft_strnew(1 + lst->flg.wth + ft_strlen(buff))))
		return (-1);
	if (buff == NULL && (lst->flg.prc >= 6 || lst->flg.prc == 0))
	{
		ft_bzero(str, ft_strlen(str) + 1);
		buff = "(null)";
	}
	ft_add_n_char(&str, ' ', lst->flg.wth);
	if (lst->flg.prc > 0 && ft_strlen(buff) > 0 && lst->flg.prc < (int)ft_strlen(buff))
		reduce(lst, &str, buff, dir);
	else
		ft_cat(lst, &str, buff, dir);
	if (lst->flg.prc == 0 && lst->flg.point)
		ft_bzero(str, ft_strlen(str));
	len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (len);
}

