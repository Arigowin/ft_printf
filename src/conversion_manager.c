#include "ft_printf.h"

int			no_conv(t_lst *lst, int width, int precision)
{
	(void)width;
	(void)precision;
	ft_putstr(lst->str);
	return (ft_strlen(lst->str));
}

int			conv_d(t_lst *lst, int width, int precision)
{
	(void)lst;
	(void)width;
	(void)precision;

	return (0);
}

int			conv_c(t_lst *lst, int width, int precision)
{
	(void)lst;
	(void)width;
	(void)precision;

	return (0);
}

int			conv_p(t_lst *lst, int width, int precision)
{
	(void)lst;
	(void)width;
	(void)precision;

	return (0);
}

int			conversion_manager(t_lst *lst, int width, int precision)
{
	int		(*fct[5])(t_lst *, int, int) = {no_conv, conv_s, conv_d, conv_c,
		conv_p};
	int		len;

	len = 0;
	// tbl de pointeur sur fonction pour appeler une fonction par conversion
	len = fct[lst->type](lst, width, precision);
	return (len);
}
