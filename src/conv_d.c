#include <stdlib.h>
#include "ft_printf.h"

long long int	get_va_arg_d(t_lst *lst, va_list ap)
{
	char			*buff;

	if ((buff = ft_strchr(lst->str, 'h')) != NULL)
	{
		if (*(buff + 1) == 'h')
			return ((char)va_arg(ap, int));
		return ((short int)va_arg(ap, int));
	}
	if ((buff = ft_strchr(lst->str, 'l')) != NULL)
	{
		if (*(buff + 1) == 'l')
			return (va_arg(ap, long long int));
		return (va_arg(ap, long int));
	}
	return (va_arg(ap, int));
}

char		*alloc_buff(long long int nb, int wth, int prc)
{
	char	*buff;
	char	*tmp;
	int		len;

	if (wth < 0)
		wth = -wth;
	tmp = ft_itoa(nb);
	len = ft_strlen(tmp);
	if (wth + prc > len)
		buff = ft_strnew(wth + prc);
	else
		buff = ft_strnew(len);
	ft_memcpy(buff, tmp, len);
	ft_strdel(&tmp);
	return (buff);
}

void		more_d(t_lst *lst, char **str, int nb, int prc, int wth)
{
	if (prc == 0 && ft_strchr(lst->str, '.')
			&& nb == 0 && wth != 0)
		ft_memset(*str, ' ', ft_strlen(*str));
	else if (prc == 0 && ft_strchr(lst->str, '.')
			&& nb == 0)
		ft_bzero(*str, ft_strlen(*str));
}

int			conv_d(t_lst *lst, va_list ap, int wth, int prc)
{
	char			*str;
	long long int	nb;
	int				len;
	int				syb[2];

	nb = get_va_arg_d(lst, ap);
	str = alloc_buff(nb, wth, prc);
	if (wth > 0 && lst->str[0] == '-')
		wth = -wth;
	syb[0] = ft_remove_char('-', &str);
	syb[1] = (ft_strchr(lst->str, '+') ? 1 : ft_remove_char('+', &str));
	if (prc != 0)
		prc = (prc < (int)ft_strlen(str) ? -1 : prc);
	if (wth > 0)
		wth = wth - (syb[1] ? syb[1] : syb[0]);
	else
		wth = wth + (syb[1] ? syb[1] : syb[0]);
	ft_add_char(lst, &str, wth, prc);
	ft_add_symbole(lst, &str, wth, prc, syb);
	more_d(lst, &str, nb, prc, wth);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
