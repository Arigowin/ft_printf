#include <stdlib.h>
#include "ft_printf.h"

char		*alloc_buff(char *str, int width, int precision)
{
	char	*buff;

	if (width < 0)
		width = -width;
	if (width + precision > (int)ft_strlen(str))
		buff = ft_strnew(width + precision);
	else
		buff = ft_strnew(ft_strlen(str));
	ft_memcpy(buff, str, ft_strlen(str));
	free(str);
	return (buff);
}

char		*add_syb(char c, char *str)
{
	char	*buff;
	int		i;
	int		j;
	int		syb;

	syb = 0;
	buff = ft_strnew(ft_strlen(str) + 1);
	while (!ft_isdigit(str[syb]) && syb < (int)ft_strlen(str))
		syb++;
	if (syb == (int)ft_strlen(str))
		return (str);
	i = 0;
	j = 0;
	while (str[i] && i < syb)
		buff[j++] = str[i++];
	buff[j++] = c;
	while (str[syb])
	{
		buff[j] = str[syb];
		j++;
		syb++;
	}
	return (buff);
}

void		add_symbole(t_lst *lst, char **str, int width, int syb[2])
{
	if (syb[0])
		*str = add_syb('-', *str);
	else if (syb[1])
		*str = add_syb('+', *str);
	else if (width < (int)ft_strlen(*str) && ft_strchr(lst->str, ' '))
		*str = add_syb(' ', *str);
}

int			conv_d(t_lst *lst, int width, int precision)
{
	char	*str;
	int		len;
	int		syb[2];

	str = alloc_buff(ft_itoa((int)lst->elt), width, precision);
	if (width > 0 && lst->str[0] == '-')
		width = -width;
	syb[0] = ft_remove_char('-', &str);
	syb[1] = ft_remove_char('+', &str);
	syb[1] = (ft_strchr(lst->str, '+') ? 1 : syb[1]);
	precision = (precision <  (int)ft_strlen(str) ? 0 : precision);
	if (width > 0)
		width = width - (syb[1] ? syb[1] : syb[0]);
	else
		width = width + (syb[1] ? syb[1] : syb[0]);
	add_char(lst, &str, width, precision);
	add_symbole(lst, &str, width, syb);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
