#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int			print_all(t_lst *lst)
{
	t_lst		*tmp;
	int			len;
	int			tmp_len;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		if (ft_strlen(tmp->str) == 1 || tmp->type == DFLT)
		{ // no option
			if ((tmp_len = exec_type(tmp)) == -1)
				return (-1);
			len += tmp_len;
		}
		else
		{ // option
			if ((tmp_len = exec_opt(tmp)) == -1)
				return (-1);
			len += tmp_len;
		}
		tmp = tmp->next;
	}
	return (len);
}
