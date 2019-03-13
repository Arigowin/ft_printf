#include <stdlib.h>
#include "ft_printf.h"

void		add_x(char **str, int wth)
{
	char	*buff;
	int		i;
	int		j;
	int		len;

	i = 0;
	if (wth <= 0)
	{
		len = (wth != 0 ? ft_strlen(*str) + (-wth - (int)ft_strlen(*str))
				: ft_strlen(*str) + 2);
		buff = ft_strnew(len);
		j = 2;
		while (j < len)
			buff[j++] = (*str)[i++];
		buff[0] = '0';
		buff[1] = 'x';
		free(*str);
		*str = buff;
		return ;
	}
	while (!ft_isdigit((*str)[i]))
		i++;
	(*str)[(i < 1 ? 0 : i - 2)] = '0';
	(*str)[(i < 1 ? 1 : i - 1)] = 'x';
}

void		more_x(t_lst *lst, char **str, unsigned long long int nb, int prc, int wth)
{
	if (prc == 0 && ft_strchr(lst->str, '.')
			&& nb == 0 && wth != 0)
		ft_memset(*str, ' ', ft_strlen(*str));
	else if (prc == 0 && ft_strchr(lst->str, '.')
			&& nb == 0)
		ft_bzero(*str, ft_strlen(*str));
}

int			conv_x(t_lst *lst, int wth, int prc)
{
	char				*str;
	int					len;
	unsigned long long int		nb;
	int					w;

	len = 0;
	nb = (unsigned int)lst->elt;
	w = (wth < 0 ? -wth : wth);
	str = (w + prc != 0 ? ft_strnew(w + prc) : ft_strnew(20));
	ft_prntnum(nb, 16, ' ', str);
	prc = (prc <  (int)ft_strlen(str) ? 0 : prc);
	if (!ft_strchr(lst->str, '#') || (int)ft_strlen(str) + 2 <= w)
		add_char(lst, &str, wth, prc);
	if (ft_strchr(lst->str, '#') && nb > 0)
		add_x(&str, wth);
	more_x(lst, &str, nb, prc, wth);
	if (lst->type == LHEX)
		ft_putstr(str);
	else
		ft_putupper(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

