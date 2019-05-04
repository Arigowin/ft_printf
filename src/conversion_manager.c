#include <stdlib.h>
#include "ft_printf.h"

int			conversion_manager(t_lst *lst, va_list ap)
{
	int		(*fct[12])(t_lst *, va_list) = {no_conv, other_conv, conv_s,
		conv_d, conv_c, conv_p, conv_o, conv_u, conv_x, conv_x, conv_f,
		conv_pct};
	int		len;

	len = 0;
	if (lst->type > 11)
		return (-1);
	len = fct[lst->type](lst, ap);
	return (len);
}
