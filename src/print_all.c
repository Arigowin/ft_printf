#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int			get_width(char **str, int *dir)
{
	int		width;

	*dir  = 0;
	if ((width = ft_atoi(*str)) < 0)
	{
		width = -width;
		*dir = 1;
	}
	int		i;

	// remove width of str
	i = 0;
	while (i < (int)ft_strlen(*str) && (*str)[i] <= '9' && (*str)[i] >= '1')
	{

	}
	return (width);
}

int			get_precision(char **str)
{
	int precision;

	precision = ft_atoi(ft_strchr(*str, '.') + 1);
	// remove '.' and precision of str
	return (precision);
}

int			print_all(t_lst *lst)
{
	t_lst		*tmp;
	int			len;
	int			tmp_len;
	int			width;
	int			precision;
	int			dir;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		width = get_width(&(lst->str), &dir);
		precision = get_precision(&(lst->str));
		// gestion des flags avec une finite state automaton
		// puis execution de la conversion avec prise en compte de width, precision et flags
		tmp = tmp->next;
	}
	return (len);
}

/* if (ft_strlen(tmp->str) == 1 || tmp->type == DFLT) */
/* { // no option */
/*     if ((tmp_len = exec_type(tmp)) == -1) */
/*         return (-1); */
/*     len += tmp_len; */
/* } */
/* else */
/* { // option */
/*     if ((tmp_len = exec_opt(tmp)) == -1) */
/*         return (-1); */
/*     len += tmp_len; */
/* } */
