#include "ft_printf.h"

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

void		ft_add_symbole(t_lst *lst, char **str, int wth, int syb[2])
{
	char	*tmp;

	if (syb[0])
		tmp = add_syb('-', *str);
	else if (syb[1])
		tmp = add_syb('+', *str);
	else if (wth <= (int)ft_strlen(*str) && (*str)[0] != ' '
			&& ft_strchr(lst->str, ' '))
		tmp = add_syb(' ', *str);
	else
		return ;
	ft_strdel(str);
	*str = tmp;
}
