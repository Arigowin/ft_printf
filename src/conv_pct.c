#include <stdlib.h>
#include "ft_printf.h"

int			conv_pct(t_lst *lst, va_list ap)
{
	(void)lst;
	(void)ap;
	ft_putchar('%');
	return (1);
}

