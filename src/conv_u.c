#include <stdlib.h>
#include "ft_printf.h"

unsigned long long int	get_va_arg_u(t_lst *lst, va_list ap)
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

int			conv_u(t_lst *lst, va_list ap, int wth, int prc)
{
	char						*str;
	char						*buff;
	int							len;
	unsigned long long int		nb;
	int							w;

	len = 0;
	nb = get_va_arg_u(lst, ap);
	w = (wth < 0 ? -wth : wth);
	str = (w + prc != 0 && w + prc >= 20 ? ft_strnew(w + prc) : ft_strnew(20));
	ft_prntnum(nb, 10, ' ', str);
	buff = ft_strdup(str);
	prc = (prc <  (int)ft_strlen(str) ? 0 : prc);
	ft_add_char(lst, &str, wth, prc);
	ft_strdel(&buff);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
