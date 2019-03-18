#include <stdlib.h>
#include "ft_printf.h"

unsigned long long int	get_va_arg_u(t_lst *lst, va_list ap)
{
	char			*buff;

	if ((buff = ft_strchr(lst->str, 'h')) != NULL)
	{
		if (*(buff + 1) == 'h')
			return ((unsigned char)va_arg(ap, unsigned int));
		return ((unsigned short int)va_arg(ap, unsigned int));
	}
	if ((buff = ft_strchr(lst->str, 'l')) != NULL)
	{
		if (*(buff + 1) == 'l')
			return (va_arg(ap, unsigned long long int));
		return (va_arg(ap, unsigned long int));
	}
	return (va_arg(ap, unsigned int));
}

int			conv_u(t_lst *lst, va_list ap, int wth, int prc)
{
	char	*str;
	unsigned long long int nb;
	int		len;

	if (wth > 0 && lst->str[0] == '-')
		wth = -wth;
	str = ft_strnew(16);
	nb = get_va_arg_u(lst, ap);
	ft_prntnum(nb, 10, ' ', str);
	prc = (prc <  (int)ft_strlen(str) ? 0 : prc);
	add_char(lst, &str, wth, prc);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
