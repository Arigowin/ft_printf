#include <stdlib.h>
#include "ft_printf.h"

int			conv_u(t_lst *lst, int width, int precision)
{
	char	*str;
	int		len;

	if (width > 0 && lst->str[0] == '-')
		width = -width;
	str = ft_strnew(16);
	ft_prntnum((unsigned int)lst->elt, 10, ' ', str);
	precision = (precision <  (int)ft_strlen(str) ? 0 : precision);
	add_char(lst, &str, width, precision);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
