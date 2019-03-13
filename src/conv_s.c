#include <stdlib.h>
#include "ft_printf.h"

int			reduce(char **buff, t_lst *lst, int dir, int wth, int prc)
{
	char		*str;
	int			i;
	int			j;

	i = 0;
	j = 0;
	str = (char *)lst->elt;
	if (dir == 0 && wth > 0 && wth > prc)
		j = wth - prc;
	while (i < prc && i < (int)ft_strlen(str))
	{
		(*buff)[j] = str[i];
		i++;
		j++;
	}
	return (ft_strlen(*buff));
}

int			ft_cat(char **buff, t_lst *lst, int dir, int wth)
{
	char		*str;
	int			i;
	int			j;

	str = (char *)lst->elt;
	i = 0;
	j = 0;
	if (dir == 0 && wth > (int)ft_strlen(str))
		j = wth - ft_strlen(str);
	while (i < (int)ft_strlen(str))
	{
		(*buff)[j] = str[i];
		i++;
		j++;
	}
	return (ft_strlen(*buff));
}

int			conv_s(t_lst *lst, int wth, int prc)
{
	char		*buff;
	int			dir;
	int			len;

	dir = 0;
	if (wth < 0)
	{
		dir++;
		wth = -wth;
	}
	if (NULL == (buff = ft_strnew((1 + wth + ft_strlen(lst->elt)) * sizeof(char))))
		return (-1);
	if (lst->elt == NULL && (prc >= 6 || prc == 0))
	{
		ft_bzero(buff, ft_strlen(buff));
		lst->elt = "(null)";
	}
	ft_add_n_char(&buff, ' ', wth);
	if (prc > 0 && ft_strlen(lst->elt) > 0)
		reduce(&buff, lst, dir, wth, prc);
	else
		ft_cat(&buff, lst, dir, wth);
	if (prc == 0 && ft_strchr(lst->str, '.'))
		ft_bzero(buff, ft_strlen(buff));
	len = ft_strlen(buff);
	ft_putstr(buff);
	free(buff);
	return (len);
}

