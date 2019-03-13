#include <stdlib.h>
#include "ft_printf.h"

void		add_char(t_lst *lst, char **str, int wth, int prc)
{
	int		len;

	len = (int)ft_strlen(*str);
	if (prc)
	{
		ft_add_char_front('0', str, prc, len);
	}
	len = (int)ft_strlen(*str);
	if (wth && !prc && wth > len && ((lst->str)[0] == '0'
				|| (!ft_isdigit((lst->str)[0]) && (lst->str)[1] == '0')))
	{
		ft_add_char_front('0', str, wth, len);
	}
	else if (wth && wth > len)
	{
		ft_add_char_front(' ', str, wth, len);
	}
	len = (int)ft_strlen(*str);
	if (wth < 0)
	{
		ft_add_char_back(' ', str, (-wth) - len, len);
	}
}

