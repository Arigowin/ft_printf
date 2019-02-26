#include <stdlib.h>
#include "ft_printf.h"

int			no_conv(t_lst *lst, int width, int precision)
{
	(void)width;
	(void)precision;
	ft_putstr(lst->str);
	return (ft_strlen(lst->str));
}

int			conv_c(t_lst *lst, int width, int precision)
{
	int			len;

	len = 1;
	(void)precision;
	if (width > 0)
	{
		ft_print_n_char(' ', width - 1);
		len = width;
	}
	ft_putchar((char)lst->elt);
	if (width < 0)
	{
		ft_print_n_char(' ', (-width) - 1);
		len = -width;
	}
	return (len);
}

int			conv_p(t_lst *lst, int width, int precision)
{
	(void)width;
	(void)precision;
	char		buff[15];

	if (lst->elt == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_ptr_to_hex(lst->elt, &buff);
	int			i;
	i = 0;
	while (buff[i] == '0')
		i++;
	ft_putstr("0x");
	ft_putstr(buff + i);
	return (ft_strlen(buff + i) + 2);
}

int			conversion_manager(t_lst *lst, int width, int precision)
{
	int		(*fct[10])(t_lst *, int, int) = {no_conv, conv_s, conv_d, conv_c,
		conv_p, conv_o, conv_u, conv_x, conv_x, NULL};
	int		len;

	len = 0;
	// SEGFAULT FOR NOW REMOVE THIS AFTER ADD OTHER FLAGS
	if (lst->type > 9 || lst->type == FLT)
		return (-1);
	len = fct[lst->type](lst, width, precision);
	return (len);
}
