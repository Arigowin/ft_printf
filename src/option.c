#include <stdlib.h>
#include "ft_printf.h"

void		add_n_char(char **str, char c, int n)
{
	int		i;
	i = 0;
	while (str && *str && i < n)
	{
		(*str)[i] = c;
		i++;
	}
}

int			precision(char **buff, t_lst *lst, int dir, int width)
{
	char		*str;
	int 		precision;
	int			i;
	int			j;

	i = 0;
	j = 0;
	str = (char *)lst->elt;
	precision = ft_atoi(ft_strchr(lst->str, '.') + 1);
	if (dir == 0 && width > 0)
		j = width - precision;
	while (i < precision && i < (int)ft_strlen(str))
	{
		(*buff)[j] = str[i];
		i++;
		j++;
	}
	return (ft_strlen(*buff));
}

int			cat(char **buff, t_lst *lst, int dir, int width)
{
	char		*str;
	int			i;
	int			j;

	str = (char *)lst->elt;
	i = 0;
	j = 0;
	if (dir == 0 && width > (int)ft_strlen(str))
		j = width - ft_strlen(str);
	while (i < (int)ft_strlen(str))
	{
		(*buff)[j] = str[i];
		i++;
		j++;
	}
	return (ft_strlen(*buff));
}

int			opt_s(t_lst *lst)
{
	char		*buff;
	int			dir;
	int			width;
	int			len;

	dir = 0;
	if ((width = ft_atoi(lst->str)) < 0)
	{
		dir++;
		width = -width;
	}
	if (NULL == (buff = ft_strnew(1 + width
					+ ft_strlen(lst->elt) * sizeof(char))))
		return (-1);
	add_n_char(&buff, ' ', width);
	if (ft_strchr(lst->str, '.'))
		precision(&buff, lst, dir, width);
	else
		cat(&buff, lst, dir, width);
	len = ft_strlen(buff);
	ft_putstr(buff);
	free(buff);
	return (len);
}

int			exec_opt(t_lst *lst)
{
	int			len;

	len = 0;
	if (lst->type == STR)
	{
		len = opt_s(lst);
	}
	return (len);
}

