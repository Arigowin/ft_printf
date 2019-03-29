#include <stdlib.h>
#include "ft_printf.h"

unsigned long long int	get_va_arg_u(t_lst *lst, va_list ap)
{
	if(lst->flg.hh)
		return ((unsigned char)va_arg(ap, unsigned int));
	if(lst->flg.h)
		return ((unsigned short int)va_arg(ap, unsigned int));
	if(lst->flg.ll)
		return (va_arg(ap, unsigned long long int));
	if(lst->flg.l)
		return (va_arg(ap, unsigned long int));
	return (va_arg(ap, unsigned int));
}

int			conv_u(t_lst *lst, va_list ap)
{
	char						*str;
	char						*buff;
	int							len;
	unsigned long long int		nb;
	int							w;

	len = 0;
	nb = get_va_arg_u(lst, ap);
	w = (lst->flg.wth < 0 ? -lst->flg.wth : lst->flg.wth);
	str = (w + lst->flg.prc && w + lst->flg.prc >= 20 ?
			ft_strnew(w + lst->flg.prc) : ft_strnew(20));
	ft_prntnum(nb, 10, ' ', str);
	buff = ft_strdup(str);
	lst->flg.prc = (lst->flg.prc < (int)ft_strlen(str) ? 0 : lst->flg.prc);
	ft_add_char(lst, &str);
	ft_strdel(&buff);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
