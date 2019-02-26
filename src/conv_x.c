#include <stdlib.h>
#include "ft_printf.h"

void		add_x(char **str, int width)
{
	char	*buff;
	int		i;
	int		j;
	int		len;

	i = 0;
	if (width <= 0)
	{
		len = (!width ? ft_strlen(*str) + 2 : ft_strlen(*str));
		buff = ft_strnew(len);
		j = 2;
		while (j < len)
			buff[j++] = (*str)[i++];
		buff[0] = '0';
		buff[1] = 'x';
		free(*str);
		*str = buff;
	}
	else
	{
		while (!ft_isdigit((*str)[i]))
			i++;
		(*str)[(i < 1 ? 0 : i - 2)] = '0';
		(*str)[(i < 1 ? 1 : i - 1)] = 'x';
	}
}

int			conv_x(t_lst *lst, int width, int precision)
{
	char				*str;
	int					len;
	unsigned int		nb;
	int					w;

	len = 0;
	nb = (unsigned int)lst->elt;
	w = (width < 0 ? -width : width);
	str = (w + precision != 0 ? ft_strnew(w + precision) : ft_strnew(13));
	ft_prntnum(nb, 16, ' ', str);
	precision = (precision <  (int)ft_strlen(str) ? 0 : precision);
	add_char(lst, &str, width, precision);
	if (lst->str[0] == '#' && nb > 0)
		add_x(&str, width);
	if (lst->type == LHEX)
		ft_putstr(str);
	else
		ft_putupper(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

