#include "ft_printf.h"

int			conv_c(t_lst *lst, va_list ap, int wth, int prc)
{
	int			len;

	len = 1;
	(void)prc;
	(void)lst;
	if (wth > 0)
	{
		ft_print_n_char(' ', wth - 1);
		len = wth;
	}
	ft_putchar(va_arg(ap, int));
	if (wth < 0)
	{
		ft_print_n_char(' ', (-wth) - 1);
		len = -wth;
	}
	return (len);
}
