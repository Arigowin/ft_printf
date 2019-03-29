#include <stdarg.h>
#include "ft_printf.h"

int			get_width(t_lst *lst)
{
	int		wth;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	while (ft_strchr("#0-+ ", (lst->str)[i]))
		i++;
	if (lst->flg.mns)
		sign = -sign;
	wth = ft_atoi((lst->str) + i);
	if (wth < 0)
		wth = -wth;
	return (wth == 0 ? wth : wth * sign);
}

int			get_precision(char *str)
{
	int		prc;
	char	*tmp;

	tmp = ft_strchr(str, '.');
	if  (tmp == NULL)
		return (0);
	prc = ft_atoi(tmp + 1);
	return (prc);
}

t_type		check_type(char c)
{
	return (c == 'c' ? CHAR :
			(c == 's' ? STR :
			 (c == 'p' ? PTR :
			  (c == 'd' || c == 'i' ? INT :
			   (c == 'o' ? OCT :
				(c == 'u' ? UINT :
				 (c == 'x' ? LHEX :
				  (c == 'X' ? UHEX :
				   (c == 'f' ? FLT :
					(c == '%' ? PCT : DFLT))))))))));
}

void		parse_1(t_lst **lst, t_type type, char *str)
{
	t_lst	*tmp;

	lst_add(lst, type, str);
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->flg.hh = ft_strstr(tmp->str, "hh") != NULL;
	tmp->flg.h = ft_strchr(tmp->str, 'h') != NULL;
	tmp->flg.ll = ft_strstr(tmp->str, "ll") != NULL;
	tmp->flg.l = ft_strchr(tmp->str, 'l') != NULL;
	tmp->flg.L = ft_strchr(tmp->str, 'L') != NULL;
	tmp->flg.sharp = ft_strchr(tmp->str, '#') != NULL;
	tmp->flg.mns = ft_strchr(tmp->str, '-') != NULL;
	tmp->flg.pls = ft_strchr(tmp->str, '+') != NULL;
	tmp->flg.spc = ft_strchr(tmp->str, ' ') != NULL;
	tmp->flg.point = ft_strchr(tmp->str, '.') != NULL;
	tmp->flg.zero = (!tmp->flg.mns && (tmp->str[0] == '0'
				|| (!ft_isdigit(tmp->str[0]) && (tmp->str[1] == '0'
						|| (!ft_isdigit(tmp->str[1]) && tmp->str[2] == '0')))));
	tmp->flg.wth = get_width(tmp);
	tmp->flg.prc = get_precision(tmp->str);
}

void		parse_2(t_lst **lst, const char *format, size_t *start, size_t *i)
{
	while (format[*i] && *i < ft_strlen(format))
	{
		(*i)++;
		if (ft_strchr("cspdiouxXf%", format[*i]) != NULL && *i < ft_strlen(format))
		{
			parse_1(lst, check_type(format[*i]), ft_strsub(format, *start + 1, (*i - *start)));
			*start = *i + 1;
			break ;
		}
	}
}

void		parse(t_lst **lst, const char *format)
{
	size_t	i;
	size_t	start;

	start = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (i != start)
			{
				parse_1(lst, DFLT, ft_strsub(format, start, i - start));
				start = i;
			}
			parse_2(lst, format, &start, &i);
		}
		i++;
	}
	if (i != start)
		parse_1(lst, DFLT, ft_strsub(format, start, i - start));
}
