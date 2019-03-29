#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int			print_all(t_lst *lst, va_list ap)
{
	t_lst		*tmp;
	int			len;
	int			tmp_len;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		if ((tmp_len = conversion_manager(tmp, ap)) < 0)
			return (tmp_len);
		len += tmp_len;
		tmp = tmp->next;
	}
	return (len);
}
