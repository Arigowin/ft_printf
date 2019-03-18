#include "ft_printf.h"

int			conv_p(t_lst *lst, va_list ap, int wth, int prc)
{
	char		buff[15];
	char		*str;
	void		*ptr;
	int			i;
	int			w;

	(void)prc;
	w = (wth < 0 ? -wth : wth);
	str = ft_strnew(16 + w);
	ptr = va_arg(ap, void *);
	if (ptr == NULL)
		ft_memcpy(buff, "(nil)", 5);
	else
		ft_ptr_to_hex(ptr, &buff);
	ft_memcpy(str, buff, 16);
	i = 0;
	while (str[i] == '0')
		i++;
	if ((lst->str)[0] == '0' || (!ft_isdigit((lst->str)[0])
				&& (lst->str)[1] == '0'))
		(lst->str)[((lst->str)[0] == '0' ? 0 : 1)] = ' ';
	add_char(lst, &str, wth, 0);
	if (ptr != NULL)
		ft_putstr("0x");
	ft_putstr(str + i);
	return (ft_strlen(str + i) + (ptr != NULL ? 2 : 0));
}
