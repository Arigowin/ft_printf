#include <stdarg.h>
#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_lst		*lst;
	int			len;

	lst = NULL;
	if (format == NULL || ft_strlen(format) == 0)
	{
		ft_putstr_fd("The firt arg cannot be NULL or empty\n", 2);
		return (-1);
	}
	va_start(ap, format);
	parse(&lst, ap, format);
	len = print_all(lst);
	va_end(ap);
	return (len);
}
