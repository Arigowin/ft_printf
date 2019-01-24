#include <stdlib.h>
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
	char	*str;

	d = (int)lst->elt;
	str = ft_itoa_base(d, 10);
	ft_putstr(str);
	d = ft_strlen(str);
	free(str);
	return (d);
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

int			arg_o(t_lst *lst)
{
	unsigned int		d;
	char				*str;

	d = (unsigned int)lst->elt;
	str = ft_itoa_base(d, 8);
	ft_putstr(str);
	d = ft_strlen(str);
	free(str);
	return (d);
}

// don't work
int			arg_u(t_lst *lst)
{
	unsigned int		d;

	d = (unsigned int)lst->elt;
	ft_putnbr(d);
	return (ft_strlen(ft_itoa(d)));
}

int			arg_x(t_lst *lst)
{
	int		d;
	char	*str;

	d = (int)lst->elt;
	str = ft_itoa_base(d, 16);
	ft_putstr(str);
	d = ft_strlen(str);
	free(str);
	return (d);
}

int			arg_X(t_lst *lst)
{
	int		d;
	char	*str;

	d = (int)lst->elt;
	str = ft_itoa_base(d, 16);
	ft_putupper(str);
	d = ft_strlen(str);
	free(str);
	return (d);
}

int			arg_f(t_lst *lst)
{
	int				len;
	double			flt;
	signed long int deci;
	signed long int nbr;

	flt = lst->flt;
	len = 0;
	if (flt < 0)
	{
		ft_putchar('-');
		len = 1;
		flt *= -1;
	}
	nbr = (signed long int)flt;
	ft_putnbr(nbr);
	len += ft_strlen(ft_itoa(nbr));
	ft_putchar('.');
	flt -= nbr;
	flt *= 1000000;
	deci = (signed long int)(flt + 0.5);
	// si deci contient 0 print 000000 (6)
	ft_putnbr(deci);
	len += ft_strlen(ft_itoa(deci));
	return (len + 1);
}

int			exec_type(t_lst *lst)
{
	static int	(*tbl_fct[10])(t_lst *lst) = {no_arg, arg_s, arg_d, arg_c,
		arg_p, arg_o, arg_u, arg_x, arg_X, arg_f};

	return (tbl_fct[lst->type](lst));
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
