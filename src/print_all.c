#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int			get_width(char **str)
{
	int		wth;
	int		sign;
	int		i;
	int		j;

	sign = 1;
	i = 0;
	if (ft_strchr(*str, '-'))
		sign = -sign;
	while (i < (int)ft_strlen(*str) && (!ft_isdigit((*str)[i])
				|| (*str)[i] == '0') && (*str)[i] != '.')
		i++;
	if (i > 0 && ((*str)[i - 1] == '-' || (*str)[i - 1] == '+' || (*str)[i - 1] == '0'))
	{
		if ((j = i - 1) < 0)
			j = 0;
		if (j > 0 && (*str)[i - 1] == '0')
			j--;
		if ((*str)[j] == '#')
			j++;
	}
	else
		j = i;
	wth = ft_atoi(*str + j);
	if (wth < 0)
		wth = -wth;
	return (wth == 0 ? wth : wth * sign);
}

int			get_precision(char **str)
{
	int		prc;
	char	*tmp;

	tmp = ft_strchr(*str, '.');
	if  (tmp == NULL)
		return (0);
	prc = ft_atoi(tmp + 1);
	return (prc);
}

void		remove_wth_and_prc(char **str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if ((new = ft_strnew(ft_strlen(*str))) == NULL)
		return;
	while (i < (int)ft_strlen(*str) && ((*str)[i] == '-' || (*str)[i] == '+' || (*str)[i] == '0'))
	{
		new[j] = (*str)[i];
		i++;
		j++;
	}
	while (i < (int)ft_strlen(*str) && (((*str)[i] <= '9' && (*str)[i] >= '0')
				|| (*str)[i] == '.'))
		i++;
	while(i < (int)ft_strlen(*str))
	{
		new[j] = (*str)[i];
		i++;
		j++;
	}
	free(*str);
	*str = new;
}

int			print_all(t_lst *lst, va_list ap)
{
	t_lst		*tmp;
	int			len;
	int			tmp_len;
	int			wth;
	int			prc;

	tmp = lst;
	len = 0;
	wth = 0;
	prc = 0;
	while (tmp)
	{
		if (tmp->type != DFLT)
		{
			wth = get_width(&(tmp->str));
			prc = get_precision(&(tmp->str));
			/* if (wth != 0 || prc != 0) */
			/*     remove_wth_and_prc(&(tmp->str)); */
		}
		// execution de la conversion avec prise en compte de wth, prc et flags
		if ((tmp_len = conversion_manager(tmp, ap, wth, prc)) < 0)
			return (tmp_len);
		len += tmp_len;
		tmp = tmp->next;
	}
	return (len);
}
