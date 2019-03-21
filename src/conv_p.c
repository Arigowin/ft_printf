#include "ft_printf.h"

void		add_0x(void *ptr, char **str)
{
	int		i;
	int		j;

	i = 0;
	if (ptr == NULL)
		return ;
	while ((*str)[i] == '0')
		i++;
	ft_memset(*str, ' ', i);
	(*str)[i - 1] = 'x';
	(*str)[i - 2] = '0';
	j = 0;
	i -= 2;
	while ((*str)[i])
		(*str)[j++] = (*str)[i++];
	ft_memset(*str + j, '\0', i);
}

int			conv_p(t_lst *lst, va_list ap, int wth, int prc)
{
	char		buff[15];
	char		*str;
	void		*ptr;
	int			w;
	int			len;

	(void)prc;
	w = (wth < 0 ? -wth : wth);
	str = ft_strnew(16 + w);
	ptr = va_arg(ap, void *);
	if (ptr == NULL)
		ft_memcpy(buff, "(nil)", 5);
	else
		ft_ptr_to_hex(ptr, &buff);
	ft_memcpy(str, buff, 16);
	if ((lst->str)[0] == '0' || (!ft_isdigit((lst->str)[0])
				&& (lst->str)[1] == '0'))
		(lst->str)[((lst->str)[0] == '0' ? 0 : 1)] = ' ';
	add_0x(ptr, &str);
	ft_add_char(lst, &str, wth, 0);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
