#include "ft_printf.h"

int			no_arg(t_lst *lst)
{
	ft_putstr(lst->str);
	return (ft_strlen(lst->str));
}

int			arg_s(t_lst *lst)
{
	ft_putstr(lst->elt);
	return (ft_strlen(lst->elt));
}

int			arg_d(t_lst *lst)
{
	int		d;

	d = (int)lst->elt;
	ft_putnbr(d);
	return (ft_strlen(ft_itoa(d)));
}

int			arg_c(t_lst *lst)
{
	ft_putchar((char) lst->elt);
	return (1);
}

int			arg_p(t_lst *lst)
{
	char		buff[13];

	ft_ptr_to_hex(lst->elt, &buff);
	ft_putstr("0x");
	ft_putstr(buff);
	return (ft_strlen(buff) + 2);
}

int			exec_type(t_lst *lst)
{
	static int	(*tbl_fct[5])(t_lst *lst) = {no_arg, arg_s, arg_d, arg_c, arg_p};

	return (tbl_fct[lst->type](lst));
	return (0);
}

int			exec_opt(t_lst *lst)
{
	(void) lst;
	ft_putendl("OPTION");
	return (0);
}

int			print_all(t_lst *lst)
{
	t_lst		*tmp;
	int			len;
	int			tmp_len;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		if (ft_strlen(tmp->str) == 1 || tmp->type == DFLT)
		{ // no option
			if ((tmp_len = exec_type(tmp)) == -1)
				return (-1);
			len += tmp_len;
		}
		else
		{ // option
			if ((tmp_len = exec_opt(tmp)) == -1)
				return (-1);
			len += tmp_len;
		}
		tmp = tmp->next;
	}
	return (len);
}
