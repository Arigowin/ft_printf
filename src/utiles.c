#include <stdlib.h>
#include "ft_printf.h"

void		add_char(t_lst *lst, char **str, int width, int precision)
{
	int		len;

	len = (int)ft_strlen(*str);
	if (precision)
		ft_add_char_front('0', str, precision, len);
	len = (int)ft_strlen(*str);
	if (width && !precision && width > len && ((lst->str)[0] == '0'
				|| (lst->str)[1] == '0'))
		ft_add_char_front('0', str, width, len);
	else if (width && width > len)
		ft_add_char_front(' ', str, width, len);
	len = (int)ft_strlen(*str);
	if (width < 0)
		ft_add_char_back(' ', str, (-width) - len, len);
}

