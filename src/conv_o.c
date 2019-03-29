#include <stdlib.h>
#include "ft_printf.h"

long long int	get_va_arg_o(t_lst *lst, va_list ap)
{
	if (lst->flg.hh)
		return ((unsigned char)va_arg(ap, unsigned int));
	if (lst->flg.h)
		return ((unsigned short int)va_arg(ap, unsigned int));
	if (lst->flg.ll)
		return (va_arg(ap, unsigned long long int));
	if (lst->flg.l)
		return (va_arg(ap, unsigned long int));
	return (va_arg(ap, unsigned int));
}

int			search_o(char *str, char *nb)
{
	char	*tmp;

	tmp = ft_strstr(str, nb);
	if (ft_strcmp(str, tmp) == 0 || (tmp - 1)[0] != '0')
		return (1);
	return (0);
}

void		add_o(t_lst *lst, char **str, char *nb)
{
	char	*buff;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(nb);
	if (lst->flg.wth <= 0 || ((lst->flg.wth < 0 && len >= -lst->flg.wth)
				|| len >= lst->flg.wth))
	{
		if ((*str)[ft_strlen(*str) - 1] == ' ')
		{
			(*str)[0] = '0';
			i = -1;
			while (nb[++i])
				(*str)[i + 1] = nb[i];
		}
		else
		{
			buff = ft_strnew(ft_strlen(*str) + 1);
			buff[0] = '0';
			ft_memcpy(buff + 1, *str, ft_strlen(*str));
			ft_strdel(str);
			*str = buff;
		}
	}
	else
	{
		while ((*str)[i] && !ft_isdigit((*str)[i]))
			i++;
		(*str)[(i <= 0 ? 0 : i - 1)] = '0';
	}
}

void		more_o(t_lst *lst, char **str, unsigned int nb)
{
	if (!lst->flg.prc && lst->flg.point && !nb && lst->flg.wth)
		ft_memset(*str, ' ', ft_strlen(*str));
	else if (!lst->flg.prc && lst->flg.point && !nb && !lst->flg.sharp)
		ft_bzero(*str, ft_strlen(*str));
}

int			conv_o(t_lst *lst, va_list ap)
{
	char						*str;
	char						*buff;
	int							len;
	unsigned long long int		nb;
	int							w;

	len = 0;
	nb = get_va_arg_o(lst, ap);
	w = (lst->flg.wth < 0 ? -lst->flg.wth : lst->flg.wth);
	str = (w + lst->flg.prc && w + lst->flg.prc >= 20 ?
			ft_strnew(w + lst->flg.prc) : ft_strnew(20));
	ft_prntnum(nb, 8, ' ', str);
	buff = ft_strdup(str);
	lst->flg.prc = (lst->flg.prc <  (int)ft_strlen(str) ? 0 : lst->flg.prc);
	ft_add_char(lst, &str);
	if (lst->flg.sharp && nb > 0 && search_o(str, buff))
		add_o(lst, &str, buff);
	ft_strdel(&buff);
	more_o(lst, &str, nb);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
