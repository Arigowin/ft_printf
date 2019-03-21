#include <stdlib.h>
#include "ft_printf.h"

long long int	get_va_arg_o(t_lst *lst, va_list ap)
{
	char			*buff;

	if ((buff = ft_strchr(lst->str, 'h')) != NULL)
	{
		if (*(buff + 1) == 'h')
			return ((unsigned char)va_arg(ap, unsigned int));
		return ((unsigned short int)va_arg(ap, unsigned int));
	}
	if ((buff = ft_strchr(lst->str, 'l')) != NULL)
	{
		if (*(buff + 1) == 'l')
			return (va_arg(ap, unsigned long long int));
		return (va_arg(ap, unsigned long int));
	}
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

void		add_o(char **str, char *nb, int wth)
{
	char	*buff;
	int		i;
	int		j;
	int		len;

	i = 0;
	if (wth <= 0 || ft_strlen(*str) == ft_strlen(nb))
	{
		len = (wth >= 0 ? ft_strlen(*str) + 1 : ft_strlen(*str));
		buff = ft_strnew(len + 1);
		j = 1;
		while (i < len)
			buff[j++] = (*str)[i++];
		buff[0] = '0';
		ft_strdel(str);
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
	char						*str;
	char						*buff;
	int							len;
	unsigned long long int		nb;
	int							w;

	len = 0;
	nb = get_va_arg_o(lst, ap);
	w = (wth < 0 ? -wth : wth);
	str = (w + prc != 0 && w + prc >= 20 ? ft_strnew(w + prc) : ft_strnew(20));
	ft_prntnum(nb, 8, ' ', str);
	buff = ft_strdup(str);
	prc = (prc <  (int)ft_strlen(str) ? 0 : prc);
	ft_add_char(lst, &str, wth, prc);
	if (ft_strchr(lst->str, '#') && nb > 0 && search_o(str, buff))
		add_o(&str, buff, wth);
	ft_strdel(&buff);
	more_o(lst, &str, nb, prc, wth);
	if (lst->type == LHEX)
		ft_putstr(str);
	else
		ft_putupper(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
