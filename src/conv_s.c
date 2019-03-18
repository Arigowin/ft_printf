#include <stdlib.h>
#include "ft_printf.h"

int			reduce(char **str, char *s2, int dir, int wth, int prc)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (dir == 0 && wth > 0 && wth > prc)
		j = wth - prc;
	while (i < prc && i < (int)ft_strlen(s2))
	{
		(*str)[j] = s2[i];
		i++;
		j++;
	}
	return (ft_strlen(*str));
}

int			ft_cat(char **str, char *s2, int dir, int wth)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (dir == 0 && wth > (int)ft_strlen(s2))
		j = wth - ft_strlen(s2);
	while (i < (int)ft_strlen(s2))
	{
		(*str)[j] = s2[i];
		i++;
		j++;
	}
	return (ft_strlen(*str));
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
	if (NULL == (str = ft_strnew((1 + wth + ft_strlen(buff)) * sizeof(char))))
		return (-1);
	if (buff == NULL && (prc >= 6 || prc == 0))
	{
		ft_bzero(str, ft_strlen(str));
		buff = "(null)";
	}
	ft_add_n_char(&str, ' ', wth);
	if (prc > 0 && ft_strlen(buff) > 0)
		reduce(&str, buff, dir, wth, prc);
	else
		ft_cat(&str, buff, dir, wth);
	if (prc == 0 && ft_strchr(lst->str, '.'))
		ft_bzero(str, ft_strlen(str));
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

