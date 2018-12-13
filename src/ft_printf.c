#include <stdarg.h>
#include "ft_printf.h"

int			arg_s(va_list ap)
{
	char		*s;
	void		*a;

	a = va_arg(ap, void *);
	s = (char *)a;
	ft_putstr(s);
	return (ft_strlen(s));
}

int			arg_d(va_list ap)
{
	int			d;
	void		*a;

	a = va_arg(ap, void *);
	d = (int)a;
	ft_putnbr(d);
	return (ft_strlen(ft_itoa(d)));
}

int			arg_c(va_list ap)
{
	ft_putchar((char) va_arg(ap, int));
	return (1);
}

int			arg_p(va_list ap)
{
	char		buff[13];

	ft_ptr_to_hex(va_arg(ap, void *), &buff);
	ft_putstr("0x");
	ft_putstr(buff);
	return (ft_strlen(buff) + 2);
}

int			arg_plus(va_list ap)
{
	(void)ap;
	ft_putchar('+');
	return (1);
}


int			basic_arg(va_list ap, const char format)
{
	static char	op[4] = "sdcp";
	static int	(*tbl_fct[4])(va_list ap) = {arg_s, arg_d, arg_c, arg_p};
	int			i;
	int			len;

	len = 0;
	i = 0;
	while (i < 4)
	{
		if (op[i] == format)
		{
			len += tbl_fct[i](ap);
			break;
		}
		i++;
	}
	if (i == 4)
	{
		ft_putstr_fd("This argument doesn't exit : ", 2);
		ft_putchar_fd(format, 2);
		ft_putchar_fd('\n', 2);
		return (-1);
	}
	return (len);
}

int			simple_flag_arg(va_list ap, const char *format, int *idx)
{
	/* static char	op[8] = "#0-+%lLh"; */
	static char	op[1] = "+";
	static int	(*tbl_fct[1])(va_list ap) = {arg_plus};
	int			i;
	int			len;

	len = 0;
	i = 0;
	while (i < 1)
	{
		if (op[i] == format[*idx])
		{
			len += tbl_fct[i](ap);
			(void)(*idx)++;
			i = 0;
		}
		i++;
	}
	return (len);
}

void		print_lst(t_lst *lst)
{
	char	buff[13];

	while (lst)
	{
		/* void			*elt; */
		/* t_type			type; */
		/* char			*str; */
		ft_putstr("[");
		if (lst->type == CHAR)
			ft_putchar((char)lst->elt);
		else if (lst->type == STR)
			ft_putstr((char *)lst->elt);
		else if (lst->type == INT)
			ft_putnbr((int)lst->elt);
		else if (lst->type == PTR)
		{
			ft_ptr_to_hex(lst->elt, &buff);
			ft_putstr("0x");
			ft_putstr(buff);
		}
		else
			ft_putstr((char *)lst->elt);
		ft_putstr(", ");
		ft_putstr(lst->str);
		ft_putstr(", ");
		if (lst->type == CHAR)
			ft_putstr("CHAR");
		else if (lst->type == STR)
			ft_putstr("STR");
		else if (lst->type == PTR)
			ft_putstr("PTR");
		else if (lst->type == INT)
			ft_putstr("INT");
		else
			ft_putstr("DFLT");
		ft_putendl("]");
		lst = lst->next;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_lst		*lst;
	/* int			len; */
	/* int			check; */
	/* int			idx; */

	/* len = 0; */
	/* idx = 0; */
	lst = NULL;
	if (format == NULL || ft_strlen(format) == 0)
	{
		ft_putstr_fd("The firt arg cannot be NULL or empty\n", 2);
		return (-1);
	}
	va_start(ap, format);
	parse(&lst, ap, format);
	print_lst(lst);

	/* while (format[idx]) */
	/* { */
	/*     if (format[idx] != '%') */
	/*     { */
	/*         ft_putchar(format[idx]); */
	/*         len++; */
	/*     } */
	/*     if (format[idx++] == '%') */
	/*     { */
	/*         len += simple_flag_arg(ap, format, &idx); */
	/*         check = basic_arg(ap, format[idx]); */
	/*         if (check == -1) */
	/*             return (-1); */
	/*         len += check; */
	/*         idx++; */
	/*     } */
	/* } */
	va_end(ap);
	/* return (len); */
	return 0;
}
