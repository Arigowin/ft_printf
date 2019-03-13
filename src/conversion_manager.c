#include <stdlib.h>
#include "ft_printf.h"

int			no_conv(t_lst *lst, int wth, int prc)
{
	(void)wth;
	(void)prc;
	ft_putstr(lst->str);
	return (ft_strlen(lst->str));
}

int			conv_pct(t_lst *lst, int wth, int prc)
{
	(void)wth;
	(void)prc;
	(void)lst;
	ft_putchar('%');
	return (1);
}

int			conversion_manager(t_lst *lst, int wth, int prc)
{
	int		(*fct[11])(t_lst *, int, int) = {no_conv, conv_s, conv_d, conv_c,
		conv_p, conv_o, conv_u, conv_x, conv_x, NULL, conv_pct};
	int		len;

	len = 0;
	// SEGFAULT FOR NOW REMOVE THIS AFTER ADD OTHER FLAGS
	if (lst->type > 10 || lst->type == FLT)
		return (-1);
	len = fct[lst->type](lst, wth, prc);
	return (len);
}
