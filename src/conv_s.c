#include <stdlib.h>
#include "ft_printf.h"

int			reduce(char **buff, t_lst *lst, int dir, int width, int precision)
{
	char		*str;
	int			i;
	int			j;

	i = 0;
	j = 0;
	str = (char *)lst->elt;
	if (dir == 0 && width > 0 && width > precision)
		j = width - precision;
	while (i < precision && i < (int)ft_strlen(str))
	{
		(*buff)[j] = str[i];
		i++;
		j++;
	}
	return (ft_strlen(*buff));
}

int			ft_cat(char **buff, t_lst *lst, int dir, int width)
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

int			conv_s(t_lst *lst, int width, int precision)
{
	char		*buff;
	int			dir;
	int			len;

	dir = 0;
	if (width < 0)
	{
		dir++;
		width = -width;
	}
	if (NULL == (buff = ft_strnew((1 + width + ft_strlen(lst->elt)) * sizeof(char))))
		return (-1);
	ft_add_n_char(&buff, ' ', width);
	if (precision > 0 && ft_strlen(lst->elt) > 0)
		reduce(&buff, lst, dir, width, precision);
	else
		ft_cat(&buff, lst, dir, width);
	len = ft_strlen(buff);
	if (lst->elt == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(buff);
	free(buff);
	return (len);
}

