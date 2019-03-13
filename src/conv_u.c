#include <stdlib.h>
#include "ft_printf.h"

int			conv_u(t_lst *lst, int wth, int prc)
{
	char	*str;
	int		len;

	if (wth > 0 && lst->str[0] == '-')
		wth = -wth;
	str = ft_strnew(16);
	ft_prntnum((unsigned int)lst->elt, 10, ' ', str);
	prc = (prc <  (int)ft_strlen(str) ? 0 : prc);
	add_char(lst, &str, wth, prc);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
