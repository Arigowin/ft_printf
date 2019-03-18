#include <stdlib.h>
#include "ft_printf.h"

int			no_conv(t_lst *lst, va_list ap, int wth, int prc)
{
	(void)wth;
	(void)prc;
	(void)ap;
	if (ft_strchr(lst->str, '%'))
	{
		char   *buff;
		size_t i;
		size_t j;

		i = 0;
		j = 0;
		buff = ft_strnew(ft_strlen(lst->str));
		while (i < ft_strlen(lst->str))
		{
			if (!ft_strchr("lh", (lst->str)[i]))
				buff[j++] = (lst->str)[i];
			i++;
		}
		ft_putstr(buff);
		return (ft_strlen(buff));
	}
	ft_putstr(lst->str);
	return (ft_strlen(lst->str));
}

int			conv_pct(t_lst *lst, va_list ap, int wth, int prc)
{
	(void)wth;
	(void)prc;
	(void)lst;
	(void)ap;
	ft_putchar('%');
	return (1);
}

int			conversion_manager(t_lst *lst, va_list ap, int wth, int prc)
{
	int		(*fct[11])(t_lst *, va_list, int, int) = {no_conv, conv_s, conv_d,
		conv_c, conv_p, conv_o, conv_u, conv_x, conv_x, conv_f, conv_pct};
	int		len;

	len = 0;
	// SEGFAULT FOR NOW REMOVE THIS AFTER ADD OTHER FLAGS
	if (lst->type > 10)
		return (-1);
	len = fct[lst->type](lst, ap, wth, prc);
	return (len);
}
