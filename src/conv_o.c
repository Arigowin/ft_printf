#include <stdlib.h>
#include "ft_printf.h"

void		add_o(char **str, int width)
{
	char	*buff;
	int		i;
	int		j;
	int		len;

	i = 0;
	if (width <= 0)
	{
		len = (!width ? ft_strlen(*str) + 1 : ft_strlen(*str));
		buff = ft_strnew(len);
		j = 1;
		while (j < len)
			buff[j++] = (*str)[i++];
		buff[0] = '0';
		free(*str);
		*str = buff;
	}
	else
	{
		while (!ft_isdigit((*str)[i]))
			i++;
		(*str)[(i < 0 ? 0 : i - 1)] = '0';
	}
}

int			conv_o(t_lst *lst, int width, int precision)
{
	char				*str;
	int					len;
	unsigned int		nb;
	int					w;

	len = 0;
	nb = (unsigned int)lst->elt;
	w = (width < 0 ? -width : width);
	str = (w + precision != 0 ? ft_strnew(w + precision) : ft_strnew(13));
	ft_prntnum(nb, 8, ' ', str);
	precision = (precision <  (int)ft_strlen(str) ? 0 : precision);
	add_char(lst, &str, width, precision);
	if (ft_strchr(lst->str, '#') && nb > 0)
		add_o(&str, width);
	if (lst->type == LHEX)
		ft_putstr(str);
	else
		ft_putupper(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
