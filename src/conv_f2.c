#include "ft_printf.h"

int			reduce_deci(t_lst *lst, signed long int deci)
{
	char	*buff;
	char	nb;
	int		i;

	nb = 0;
	if (lst->flg.prc == 0)
		return (deci);
	buff = ft_itoa(deci);
	i = ft_strlen(buff) - 1;
	while (i >= lst->flg.prc)
	{
		if (i == lst->flg.prc)
			nb = buff[i];
		buff[i] = ' ';
		i--;
	}
	deci = ft_atoi(buff);
	if (nb >= '5')
		deci++;
	ft_strdel(&buff);
	return (deci);
}

char		*alloc_str(t_lst *lst, long double nb, signed long int (*flt)[2])
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		len = 1;
		nb = -nb;
	}
	(*flt)[0] = (signed long int)nb;
	len += ft_nbrlen((*flt)[0]);
	nb -= (*flt)[0];
	nb *= 1000000;
	(*flt)[1] = (signed long int)(nb + 0.5);
	if ((*flt)[1] == 0)
		len += 6;
	else
	{
		(*flt)[1] = reduce_deci(lst, (*flt)[1]);
		len += ft_nbrlen((*flt)[1]) + 1;
	}
	if (lst->flg.wth < 0)
		lst->flg.wth = -lst->flg.wth;
	if (lst->flg.wth > 0 && lst->flg.wth > len)
		return (ft_strnew(lst->flg.wth + lst->flg.prc + (!(*flt)[1] ? 6 : 0)));
	return (ft_strnew(len + lst->flg.prc + (!(*flt)[1] ? 6 : 0)));
}
