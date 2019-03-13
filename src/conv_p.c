#include "ft_printf.h"

int			conv_p(t_lst *lst, int wth, int prc)
{
	char		buff[15];
	char		*str;
	int			i;
	int			w;

	(void)prc;
	w = (wth < 0 ? -wth : wth);
	str = ft_strnew(16 + w);
	if (lst->elt == NULL)
		ft_memcpy(buff, "(nil)", 5);
	else
		ft_ptr_to_hex(lst->elt, &buff);
	ft_memcpy(str, buff, 16);
	i = 0;
	while (str[i] == '0')
		i++;
	if ((lst->str)[0] == '0' || (!ft_isdigit((lst->str)[0])
				&& (lst->str)[1] == '0'))
		(lst->str)[((lst->str)[0] == '0' ? 0 : 1)] = ' ';
	add_char(lst, &str, wth, 0);
	if (lst->elt != NULL)
		ft_putstr("0x");
	ft_putstr(str + i);
	return (ft_strlen(str + i) + (lst->elt != NULL ? 2 : 0));
}
