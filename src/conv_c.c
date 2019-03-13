#include "ft_printf.h"

int			conv_c(t_lst *lst, int wth, int prc)
{
	int			len;

	len = 1;
	(void)prc;
	if (wth > 0)
	{
		ft_print_n_char(' ', wth - 1);
		len = wth;
	}
	ft_putchar((char)lst->elt);
	if (wth < 0)
	{
		ft_print_n_char(' ', (-wth) - 1);
		len = -wth;
	}
	return (len);
}
