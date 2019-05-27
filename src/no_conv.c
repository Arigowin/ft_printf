#include <libft.h>
#include "ft_printf.h"

int			no_conv(t_lst *lst, va_list ap)
{
	(void)ap;
	ft_putstr(lst->str);
	return (ft_strlen(lst->str));
}
