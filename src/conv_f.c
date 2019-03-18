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
	free(buff);
	return (deci);
}

char		*alloc_str(long double nb, signed long int (*flt)[2],int wth, int prc)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		len = 1;
		nb = -nb;
	}
	(*flt)[0] = (signed long int)nb;
	len += ft_strlen(ft_itoa((*flt)[0])) + 1;
	nb -= (*flt)[0];
	nb *= 1000000;
	(*flt)[1] = (signed long int)(nb + 0.5);
	if ((*flt)[1] == 0)
		len += 6;
	else
	{
		(*flt)[1] = reduce_deci((*flt)[1], prc);
		len += ft_strlen(ft_itoa((*flt)[1]));
	}
	if (wth < 0)
		wth = -wth;
	if (wth > 0 && wth > len)
		return (ft_strnew(wth + prc));
	return (ft_strnew(len + 1 + prc));
}

char		*raise_deci(long double nb, int prc)
{
	char	*str;

	str = ft_itoa(nb);
	if ((int)ft_strlen(str) > prc)
		return (str);
	ft_add_char_front('0', &str, prc, ft_strlen(str));
	return (str);
}

int			conv_f(t_lst *lst, va_list ap, int wth, int prc)
{
	char			*str;
	long double		nb;
	signed long int flt[2];
	int				len;

	nb = get_va_arg_f(lst, ap);
	str = alloc_str(nb, &flt, wth, prc);
	if (nb < 0)
	{
		str[0] = 1;
		nb *= -1;
	}
	ft_strcat(str, ft_itoa(flt[0]));
	ft_strcat(str, ".");
	if (flt[1] == 0 && prc == 0)
		ft_strcat(str, "000000");
	else
		ft_strcat(str, raise_deci(flt[1], prc));
	add_char(lst, &str, wth, 0);
	len = ft_strlen(str);
	if (str[0] != ' ' && ft_strchr(lst->str, ' '))
	{
		ft_putchar(' ');
		len++;
	}
	ft_putstr(str);
	return (len);
}
