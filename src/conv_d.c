#include "ft_printf.h"

int			conv_d(t_lst *lst, int width, int precision)
{
	(void)width;
	(void)precision;
	int		nb;
	int		len;
	int		syb;

	syb = 0;
	nb = (int)lst->elt;
	len = ft_strlen(ft_itoa(nb));
	if (nb < 0 && lst->str[0] == '0')
	{
		nb = -nb;
		if (nb >= 0)
			ft_putchar('-');
		syb++;
	}
	if (syb == 0 && nb >= 0 && ft_strchr(lst->str, '+'))
	{
		ft_putchar('+');
		len++;
		syb++;
	}
	if (syb == 0 && nb >= 0 && ft_strchr(lst->str, ' '))
	{
		ft_putchar(' ');
		len++;
	}
	if (width > 0 && lst->str[0] != '-')
	{
		if (lst->str[0] == '0')
			ft_print_n_char('0', width - len);
		else
			ft_print_n_char(' ', width - len);
		len += width - len;
	}
	ft_putnbr(nb);
	if (width < 0 || lst->str[0] == '-')
	{
		if (lst->str[0] != '-')
			width = -width;
		if (lst->str[0] == '0')
			ft_print_n_char('0', width - len);
		else
			ft_print_n_char(' ', width - len);
		len += width - len;
	}

	return (len);
}

