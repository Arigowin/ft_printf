#include <stdlib.h>
#include "ft_printf.h"

double		get_va_arg_f(t_lst *lst, va_list ap)
{
	char			*buff;

	if ((buff = ft_strchr(lst->str, 'L')) != NULL)
		return (va_arg(ap, long double));
	return (va_arg(ap, double));
}

int			reduce_deci(signed long int deci, int prc)
{
	char	*buff;
	char	nb;
	int		i;

	nb = 0;
	if (prc == 0)
		return (deci);
	buff = ft_itoa(deci);
	i = ft_strlen(buff) - 1;
	while (i >= prc)
	{
		if (i == prc)
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

char		*alloc_str(long double nb, signed long int (*flt)[2],
		int wth, int prc)
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
		(*flt)[1] = reduce_deci((*flt)[1], prc);
		len += ft_nbrlen((*flt)[1]) + 1;
	}
	if (wth < 0)
		wth = -wth;
	if (wth > 0 && wth > len)
		return (ft_strnew(wth + prc + ((*flt)[1] == 0 ? 6 : 0)));
	return (ft_strnew(len + prc + ((*flt)[1] == 0 ? 6 : 0)));
}

void		raise_deci(char **str, long double nb, int prc)
{
	char	*tmp;
	char	*buff;

	tmp = ft_itoa(nb);
	if ((int)ft_strlen(tmp) > prc)
	{
		ft_strcat(*str, tmp);
		ft_strdel(&tmp);
		return ;
	}
	buff = ft_strnew(prc);
	ft_strcat(buff, tmp);
	ft_strdel(&tmp);
	ft_add_char_front('0', &buff, prc, ft_strlen(tmp));
	ft_strcat(*str, buff);
	ft_strdel(&buff);
}

int			conv_f(t_lst *lst, va_list ap, int wth, int prc)
{
	char			*str;
	long double		nb;
	signed long int flt[2];
	int				syb[2];
	int				len;

	nb = get_va_arg_f(lst, ap);
	str = alloc_str(nb, &flt, wth, prc);
	if (wth > 0 && lst->str[0] == '-')
		wth = -wth;
	syb[0] = (nb < 0 ? 1 : ft_remove_char('-', &str));
	syb[1] = ft_remove_char('+', &str);
	syb[1] = (ft_strchr(lst->str, '+') ? 1 : syb[1]);
	if (wth > 0)
		wth = wth - (syb[1] ? syb[1] : syb[0]);
	else
		wth = wth + (syb[1] ? syb[1] : syb[0]);
	char *tmp;
	tmp = ft_itoa(flt[0]);
	ft_strcat(str, tmp);
	ft_strdel(&tmp);
	ft_strcat(str, ".");
	if (flt[1] == 0 && prc == 0)
		ft_strcat(str, "000000");
	else
		raise_deci(&str, flt[1], prc);
	ft_add_char(lst, &str, wth, 0);
	ft_add_symbole(lst, &str, wth, prc, syb);
	len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (len);
}
