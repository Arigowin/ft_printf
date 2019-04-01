#include <stdlib.h>
#include <math.h>
#include "ft_printf.h"

double		get_va_arg_f(t_lst *lst, va_list ap)
{
	if (lst->flg.L)
		return (va_arg(ap, long double));
	return (va_arg(ap, double));
}

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

void		raise_deci(t_lst *lst, char **str, long double nb)
{
	char	*tmp;
	char	*buff;

	tmp = ft_itoa(nb);
	if ((int)ft_strlen(tmp) > lst->flg.prc)
	{
		ft_strcat(*str, tmp);
		ft_strdel(&tmp);
		return ;
	}
	buff = ft_strnew(lst->flg.prc);
	ft_strcat(buff, tmp);
	ft_strdel(&tmp);
	ft_add_char_front('0', &buff, lst->flg.prc, ft_strlen(tmp));
	ft_strcat(*str, buff);
	ft_strdel(&buff);
}

int			conv_f(t_lst *lst, va_list ap)
{
	char			*str;
	char			*tmp;
	long double		nb;
	signed long int flt[2];
	int				syb[2];
	int				len;

	nb = get_va_arg_f(lst, ap);
	str = alloc_str(lst, nb, &flt);
	if (lst->flg.wth > 0 && lst->flg.mns)
		lst->flg.wth = -lst->flg.wth;
	syb[0] = (nb < 0 ? 1 : ft_remove_char('-', &str));
	syb[1] = ft_remove_char('+', &str);
	syb[1] = (lst->flg.pls ? 1 : syb[1]);
	if (lst->flg.wth > 0)
		lst->flg.wth = lst->flg.wth - (syb[1] ? syb[1] : syb[0]);
	else
		lst->flg.wth = lst->flg.wth + (syb[1] ? syb[1] : syb[0]);
	tmp = ft_itoa(flt[0]);
	if (nb != nb)
	{
		ft_putstr("nan");
		return (3);
	}
	ft_strcat(str, tmp);
	ft_strdel(&tmp);
	ft_strcat(str, ".");
	if (flt[1] == 0 && lst->flg.prc == 0)
		ft_strcat(str, "000000");
	else
		raise_deci(lst, &str, flt[1]);
	lst->flg.prc = 0;
	ft_add_char(lst, &str);
	ft_add_symbole(lst, &str, syb);
	len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (len);
}
