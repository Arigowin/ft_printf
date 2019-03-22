#include <stdlib.h>
#include "ft_printf.h"

#include <stdio.h>

long long int	get_va_arg_x(t_lst *lst, va_list ap)
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

void		add_x(t_lst *lst, char **str)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	if (((*str)[0] == ' ' && (*str)[1] == ' ')
			|| ((lst->str)[0] == '0' && !ft_strchr(lst->str, '.')))
	{
		while ((*str)[i] && !ft_strchr("0123456789abcdef", (*str)[i]))
			i++;
		(*str)[(i <= 2 ? 0 : i - 2)] = '0';
		(*str)[(i <= 1 ? 1 : i - 1)] = 'x';
	}
	else
	{
		if ((*str)[ft_strlen(*str) - 1] == ' ')
		{
			i = 0;
			while ((*str)[i] && ft_strchr("0123456789abcdef", (*str)[i]))
				i++;
			j = i + 2;
			while (i > -1)
				(*str)[j--] = (*str)[i--];
			(*str)[0] = '0';
			(*str)[1] = 'x';
		}
		else
		{
			i = ((*str)[0] == ' ' && (*str)[1] != ' ' ? 1 : 2);
			buff = ft_strnew(ft_strlen(*str) + i);
			ft_memcpy(buff + i, *str, ft_strlen(*str));
			ft_strdel(str);
			buff[0] = '0';
			buff[1] = 'x';
			*str = buff;
		}
	}
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

int			conv_x(t_lst *lst, va_list ap, int wth, int prc)
{
	char						*buff;
	char						*str;
	int							len;
	unsigned long long int		nb;
	int							w;

	len = 0;
	nb = get_va_arg_x(lst, ap);
	w = (wth < 0 ? -wth : wth);
	str = (w + prc != 0 && w + prc >= 20 ? ft_strnew(w + prc) : ft_strnew(20));
	ft_prntnum(nb, 16, ' ', str);
	buff = ft_strdup(str);
	prc = (prc < (int)ft_strlen(str) && nb != 0 && prc != 0 ? -1 : prc);
	if (nb > 0 && ft_strchr(lst->str, '#') && (int)ft_strlen(buff) + 2 > w && prc <= 0)
		wth = 0;
	ft_add_char(lst, &str, wth, prc);
	printf("{wth: %d, w: %d, prc: %d, lst->str: [%s], buff: [%s], s: [%s]}\n", wth, w, prc, lst->str, buff, str);
	if (ft_strchr(lst->str, '#') && nb > 0)
		add_x(lst, &str);
	ft_strdel(&buff);
	more_x(lst, &str, nb, prc, wth);
	if (lst->type == LHEX)
		ft_putstr(str);
	else
		ft_putupper(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

