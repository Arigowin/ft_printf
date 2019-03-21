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

char		*offset(char c, char *str)
{
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	if (str[len - 1] == ' ')
	{
		tmp = ft_strnew(len);
		ft_memcpy(tmp + 1, str, len - 1);
		tmp[0] = c;
		return (tmp);
	}
	tmp = ft_strdup(str);
	tmp[0] = c;
	return (tmp);
}

void		ft_add_symbole(t_lst *lst, char **str, int wth, int prc, int syb[2])
{
	char	*tmp;
	int		len;

	len = ft_strlen(*str);
	if (syb[0])
		tmp = add_syb('-', *str);
	else if (syb[1])
		tmp = add_syb('+', *str);
	else if (wth <= len && (*str)[0] != ' '
			&& ft_strchr(lst->str, ' '))
	{
		if (len > 1 && wth != 0 && ((*str)[len - 1] == ' '
					|| (prc == 0 && ((lst->str)[1] == '0'
							|| (lst->str)[0] == '0')
						&& (*str)[0] == '0')))
		{
			tmp = offset(' ', *str);
		}
		else
		{
			tmp = add_syb(' ', *str);
		}
	}
	else
		return ;
	ft_strdel(str);
	*str = tmp;
}
