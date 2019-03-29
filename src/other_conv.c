#include <stdlib.h>
#include "ft_printf.h"

void		remove_char(char **str, char *s2)
{
	char	*buff;
	size_t	i;
	size_t	j;

	buff = ft_strnew(ft_strlen(*str));
	i = 0;
	j = 0;
	while ((*str)[i])
	{
		if (!ft_strchr(s2, (*str)[i]))
			buff[j++] = (*str)[i];
		i++;
	}
	ft_strdel(str);
	*str = buff;
}

int			print_flag(char c)
{
	ft_putchar(c);
	return (1);
}

int			print_flags(t_lst *lst)
{
	int		len;

	len = 0;
	if (lst->flg.spc)
		len += print_flag(' ');
	if (lst->flg.sharp)
		len += print_flag('#');
	if (lst->flg.pls)
		len += print_flag('+');
	if (lst->flg.mns)
		len += print_flag('-');
	if (lst->flg.zero)
		len += print_flag('0');
	return (len);
}

int			other_conv(t_lst *lst, va_list ap)
{
	int		len;

	(void)ap;
	len = 1;
	remove_char(&(lst->str), "#-+ lhL");
	if (lst->flg.zero)
		ft_remove_char('0', &(lst->str));
	ft_putchar('%');
	len += print_flags(lst);
	ft_putstr(lst->str);
	len += ft_strlen(lst->str);
	return (len);
}
