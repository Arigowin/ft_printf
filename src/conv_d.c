#include <stdlib.h>
#include "ft_printf.h"

char		*alloc_buff(char *str, int wth, int prc)
{
	char	*buff;

	if (wth < 0)
		wth = -wth;
	if (wth + prc > (int)ft_strlen(str))
		buff = ft_strnew(wth + prc);
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

void		add_symbole(t_lst *lst, char **str, int wth, int syb[2])
{
	if (syb[0])
		*str = add_syb('-', *str);
	else if (syb[1])
		*str = add_syb('+', *str);
	else if (wth < (int)ft_strlen(*str) && ft_strchr(lst->str, ' '))
		*str = add_syb(' ', *str);
}

void		more_d(t_lst *lst, char **str, int prc, int wth)
{
	if (prc == 0 && ft_strchr(lst->str, '.')
			&& (int)lst->elt == 0 && wth != 0)
		ft_memset(*str, ' ', ft_strlen(*str));
	else if (prc == 0 && ft_strchr(lst->str, '.')
			&& (int)lst->elt == 0)
		ft_bzero(*str, ft_strlen(*str));
}

int			conv_d(t_lst *lst, int wth, int prc)
{
	char	*str;
	int		len;
	int		syb[2];

	str = alloc_buff(ft_itoa((int)lst->elt), wth, prc);
	if (wth > 0 && lst->str[0] == '-')
		wth = -wth;
	syb[0] = ft_remove_char('-', &str);
	syb[1] = ft_remove_char('+', &str);
	syb[1] = (ft_strchr(lst->str, '+') ? 1 : syb[1]);
	prc = (prc < (int)ft_strlen(str) ? 0 : prc);
	if (wth > 0)
		wth = wth - (syb[1] ? syb[1] : syb[0]);
	else
		wth = wth + (syb[1] ? syb[1] : syb[0]);
	add_char(lst, &str, wth, prc);
	add_symbole(lst, &str, wth, syb);
	more_d(lst, &str, prc, wth);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
