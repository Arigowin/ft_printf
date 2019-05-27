#include <libft.h>
#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_lst		*lst;
	int			len;

	lst = NULL;
	va_start(ap, format);
	parse(&lst, format);
	len = print_all(lst, ap);
	lst_free(&lst);
	va_end(ap);
	return (len);
}
