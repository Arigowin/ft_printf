#include <stdarg.h>
#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_lst		*lst;
	int			len;

	lst = NULL;
	if (format == NULL)
	{
		ft_putstr_fd("The firt arg cannot be NULL\n", 2);
		return (-1);
	}
	if (ft_strchr(format, '*') || ft_strchr(format, '$'))
	{
		ft_putstr_fd("The flags [*$] are not available", 2);
		return (-1);
	}
	va_start(ap, format);
	parse(&lst, format);
	len = print_all(lst, ap);
	lst_free(&lst);
	va_end(ap);
	return (len);
}
