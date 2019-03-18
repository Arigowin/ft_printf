#include <stdlib.h>
#include "ft_printf.h"

void		add_o(char **str, int wth)
{
	char	*buff;
	int		i;
	int		j;
	int		len;

	i = 0;
	if (wth <= 0)
	{
		len = (!wth ? ft_strlen(*str) + 1 : ft_strlen(*str));
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

void		more_o(t_lst *lst, char **str, unsigned int nb, int prc, int wth)
{
	if (prc == 0 && ft_strchr(lst->str, '.')
			&& nb == 0 && wth != 0)
		ft_memset(*str, ' ', ft_strlen(*str));
	else if (prc == 0 && ft_strchr(lst->str, '.')
			&& nb == 0 && !ft_strchr(lst->str, '#'))
	{
		ft_bzero(*str, ft_strlen(*str));
	}
}

int			conv_o(t_lst *lst, va_list ap, int wth, int prc)
{
	char				*str;
	int					len;
	unsigned int		nb;
	int					w;

	len = 0;
	nb = va_arg(ap, unsigned int);
	w = (wth < 0 ? -wth : wth);
	str = (w + prc != 0 ? ft_strnew(w + prc) : ft_strnew(13));
	ft_prntnum(nb, 8, ' ', str);
	prc = (prc <  (int)ft_strlen(str) ? 0 : prc);
	add_char(lst, &str, wth, prc);
	if (ft_strchr(lst->str, '#') && nb > 0)
		add_o(&str, wth);
	more_o(lst, &str, nb, prc, wth);
	if (lst->type == LHEX)
		ft_putstr(str);
	else
		ft_putupper(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
