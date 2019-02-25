#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int			get_width(char **str)
{
	int		width;
	int		i;
	int		j;

	i = 0;
	while (i < (int)ft_strlen(*str) && ((*str)[i] == '-' || (*str)[i] == '+' || (*str)[i] == '0'))
		i++;
	if ((j = i - 1) < 0)
		j = 0;
	width = ft_atoi(*str + j);
	return (width);
}

int			get_precision(char **str)
{
	int		precision;
	char	*tmp;

	tmp = ft_strchr(*str, '.');
	if  (tmp == NULL)
		return (0);
	precision = ft_atoi(tmp + 1);
	return (precision);
}

void		remove_width_and_precision(char **str)
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
	/* if (j != 0 && (new[j - 1] == '-' || new[j - 1] == '+')) */
	/*     j--; */
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

int			print_all(t_lst *lst)
{
	t_lst		*tmp;
	int			len;
	int			tmp_len;
	int			width;
	int			precision;

	tmp = lst;
	len = 0;
	width = 0;
	precision = 0;
	while (tmp)
	{
		if (tmp->type != DFLT)
		{
			width = get_width(&(tmp->str));
			precision = get_precision(&(tmp->str));
			if (width != 0 || precision != 0)
				remove_width_and_precision(&(tmp->str));
		}
		// execution de la conversion avec prise en compte de width, precision et flags
		if ((tmp_len = conversion_manager(tmp, width, precision)) < 0)
			return (tmp_len);
		len += tmp_len;
		tmp = tmp->next;
	}
	return (len);
}
